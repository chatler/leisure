#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>


char* GetString1()
{
	char p[] = "Hello World";
	return p;
}

char* GetString2()
{
	char *p = "Hello World";
	return p;
}

void testBranchPredictor()
{
	const int arraySize = 32768;
	int sum = 0;
	int* data = new int[arraySize];

	srand(time(NULL));
	for (int c = 0; c < arraySize; ++c)
		data[c] = rand()%256;
	data[0] = 129;
	data[1] = 125;

	/*
	   for (int c = 0; c < arraySize; ++c)
	   if (data[c] >= 128)
	   sum += data[c];
	   */

	for (int c = 0; c < 2; ++c) {
		int t = (data[c] - 128) >> 31;
		std::cout << "t:[" << t << "], datac:[" << data[c] << "]\n";
		sum += ~t & data[c];
	}

	if (data) {
		delete [] data;
		data = NULL;
	}
}

int main(int argc, char* argv[])
{
	printf("GetString1 returns: %s. \n", GetString1());
	printf("GetString2 returns: %s. \n", GetString2());
	testBranchPredictor();



	return 0;
}
