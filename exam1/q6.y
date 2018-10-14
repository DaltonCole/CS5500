N_ASSIGN        : N_VARIABLE T_ASSIGN N_EXPR
{
	/* Print rule */
	if(($1.type == INT || $1.baseType == INT) && ($3.type == BOOL || $3.type == CHAR)) {
		$3.type = INT;
	}

	/* Rest of the handling code */
}