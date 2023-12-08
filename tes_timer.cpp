// C++ program to demonstrate use of kbhit()
#include <stdio.h>
#include <conio.h>

int main()
{
    while (!kbhit()) {
    	printf("Press a key\n");
	}
	printf("%d\n", kbhit());
	printf("%d", getch());
//	fflush(stdin);
//	int inp;
//	inp = getch();
//	printf("%c", inp);
    return 0;
}
