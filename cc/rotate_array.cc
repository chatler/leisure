#include <cstdio>

void rotate(int a[], int n, int k)
{
	k %=n;
	if (n <= 0 || k < 1)
		return;

	int t = n, s = 0;
	while (t>0)
	{
		int tmp = a[s], i = s;
		do
		{
			a[i] = (i-k+n)%n != s ? a[(i-k+n) % n] : tmp;
			--t;
			i = (i-k+n)%n;
		}
		while (i != s);
		++s;
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	rotate(a, 9, 2);
	for (int i = 0; i < 9; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

