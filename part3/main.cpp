#include <iostream>
#include "expression.h"
using namespace std;



int main ()
{

	typedef
	VIEWBOUNDS<
		ADD<
			VAR<BOUND<4,12>>,
			MULTIPLY<
				MINUS<
					VAR<BOUND<1,8>>,
					LITERALINTEGER<2>
				>,
				MINUS<
					VAR<BOUND<22,36>>,
					LITERALINTEGER<4>
				>
			>
		>
	> expr;




	int input[3];
	int output[3];

	//First
	input[0] = 8;
	input[1] = 2;
	input[2] = 28;
	output[0] = expr::eval(input);


	//Second
	input[0] = 11;
	input[1] = 2;
	input[2] = 30;
	output[1] = expr::eval(input);

	//Third
	input[0] = 5;
	input[1] = 7;
	input[2] = 23;
	output[2] = expr::eval(input);

	for(int i = 0;i < 3; i++){
		printf("f(): %d\n",output[i]);
	}

}