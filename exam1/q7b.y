/*
 *  Declaration section.
 */
%{
// Empty vector, for convenience
#define NEW_VECTOR vector<TYPE_INFO>()
// Keep track if pass by reference or not
bool pass_by_reference;
// Vector of proc argument variable names
vector<string> variable_names;
// Procedure to add arguments to
TYPE_INFO proc_info;
%}

N_PROC_HDR	: T_PROCEDURE T_IDENT 
	{
		// Initialize procedure
		proc_info = {PROCEDURE, NOT_APPLICABLE, NOT_APPLICABLE, NOT_APPLICABLE, NEW_VECTOR, false};
	}
	N_FORMAL_PARAM_DEC_PART T_SCOLON 
	{
		// Name procedure
		string lexeme = string($2);

		// Add procedure to symbol table
		bool success = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lexeme, proc_info));
		// Error out if not successful
		if(!success) {
			yyerror("Multiply defined identifier");
			return(0);
		}
	};

N_FORMAL_PARAM_DEC_PART	: /* Epsilon */
	{
		// Nothing to do here, proc already added to symbol table
	}
	| T_LPAREN N_FORMAL_PARAM_DEC_LST T_RPAREN
	{
		// Nothing to do here, handled in N_FORMAL_PARAM_DEC_LST
	};

N_FORMAL_PARAM_DEC_LST	: N_FORMAL_PARAM_DEC N_MORE_FORMAL_PARAM_DECS
	{
		// Nothing to do here
	};

N_MORE_FORMAL_PARAM_DEC : T_SCOLON N_FORMAL_PARAM_DEC_LST
		{
			// Nothing to do here
		}
		| /* Epsilon */
		{
			// Nothing to do here
		};

N_FORMAL_PARAM_DEC 	: 
	{
		// No var => pass-by-value
		pass_by_reference = false;
	}
	N_FORMAL_PARAM_GROUP
		
	| 
	T_VAR 
	{
		// Var => pass-by-reference
		pass_by_reference = true;
	}
	N_FORMAL_PARAM_GROUP;

N_FORMAL_PARAM_GROUP	: T_IDENT N_FORMAL_PARAM_IDENT_LST T_SCOLON N_TYPE
	{
		// Identifier name
		string varName = string($1);
		// Add ident to variable name vector
		variable_names.push_back(varName);
		// For each variable name in variable name list
		for(auto it : variable_names) {
			// Create pointer to a new symbol table entry
			SYMBOL_TABLE_ENTRY* info = new SYMBOL_TABLE_ENTRY(it, $4, pass_by_reference);
			// If name has been added to symbol table entry vector => error
			if(mult_def(info)) {
				yyerror("Multiply defined identifier");
				return(0);
			}
			// Add entry to entry vector
			proc_info.procedure_list.push_back(info);
		}
	};

N_FORMAL_PARAM_IDENT_LST 	: /* Epsilon */
	| T_COMMA T_IDENT N_FORMAL_PARAM_IDENT_LST
	{
		// Get variable name and add it to variable name vector
		string varName = string($2);
		variable_names.push_back(varName);
	};

// Check if name is already in symbol table entry vector for proc
bool mult_def(SYMBOL_TABLE_ENTRY* info) {
	for(auto it : proc_info.procedure_list) {
		if(info -> name == it -> name) {
			return true;
		}
	}
	return false;
}