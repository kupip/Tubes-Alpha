/*
File		: pilihPapan.cpp
Deskripsi	: Body modul pilihPapan() untuk menampilkan menu pemilihan jenis papan.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 30/11/2023
*/
#include <stdio.h>
#include "header.h"

void pilihPapan(int *index_halaman, int *jenis_papan)
{
	system("cls");
	int x, y, inp;
	banner();
	kursorOut(57, 13);
	printf("Pilih Papan");
	kursorOut(55, 15);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	kursorOut(55, 16);
	printf("%c 3x3          %c", 186, 186);
	kursorOut(55, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 18);
	printf("%c 5x5          %c", 186, 186);
	kursorOut(55, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 20);
	printf("%c 7x7          %c", 186, 186);
	kursorOut(55, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	kursorOut(55, 22);
	printf("%c Back         %c", 186, 186);
	kursorOut(55, 23);
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
			if (y < 22)
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
			if (y < 22)
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
			if (y < 22)
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
		*index_halaman = 6;
		*jenis_papan = 3;
		break;
	case 18:
		*index_halaman = 6;
		*jenis_papan = 5;
		break;
	case 20:
		*index_halaman = 6;
		*jenis_papan = 7;
		break;
	case 22:
		*index_halaman = 4;
	}
}
