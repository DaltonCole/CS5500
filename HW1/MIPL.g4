grammar MIPL;

@members {
def tokInfo(self, *args):
	non_token_indexes = []
	for i in range(len(args)):
		if not str(args[i]).startswith("T_") and not str(args[i]).startswith("N_"):
			continue
		else:
			if len(non_token_indexes) > 0:
				if non_token_indexes[-1] == i - 1 and str(args[non_token_indexes[-1]]).startswith("T_"):
					continue
		non_token_indexes.append(i)

	for i in non_token_indexes:
		if args[i].startswith("T_"):
			print("TOKEN: " + str(args[i]) + "\t" + "LEXEME: " + str(args[i+1]))

	print(str(args[0]) + " -> ", end='')
	for i in non_token_indexes:
		if i != 0:
			print(str(args[i]) + " ", end='')
	print()
}


/*
 * Parser Rules
 */

n_start 		: n_prog ;

n_addop 		: T_PLUS {self.tokInfo("N_ADDOP", "T_PLUS", $T_PLUS.text)}
				| T_MINUS {self.tokInfo("N_ADDOP", "T_MINUS", $T_MINUS.text)}
				| T_OR {self.tokInfo("N_ADDOP", "T_OR", $T_OR.text)};

n_addoplst 		: /* epsilon */ {\
					self.tokInfo("N_ADDOPLST", "", "N_epsilon")}
				| n_addop n_term n_addoplst {\
					self.tokInfo("N_ADDOPLST", "N_ADDOP", "N_TERM", "N_ADDOPLST")};

n_array 		: T_ARRAY T_LBRACK n_idxrange T_RBRACK T_OF n_simple {\
					self.tokInfo("N_ARRAY", "T_ARRAY", $T_ARRAY.text, "T_LBRACK", $T_LBRACK.text, "N_IDXRANGE", "T_RBRACK", $T_RBRACK.text, "T_OF", $T_OF.text, "N_SIMPLE")} ; 

n_arrayvar 		: n_entirevar {self.tokInfo("N_ARRAYVAR", "N_ENTIREVAR")} ;

n_assign 		: n_variable T_ASSIGN n_expr {\
					self.tokInfo("N_ASSIGN", "N_VARIABLE", $T_ASSIGN.text, "N_EXPR")} ;

n_block 		: n_vardecpart n_procdecpart n_stmtpart {\
					self.tokInfo("N_BLOCK", "N_VARDECPART", "N_PROCDECPART", "N_STMTPART")} ;

n_boolconst 	: T_TRUE {self.tokInfo("N_BOOLCONST", "T_TRUE", $T_TRUE.text)}
				| T_FALSE {self.tokInfo("N_BOOLCONST", "T_FALSE", $T_FALSE.text)};

n_compound 		: T_BEGIN n_stmt n_stmtlst T_END {\
					self.tokInfo("N_COMPOUND", "T_BEGIN", $T_BEGIN.text, "N_STMT", "N_STMTLST", "T_END", $T_END.text)} ;

n_condition 	: T_IF n_expr T_THEN n_stmt {\
					self.tokInfo("N_CONDITION", "T_IF", $T_IF.text, "N_EXPR", "T_THEN", $T_THEN, "N_STMT")}
				| T_IF n_expr T_THEN n_stmt T_ELSE n_stmt {\
					self.tokInfo("N_CONDITION", "T_IF", $T_IF.text, "N_EXPR", "T_THEN", $T_THEN.text, "N_STMT")} ;

n_const 		: n_intconst {self.tokInfo("N_CONST", "N_INTCONST")}
				| T_CHARCONST {self.tokInfo("N_CONST", "T_CHARCONST", $T_CHARCONST.text)}
				| n_boolconst {self.tokInfo("N_CONST", "N_BOOLCONST")} ;

n_entirevar 	: n_varident {self.tokInfo("N_ENTIREVAR", "N_VARIDENT")} ;

n_expr 			: n_simpleexpr {self.tokInfo("N_EXPR", "N_SIMPLEEXPR")}
				| n_simpleexpr n_relop n_simpleexpr {\
					self.tokInfo("N_EXPR", "N_SIMPLEEXPR", "N_RELOP", "N_SIMPLEEXPR")} ;

n_factor 		: n_sign n_variable {self.tokInfo("N_FACTOR", "N_SIGN", "N_VARIABLE")}
				| n_const  {self.tokInfo("N_FACTOR", "N_CONST")}
				| T_LPAREN n_expr T_RPAREN {self.tokInfo("N_FACTOR", "T_LPAREN", $T_LPAREN.text, "N_EXPR", "T_RPAREN", $T_RPAREN.text)}
				| T_NOT n_factor {self.tokInfo("N_FACTOR", "T_NOT", $T_NOT.text, "N_FACTOR")} ;

n_ident         : T_IDENT {self.tokInfo("N_IDENT", "T_IDENT", $T_IDENT.text)} ;

n_identlst      : /* epsilon */ {self.tokInfo("N_IDENTLST", "N_epsilon")}
                | T_COMMA n_ident n_identlst {self.tokInfo("N_IDENTLST", "T_COMMA", $T_COMMA.text, "N_IDENT", "N_IDENTLST")} ;

n_idx           : n_intconst {self.tokInfo("N_IDX", "N_INTCONST")} ;

n_idxrange      : n_idx T_DOTDOT n_idx {self.tokInfo("N_IDXRANGE", "N_IDX", "T_DOTDOT", $T_DOTDOT.text, "N_IDX") };

n_idxvar        : n_arrayvar T_LBRACK n_expr T_RBRACK {self.tokInfo("N_IDXVAR", "N_ARRAYVAR", "T_LBRACK", $T_LBRACK.text, "N_EXPR", "T_RBRACK", $T_RBRACK.text)} ;

n_inputlst      : /* epsilon */ {self.tokInfo("N_INPUTLST", "N_epsilon")}
                | T_COMMA n_inputvar n_inputlst {self.tokInfo("N_INPUTLST", "T_COMMA", $T_COMMA.text, "N_INPUTVAR", "N_INPUTLST")} ;

n_inputvar      : n_variable {self.tokInfo("N_INPUTVAR", "N_VARIABLE")} ;

n_intconst      : n_sign T_INTCONST {self.tokInfo("N_INTCONST", "N_SIGN", "T_INTCONST", $T_INTCONST.text)} ; /*
				| n_sign INVALINT {self.tokInfo("N_INTCONST", "N_SIGN", "T_INVALINT", $INVALINT.text)} 
				; */

n_multop        : T_MULT {self.tokInfo("N_MULTOP", "T_MULT", $T_MULT.text)}
                | T_DIV {self.tokInfo("N_MULTOP", "T_DIV", $T_DIV.text)}
                | T_AND {self.tokInfo("N_MULTOP", "T_AND", $T_AND.text)} ;

n_multoplst     : /* epsilon */ {self.tokInfo("N_MULTOPLST", "N_epsilon")}
                | n_multop n_factor n_multoplst {self.tokInfo("N_MULTOPLST", "N_MULTOP", "N_FACTOR", "N_MULTOPLST")} ;

n_output        : n_expr {self.tokInfo("N_OUTPUT", "N_EXPR")} ;

n_outputlst     : /* epsilon */ {self.tokInfo("N_OUTPUTLST", "N_epsilon")}
                | T_COMMA n_output n_outputlst {self.tokInfo("N_OUTPUTLST", "T_COMMA", $T_COMMA.text, "N_OUTPUT", "N_OUTPUTLST")} ;

n_procdec       : n_prochdr n_block {self.tokInfo("N_PROCDEC", "N_PROCDEC", "N_BLOCK")} ;

n_prochdr       : T_PROC T_IDENT T_SCOLON {self.tokInfo("N_PROCHDR", "T_PROC", $T_PROC.text, "T_IDENT", $T_IDENT.text, "T_SCOLON", $T_SCOLON.text)} ;

n_procdecpart   : /* epsilon */ {self.tokInfo("N_PROCDECPART", "N_epsilon")}
                | n_procdec T_SCOLON n_procdecpart {self.tokInfo("N_PROCDECPART", "N_PROCDEC", "T_SCOLON", $T_SCOLON.text, "N_PROCDECPART")} ;

n_procident     : T_IDENT {self.tokInfo("N_PROCIDENT", "T_IDENT", $T_IDENT.text)} ;

n_procstmt      : n_procident {self.tokInfo("N_PROCSTMT", "N_PROCIDENT")} ;

n_prog          : n_proglbl T_IDENT T_SCOLON n_block T_DOT {self.tokInfo("N_PROG", "N_PROGLBL", "T_IDENT", $T_IDENT.text, "T_SCOLON", $T_SCOLON.text, "N_BLOCK", "T_DOT", $T_DOT.text)} ;

n_proglbl       : T_PROG {self.tokInfo("N_PROGLBL", "T_PROG", "T_PROG", $T_PROG.text)};

n_read          : T_READ T_LPAREN n_inputvar n_inputlst T_RPAREN {\
					self.tokInfo("N_READ", "T_READ", $T_READ.text, "T_LPAREN", $T_LPAREN.text, "N_INPUTVAR", "N_INPUTLST", "T_RPAREN", $T_RPAREN.text)} ;

n_relop         : T_LT {self.tokInfo("N_RELOP", "T_LT", $T_LT.text)}
                | T_GT {self.tokInfo("N_RELOP", "T_GT", $T_GT.text)}
                | T_LE {self.tokInfo("N_RELOP", "T_LE", $T_LE.text)}
                | T_GE {self.tokInfo("N_RELOP", "T_GE", $T_GE.text)}
                | T_EQ {self.tokInfo("N_RELOP", "T_EQ", $T_EQ.text)}
                | T_NE {self.tokInfo("N_RELOP", "T_NE", $T_NE.text)} ;

n_sign          : /* epsilon */ {self.tokInfo("N_SIGN", "N_epsilon")}
                | T_PLUS {self.tokInfo("N_SIGN", "T_PLUS", $T_PLUS.text)}
                | T_MINUS {self.tokInfo("N_SIGN", "T_MINUS", $T_MINUS.text)} ;

n_simple        : T_INT {self.tokInfo("N_SIMPLE", "T_INT", $T_INT.text)}
                | T_CHAR {self.tokInfo("N_SIMPLE", "T_CHAR", $T_CHAR.text)}
                | T_BOOL {self.tokInfo("N_SIMPLE", "T_BOOL", $T_BOOL.text)} ;

n_simpleexpr    : n_term n_addoplst {self.tokInfo("N_SIMPLEEXPR", "N_TERM", "N_ADDOPLST")} ;

n_stmt          : n_assign {self.tokInfo("N_STMT", "N_ASSIGN")}
                | n_procstmt {self.tokInfo("N_STMT", "N_PROCSTMT")}
                | n_read {self.tokInfo("N_STMT", "N_READ")}
                | n_write {self.tokInfo("N_STMT", "N_WRITE")}
                | n_condition {self.tokInfo("N_STMT", "N_CONDITION")}
                | n_while {self.tokInfo("N_STMT", "N_WHILE")}
                | n_compound {self.tokInfo("N_STMT", "N_COMPOUND")} ;

n_stmtlst       : /* epsilon */ {self.tokInfo("N_STMTLST", "N_epsilon")}
                | T_SCOLON n_stmt n_stmtlst {self.tokInfo("N_STMTLST", "T_SCOLON", $T_SCOLON.text, "N_STMT", "N_STMTLST")};

n_stmtpart      : n_compound {self.tokInfo("N_STMTPART", "N_COMPOUND")} ;

n_term          : n_factor n_multoplst {self.tokInfo("N_TERM", "N_FACTOR", "N_MULTOPLST")} ;

n_type          : n_simple {self.tokInfo("N_TYPE", "N_SIMPLE")}
                | n_array {self.tokInfo("N_TYPE", "N_ARRAY")} ;

n_vardec        : n_ident n_identlst T_COLON n_type {self.tokInfo("N_VARDEC", "N_IDENT", "N_IDENTLST", "T_COLON", $T_COLON.text, "N_TYPE")} ;

n_vardeclst     : /* epsilon */ {self.tokInfo("N_VARDECLST", "N_epsilon")}
                | n_vardec T_SCOLON n_vardeclst {self.tokInfo("N_VARDECLST", "N_VARDEC", "T_SCOLON", $T_SCOLON.text, "N_VARDECLST")} ;

n_vardecpart    : /* epsilon */ {self.tokInfo("N_VARDECPART", "N_epsilon")}
                | T_VAR n_vardec T_SCOLON n_vardeclst {self.tokInfo("N_VARDECPART", "T_VAR", $T_VAR.text, "N_VARDEC", "T_SCOLON", $T_SCOLON.text, "N_VARDECLST")} ;

n_variable      : n_entirevar {self.tokInfo("N_VARIABLE", "N_ENTIREVAR")}
                | n_idxvar {self.tokInfo("N_VARIABLE", "N_IDXVAR")} ;

n_varident      : T_IDENT {self.tokInfo("N_VARIDENT", "T_IDENT", $T_IDENT.text)} ;

n_while         : T_WHILE n_expr T_DO n_stmt {self.tokInfo("N_WHILE", "T_WHILE", $T_WHILE.text, "N_EXPR", "T_DO", $T_DO.text, "N_STMT")} ;

n_write         : T_WRITE T_LPAREN n_output n_outputlst T_RPAREN {\
					self.tokInfo("N_WRITE", "T_WRITE", $T_WRITE.text, "T_LPAREN", $T_LPAREN.text, "N_OUTPUT", "N_OUTPUTLST", "T_RPAREN", $T_RPAREN.text)} ;



/*
 *	Lexer Rules
 */

T_COMMENT 		: '(*' .*? '*)' -> skip ;
T_WRITE 		: 'write' ;
T_PLUS 			: '+' ;
T_MINUS 		: '-' ;
T_OR 			: 'or' ;
T_ARRAY 		: 'array' ;
T_LBRACK 		: '[' ;
T_RBRACK 		: ']' ;
T_OF 			: 'of' ;
T_ASSIGN 		: ':=' ;
T_TRUE 			: 'true' ;
T_LPAREN 		: '(' ;
T_RPAREN		: ')' ;
T_MULT			: '*' ;
T_COMMA			: ',' ;
T_DOTDOT		: '..' ;
T_DOT			: '.' ;
T_COLON			: ':' ;
T_SCOLON 		: ';' ;
T_LT 			: '<' ;
T_LE 			: '<=' ;
T_NE 			: '<>' ;
T_EQ 			: '=' ;
T_GT 			: '>' ;
T_GE 			: '>=' ;
T_AND 			: 'and' ;
T_BEGIN 		: 'begin' ;
T_BOOL 			: 'boolean' ;
T_CHAR 			: 'char' ;
T_DIV 			: 'div' ;
T_DO 			: 'do' ;
T_ELSE 			: 'else' ;
T_END 			: 'end' ;
T_FALSE 		: 'false' ;
T_IF 			: 'if' ;
T_INT 			: 'integer' ;
T_NOT 			: 'not' ;
T_PROC 			: 'procedure' ;
T_PROG 			: 'program' ;
T_READ 			: 'read' ;
T_THEN 			: 'then' ;
T_VAR 			: 'var' ;
T_WHILE 		: 'while' ;

T_INTCONST 		: VALIDINT ;
/* MAYBEINT 		: T_UNKNOWN | T_INTCONST ; */
/* INVALINT 		: T_UNKNOWN ; */
/* IDENT 			: T_IDENT ; */
/* BADCHARCONST 	: T_UNKNOWN ; */
/* CHARCONST 		: T_CHARCONST ; */
T_IDENT 			: IDENT ;
T_CHARCONST 		: CHARCONST ;

QUOTE			: '\'' ;
UNDERSCORE		: '_' ;

WSPACE			: (' ' | '\t')+ -> skip;
NEWLINE         : '\n' -> skip;

SIGN			: [+-] ;
COUNT_DIGIT		: [1-9] ; 
DIGIT			: [0-9] ;

LO_ALPHA		: [a-z] ;
HI_ALPHA		: [A-Z] ;
ALPHA			: LO_ALPHA | HI_ALPHA ;

ALPHANUM		: ALPHA | DIGIT ;

VALIDINT		: ([0]* COUNT_DIGIT DIGIT? DIGIT? DIGIT? DIGIT? DIGIT? DIGIT? DIGIT?)
				| [0]* [0-2] [0-1] [0-7] [0-4] [0-8] [0-3] [0-6] [0-4] [0-7]
				| [0]+ ;

INVALINT		: ([0]* COUNT_DIGIT DIGIT*);

IDENT			: (UNDERSCORE | ALPHA)(ALPHANUM | UNDERSCORE)* ;

CHARCONST		: QUOTE . QUOTE ;
BADCHARCONST	: QUOTE | QUOTE QUOTE ;