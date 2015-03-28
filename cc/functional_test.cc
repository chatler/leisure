// functional_test.cc

#include <iostream>
#include <functional>

using namespace std;


//unary_function
struct IsOdd : public unary_function<int, bool>
{
	bool operator() (int number)
	{ return number % 2 != 0; }
};

//binary_function
struct Compare : public binary_function<int, int, bool>
{
	bool operator() (int a, int b)
	{ return a == b; }
};


int main(int argc, char *argv[])
{

	IsOdd isOddObj;
	IsOdd::argument_type	input = 10;
	IsOdd::result_type		result;
	result	=	isOddObj(input);
	cout	<<	"Number:"	<<	input	<<	" is "
			<<	(result?"odd":"even")	<<	".\n";

	Compare CompareObj;
	Compare::first_argument_type	input1 = 100;
	Compare::second_argument_type	input2 = 200;
	Compare::result_type			result1;
	result1	=	CompareObj(input1, input2);
	cout	<<	"number:"	<<	input1	<< ":"	<< input2;
	if (result1)
		cout << " are equal\n";
	else
		cout << " are not equal\n";

	return 0;
}

