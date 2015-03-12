//file fibonacci.cc
//

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

using namespace std;


uint64_t fib(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fib(n-1) + fib(n-2);
}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	   cout	<< "argc should be only 2" << endl;
	   exit(EXIT_SUCCESS);
	}

	int i = atoi(argv[1]);
	cout << "i:" << i << endl;
	cout << "fib:" << i << ":" << fib(i) << endl;

	return 0;
}

