#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void trit1(void *ignored);
void trit2(void *ignored);

// int main()
// {
// 	_beginthread(trit1, 0, NULL);
// 	_beginthread(trit2, 0, NULL);
// 	_endthread();
// 	return 0;
// }

void trit1(void *ignored)
{
	printf("Tekan enter");
	int inp = getch();
	if (inp == 13)
	{
		exit(1);
	}
}

void trit2(void *ignored)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", i);
		sleep(1);
		printf("\b ");
	}
}
