// file maxSubSum.cc

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>

using namespace std;


/*
 * cubic maximum contiguous subsequence sum algorithm
 */

uint64_t maxSubSumNaive(const vector<int>& a)
{
	uint64_t maxSum = 0;

	for (uint32_t i = 0; i < a.size(); i++)
		for (uint32_t j = i; j < a.size(); j++)
		{
			uint64_t thisSum = 0;

			for (uint32_t k = i; k <= j; k++)
				thisSum += a[k];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}

	return maxSum;
}


int main()
{
	vector<int> array;


	int nloops = 20;
	srand(time(NULL));
	for (int j = 0; j < nloops; j++) {
		int r = rand();
		array.push_back(r);
		printf("%d:%d%c", j+1, r, (j+1)%10 ?  ' ': '\n');
	}

	printf("\nafter:maxsumNaive:\n");
	uint64_t maxsum = maxSubSumNaive(array);
	printf("maxsum:%ld\n", maxsum);


	return 0;
}

