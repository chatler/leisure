#include <stdio.h>


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


int main(int argc, char* argv[])
{
	printf("GetString1 returns: %s. \n", GetString1());
	printf("GetString2 returns: %s. \n", GetString2());

	return 0;
}
