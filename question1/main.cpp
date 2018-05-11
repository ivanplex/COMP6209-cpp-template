#include <iostream>
#include "expression.h"
using namespace std;



int main ()
{
	int variable = 5;

	//Equation
	typedef
	ADD<
	  	VAR,
	  	MULTIPLY<
		  	MINUS<
		  		VAR,
		  		LITERALINTEGER<2>
		  	>,
		  	MINUS<
		  		VAR,
		  		LITERALINTEGER<3>
		  	>
		>
	> expr;

	printf("f(%d): %d\n",variable,expr::eval(variable));
};
