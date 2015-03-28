// file maxSubSum.cc

#include <vector>

using namespace std;


/*
 * cubic maximum contiguous subsequence sum algorithm
 */

uint64_t maxSubSumNaive(const vector<int>& a)
{
	int maxSum = 0;

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

	srand();

	return 0;
}

