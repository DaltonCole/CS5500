grammar exam;

/* Parser Rules */

n_start		: n_var ;

n_var		: T_VAR n_declair
			| n_declair ;

n_declair	: T_IDENT T_COLON n_type ;

n_type 		: n_basetype
			| n_collectiontype T_OF n_basetype ;

n_collectiontype	: T_STACK
					| T_QUEUE
					| T_LIST
					| T_TREE 
					| T_ARRAY ;

n_basetype 			: T_INT
					| T_CHAR
					| T_BOOLEAN
					| T_REAL ;


/* Lexer Rules */

WSPACE			: (' ' | '\t')+ -> skip;

T_VAR 		: 'var' ;
T_IDENT 	: [A-Z]+ ;
T_OF 		: 'of' ;
T_COLON 	: ':' ;

T_INT 		: 'integer' ;
T_CHAR 		: 'char' ;
T_BOOLEAN 	: 'boolean' ;
T_REAL 		: 'real' ;

T_ARRAY 	: 'array' ; /* NOTE, assumed valid from test cases */
T_STACK 	: 'stack' ;
T_QUEUE 	: 'queue' ;
T_LIST 		: 'list' ;
T_TREE 		: 'tree' ;