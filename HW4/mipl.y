/*
      hw4_parser.y

 	Bison specification file for the HW #4 language.
 	CS 5500, Fall 2018.

      To create the executable:

        flex hw4_parser.l
        bison hw4_parser.y
        g++ hw4_parser.tab.c -o hw4

      To execute:

        hw4 <inputFileName>

*/

/*
 *	Declaration section.
 */
%{
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include "quad.h"
using namespace std;


int lineNum = 1; 

bool DEBUG  = false;   // if true, outputs tokens, productions,
                      // symbol table entries, etc.


typedef vector<int> SUBSCRIPT_INFO;

map<char, SUBSCRIPT_INFO> symbolTable;
SUBSCRIPT_INFO currentSubscriptInfo;  

void addEntryToSymbolTable(const char id, 
                           const SUBSCRIPT_INFO subscriptInfo);
SUBSCRIPT_INFO findEntryInSymbolTable(const char id);
void outputSubscriptInfo(const SUBSCRIPT_INFO v);
void printTypeInfo(const char ch, const SUBSCRIPT_INFO s);

void prRule(const char*, const char*);
void printTokenInfo(const char* tokenType, const char* lexeme);

/////////////////////////////////////////////////////////
// Vector containing instructions
vector<Quad> instructions;
// Current instruction being changed
Quad current_inst;
// Depth for recursive array
int depth;
// Keeps track of array size for L -> L[e]
SUBSCRIPT_INFO array_size;
// GOTO stack for "Lx:""
stack<Quad> goto_stack;
// GOTO stack for "goto Lx"
stack<Quad> goto_label_stack;

// Requires previous temp
bool temp1 = false;
// Requires previous two temps
bool temp2 = false;
/////////////////////////////////////////////////////////

int yyerror(const char* s) 
{
  printf("Line %d: %s\n", lineNum, s);
  return(1);
}

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

%}

%union {
  char ch;
  int num;
  char* text;
};

/*
 *	Token declarations
*/
%token  T_LPAREN T_RPAREN T_LBRACK T_RBRACK
%token  T_SEMICOL T_PLUS T_ASSIGN
%token  T_GT T_LT T_NE T_GE T_LE T_EQ
%token  T_VAR T_LCURLY T_RCURLY
%token  T_IF T_THEN T_ELSE T_WHILE T_DO T_TRUE T_FALSE 
%token  T_INTCONST T_IDENT T_UNKNOWN

%type <num> T_INTCONST
%type <ch> T_IDENT 
%type <text> E L B R

/*
 *	Starting point.
 */
%start		P

/*
 *	Translation rules.
 */
%%
P	: T_VAR V T_LCURLY C T_RCURLY
	{
	prRule("P", "var V { C }");
	if (DEBUG) printf("\n---- Completed parsing ----\n\n");
	}
	;
V   : /* epsilon */
	{
	prRule("V", "epsilon");
	}
	| T_IDENT N T_SEMICOL
	{
	addEntryToSymbolTable($1, currentSubscriptInfo);
	currentSubscriptInfo.clear( );
	}
	V
	{
	prRule("V", "id N ; V");
	}
	;
N	: T_LBRACK T_INTCONST T_RBRACK N
	{
	prRule("N", "[ INTCONST ] N");
	currentSubscriptInfo.insert(currentSubscriptInfo.begin(),
                                 $2);
	}
	| /* epsilon */
	{
	prRule("N", "epsilon");
	}
	;
C	: S T_SEMICOL
	{
		
	} C
	{
		prRule("C", "S ; C");
		
	}
	| /* epsilon */
	{
	prRule("C", "epsilon");
	}
	;
S	: A
	{
	prRule("S", "A ;");
		// Add current_inst to instruciton vector
		instructions.push_back(current_inst);
		// Clear current instruction
		current_inst.clear();
	}
	| F
	{
	prRule("S", "F");
	}
	| W
	{
	prRule("S", "W");
	}
	;  
A	: T_IDENT T_ASSIGN E // id = EXPR
	{
		prRule("A", "id = E");
		// Index
		SUBSCRIPT_INFO s = findEntryInSymbolTable($1);
		if (DEBUG) 
		{
		  printf("\n*** Found %c in symbol table\n", $1);
	   	  if (s.size() > 0) 
		  {
	 	  printf("*** This array has the following ");
		  printf("subscriptInfo:\n");
		  outputSubscriptInfo(s);
	  	  }
	 	  printf("\n");
		}

		// Update result in current_inst
		current_inst.result = $1;
		current_inst.add_arg($3);
	}
	| L T_ASSIGN E // id[x] = EXPR
	{
		prRule("A", "L = E");

		// Update result in current_inst
		current_inst.result = $1;
		current_inst.op = "[]";
		current_inst.add_arg($3); // arg2
	}
	;
F	: T_IF T_LPAREN B T_RPAREN T_THEN S T_ELSE S
	{
	prRule("F", "if ( B ) then S else S");
	}
	; 
W	: T_WHILE 
	{
		// Add inital label instruction
		Quad q;
		q.add_label_result();
		instructions.push_back(q);

		q.op = "goto";
		goto_label_stack.push(q);
	} T_LPAREN B T_RPAREN 
	{
		string still_clears = $4; // $4 clears after Quad q...
		// GOTO
		Quad q;
		q.add_arg(still_clears);
		q.add_label_result(); // will update op with ':'
		q.op = "if_goto";
		instructions.push_back(q);

		// Add label to stack
		q.op = ":";
		q.remove_arg();
		goto_stack.push(q);

	} S
	{
		prRule("S", "while ( B ) S");
		// Add goto label
		Quad q = goto_label_stack.top();
		goto_label_stack.pop();
		instructions.push_back(q);

		// After GOTO, quad should already be populated
		q = goto_stack.top();
		goto_stack.pop();
		instructions.push_back(q);
	}
	;
E	: E T_PLUS T_INTCONST // E + num
	{
		prRule("E", "E + INTCONST");
		Quad q;
		q.op = "+";
		//printf("$1: %s\n", $1);
		q.add_arg($1);
		q.add_arg($3);
		q.add_temp_result();
		instructions.push_back(q);

		$$ = q.get_temp_result();
	}
	| T_IDENT // id
	{
		prRule("E", "id");
		//current_inst.add_arg($1);
		
		string hacker(1, $1);
		$$ = new char(hacker.length() + 1);
		strcpy($$, hacker.c_str());
	}
	| L
	{
	prRule("E", "L");
		Quad q;
		q.op = "rhs[]";
		q.add_arg($1);
		q.add_arg(instructions.back().result);
		q.add_temp_result();
		instructions.push_back(q);
		$$ = q.get_temp_result();

		// Remove first arg in current inst set by L ->
		current_inst.remove_arg();
	}
	| T_INTCONST // number
	{
		prRule("E", "INTCONST");
		//current_inst.add_arg($1);
		string s = to_string($1);
		$$ = (char*)s.c_str();
		//printf("HI: \n");
	}
	;
L	: T_IDENT T_LBRACK E T_RBRACK
  	{
		prRule("L", "id [ E ]"); // Final
		SUBSCRIPT_INFO s = findEntryInSymbolTable($1);
		array_size = s; // Keep track of array size for recursive L
		string temp = string($3); // Quad q clears $3 ???
		int row_col_count = 4;
		depth = 1; // Set recursive index depth

		for(int i = depth; i < array_size.size(); i++) {
			row_col_count *= array_size[i];
		}

		Quad q;
		q.op = "*";
		q.add_arg(temp);
		q.add_arg(row_col_count); 
		q.add_temp_result();
		instructions.push_back(q);

		string hacker(1, $1);
		$$ = new char(hacker.length() + 1);
		strcpy($$, hacker.c_str());

		current_inst.add_arg(q.get_temp_result()); // arg1

		if (DEBUG) 
		{
	  	  printf("\n*** Found %c in symbol table\n", $1);
	   	  if (s.size() > 0) 
		  {
		  printf("*** This array has the following ");
		  printf("subscriptInfo:\n");
		  outputSubscriptInfo(s);
	 	  }
		  printf("\n");
	  	}
	}
	| L T_LBRACK E T_RBRACK // Recursive
	{
		prRule("L", "L [ E ]");
		string temp = string($3); // Quad q clears $3 ???
		depth++;
		int row_col_count = 4;

		for(int i = depth; i < array_size.size(); i++) {
			row_col_count *= array_size[i];
		}

		Quad q;
		q.op = "*";
		q.add_arg(temp);
		q.add_arg(row_col_count); 
		q.add_temp_result();
		instructions.push_back(q);

		// Add last two temp values to instructions
		Quad p_q;
		p_q.op = "+";
		// Add temp value from two instructions ago
		p_q.add_arg(instructions[instructions.size() - 2].get_temp_result());
		// Add temp value from last instruction
		p_q.add_arg(instructions.back().get_temp_result());
		p_q.add_temp_result();
		instructions.push_back(p_q);

		$$ = $1;
		current_inst.remove_arg();
		current_inst.add_arg(p_q.get_temp_result()); // arg1
	}
	;
B	: E R E
    {
		prRule("B", "E R E");

		// Again, char*'s are weird and stop existing after Quad q...
		string a1 = string($1);
		string a2 = string($3);

		Quad q;
		q.op = $2;
		q.add_arg(a1);
		q.add_arg(a2); 
		q.add_temp_result();
		instructions.push_back(q);

		$$ = q.get_temp_result();
	}
	| T_TRUE
   	{
		prRule("B", "true");
		$$ = (char*)"true";
	}
	| T_FALSE
   	{
		prRule("B", "false");
		$$ = (char*)"false";
	}
	;                              
R	: T_GT
	{
		prRule("R", ">");
		$$ = (char*)">";
	}
     	| T_LT
	{
		prRule("R", "<");
		$$ = (char*)"<";
	}
     	| T_NE
	{
		prRule("R", "!=");
		$$ = (char*)"!=";
	}
	| T_GE
	{
		prRule("R", ">=");
		$$ = (char*)">=";
	}
    	| T_LE
	{
		prRule("R", "<=");
		$$ = (char*)"<=";
	}
     	| T_EQ
	{
		prRule("R", "==");
		$$ = (char*)"==";
	}
	;
%%

#include "lex.yy.c"
extern FILE *yyin;

void prRule(const char* lhs, const char* rhs) 
{
  if (DEBUG) printf("%s -> %s\n", lhs, rhs);
  return;
}

void printTokenInfo(const char* tokenType, const char* lexeme) 
{
  if (DEBUG)
    printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
  return;
}

// Add symbol table entry x to the symbol table.
void addEntryToSymbolTable(const char id, 
                           const SUBSCRIPT_INFO subscriptInfo) 
{
  // Make sure there isn't already an entry with the same name
  map<char, SUBSCRIPT_INFO>::iterator itr;
  if ((itr = symbolTable.find(id)) == symbolTable.end()) 
    symbolTable.insert(make_pair(id, subscriptInfo));
  else yyerror("Multiply defined identifier!");

  if (DEBUG) 
  {
    printf("\n>>> Added %c to symbol table\n", id);
    if (subscriptInfo.size() > 0) {
      printf(">>> with the following subscriptInfo:\n");
      outputSubscriptInfo(subscriptInfo);
    }
  }
  return;
}

// Return the subscript info for symbol table entry id.
SUBSCRIPT_INFO findEntryInSymbolTable(const char id) 
{
  map<char, SUBSCRIPT_INFO>::iterator itr;
  if ((itr = symbolTable.find(id)) == symbolTable.end())
    yyerror("Undefined identifier!");
  else return(itr->second);
}

// Output the contents of a vector of int's.
void outputSubscriptInfo(const SUBSCRIPT_INFO s) 
{  
  for (int i = 0; i < s.size(); i++)
    printf("     s[%d] = %d\n", i, s[i]);
  return;
}

// Output the identifier name (ch) and its subscript info.
void printTypeInfo(const char ch, const SUBSCRIPT_INFO s) 
{
  printf("\n*** Found %c in symbol table\n", ch);
  if (s.size() > 0) {
    printf("*** This array has the following subscriptInfo:\n");
    outputSubscriptInfo(s);
  }
  printf("\n");
  return;
}

int main( ) 
{
  // Parse until end-of-file
  do {
	yyparse();
  } while (!feof(yyin));

  // Output list of 3-address instructions
  for(int i = 0; i < instructions.size(); i++) {
  	instructions[i].print();
  }

  return 0;
}
