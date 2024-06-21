/*
File		: menuAkhir.cpp
Deskripsi	: Body modul menuAkhir() untuk menampilkan menu akhir setelah permainan berakhir.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 25/11/2023
*/

#include <stdio.h>
#include <windows.h>
#include "header.h"

void menuAkhir(permainan game, char pemenang[20], int *index_halaman, bool *keluar)
{
	int inp, x, y;
	if (strcmp(pemenang, " ") == 0)
	{
		kursorOut(62, 11);
		printf("DRAW");
	}
	else
	{
		kursorOut(56, 11);
		printf("%s WIN!", pemenang);
	}

	kursorOut(55, 13);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	kursorOut(55, 14);
	printf("%c   CONTINUE   %c", 186, 186);
	kursorOut(55, 15);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 16);
	printf("%c   SAVE GAME  %c", 186, 186);
	kursorOut(55, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 18);
	printf("%c BACK TO MENU %c", 186, 186);
	kursorOut(55, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 20);
	printf("%c     EXIT     %c", 186, 186);
	kursorOut(55, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

	x = 53;
	y = 14;
	kursorOut(x, y);
	printf("%c", 175);
	do
	{
		inp = getch();
		switch (inp)
		{
		case atas:
			printf("\b ");
			if (y > 14)
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
			if (y > 14)
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
			if (y > 14)
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
	case 14:
		*index_halaman = 7;
		system("cls");
		break;
	case 16:
		saveGame(game);
		system("cls");
		break;
	case 18:
		*index_halaman = 1;
		system("cls");
		break;
	case 20:
		*keluar = true;
		system("cls");
		break;
	}
}

void menuAwal(int *index_halaman, bool *keluar)
{
	int x, y, inp;
	banner();
	kursorOut(58, 13);
	printf("Main Menu");
	kursorOut(55, 15);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	kursorOut(55, 16);
	printf("%c    START    %c", 186, 186);
	kursorOut(55, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 18);
	printf("%c  LOAD GAME  %c", 186, 186);
	kursorOut(55, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 20);
	printf("%c  HIGHSCORE  %c", 186, 186);
	kursorOut(55, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 22);
	printf("%c HOW TO PLAY %c", 186, 186);
	kursorOut(55, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 24);
	printf("%c    EXIT     %c", 186, 186);
	kursorOut(55, 25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

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
			if (y < 24)
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
			if (y < 24)
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
			if (y < 24)
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
		*index_halaman = 4;
		break;
	case 18:
		*index_halaman = 2;
		break;
	case 20:
		*index_halaman = 3;
		break;
	case 22:
		*index_halaman = 9;
		break;
	case 24:
		*keluar = true;
		break;
	}
	fflush(stdin);
	system("cls");
}