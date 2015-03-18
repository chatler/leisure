// file factorial.cc

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

using namespace std;


uint64_t factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n-1);

}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
	   cout	<< "argc should be only 2" << endl;
	   exit(EXIT_SUCCESS);
	}

	int i = atoi(argv[1]);
	cout << "i:" << i << endl;
	cout << "factorial:" << i << ":" << factorial(i) << endl;


	return 0;
}


