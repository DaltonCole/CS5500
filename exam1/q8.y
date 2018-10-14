/*
 *  Declaration section.
 */
%{
// Number of arguments to procedure
int argument_count;
%}

N_PROC_STMT				: N_PROCIDENT 
	{
		argument_count = 0;
	}
	N_ACTUAL_PARAM_LST
	{
		// If precedure list size is greater than number of arguments given
		if($1.procedure_list.size() > argument_count) {
			yyerror("Too few parameters");
			return(0);
		} 
		// If precedure list size is less than number of arguments given
		else if($1.procedure_list.size() > argument_count) {
			yyerror("Too many parameters");
			return(0);
		}
	};

N_ACTUAL_PARAM_LST 		: /* Epsion */
	| T_LPAREN N_ACTUAL_PARAM_EXPR_LST T_RPARE ;


N_ACTUAL_PARAM_EXPR_LST	: N_EXPR T_COMMA N_ACTUAL_PARAM_EXPR_LST
	{
		// Increment argument count
		argument_count++;
	}
	| N_EXPR
	{
		// Increment argument count
		argument_count++;
	};
