#include <iostream>
#include "expression.h"
using namespace std;



int main ()
{
	int variable = 2;
	const int lowerBound = 0;
	const int upperBound = 5;

	//Equation
	typedef
	VIEWBOUNDS<
		MULTIPLY<
			ADD<
				VAR<BOUND<lowerBound,upperBound>>,
				LITERALINTEGER<3>
			>,
			ADD<
				VAR<BOUND<lowerBound,upperBound>>,
				LITERALINTEGER<5>
			>
		>
	> expr;

	printf("f(%d): %d\n",variable,expr::eval(variable));
};
