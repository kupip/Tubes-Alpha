/*
File		: pilihMode.cpp
Deskripsi	: Body modul pilihMode() untuk menampilkan menu awal permainan ke layar.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 30/11/2023
*/
#include <stdio.h>
#include "header.h"

void pilihMode(int *index_halaman, int *modeMain)
{
	system("cls");
	int x, y, inp;
	banner();
	kursorOut(57, 13);
	printf("Pilih Mode");
	kursorOut(55, 15);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	kursorOut(55, 16);
	printf("%c vs Player    %c", 186, 186);
	kursorOut(55, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 18);
	printf("%c vs Computer  %c", 186, 186);
	kursorOut(55, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 20);
	printf("%c Back         %c", 186, 186);
	kursorOut(55, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

	x = 53;
	y = 16;
	kursorOut(x, y);
	printf("%c", 175);
	do
	{
		inp = getch();
		switch (inp)
		{
		case atas:
			printf("\b ");
			if (y > 16)
			{
				y -= 2;
			}
			break;
		case bawah:
			printf("\b ");
			if (y < 20)
			{
				y += 2;
			}
		}

		switch (inp)
		{
		case W:
			printf("\b ");
			if (y > 16)
			{
				y -= 2;
			}
			break;
		case S:
			printf("\b ");
			if (y < 20)
			{
				y += 2;
			}
		case w:
			printf("\b ");
			if (y > 16)
			{
				y -= 2;
			}
			break;
		case s:
			printf("\b ");
			if (y < 20)
			{
				y += 2;
			}
		}

		kursorOut(x, y);
		printf("%c", 175);
	} while (inp != 13);

	switch (y)
	{
	case 16:
		*index_halaman = 5;
		*modeMain = 2;
		break;
	case 18:
		*index_halaman = 5;
		*modeMain = 1;
		break;
	case 20:
		system("cls");
		*index_halaman = 1;
		break;
	}
}
