#include <iostream>
#include "expression.h"
using namespace std;



int main ()
{
	int variable = 5;

	//Equation
	// ADD<
	//   	VAR,
	//   	MULTIPLY<
	// 	  	MINUS<
	// 	  		VAR,
	// 	  		LITERALINTEGER<2>
	// 	  	>,
	// 	  	MINUS<
	// 	  		VAR,
	// 	  		LITERALINTEGER<3>
	// 	  	>
	// 	>
	// > expr;
	DIVIDE<VAR,LITERALINTEGER<0>> expr;


	cout << expr.eval(variable);

};
