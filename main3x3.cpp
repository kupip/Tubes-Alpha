/*
File		: main3x3.cpp
Deskripsi	: Body modul-modul main3 untuk memainkkan tic tac toe dengan papan 3x3.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 10/12/2023
*/

#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"

char papan3[3][3] = {{' ', ' ', ' '},
					{' ', ' ', ' '},
					{' ', ' ', ' '}};

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 3x3                      |*/
/*+---------------------------------------------------------------+*/

void main3(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	int turn = 1;
	int kosong = 9;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan3(&papan3);

	while (kosong != 0)
	{
		printPapan3(papan3);
		giliran3(&papan3, &turn, (*game).modeMain);
		kosong = cekKosong3(papan3);
		idx_pemenang = cekPemenang3(papan3);
		printPapan3(papan3);

		if (idx_pemenang == 1)
		{
			strcpy((*pemenang), (*game).pemain1.nama);
			kursorOut(68, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain1.skor++;
			*index_halaman = 8;
			Sleep(2000);
			system("cls");
			break;
		}
		else if (idx_pemenang == 2)
		{
			strcpy((*pemenang), (*game).pemain2.nama);
			kursorOut(68, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain2.skor++;
			*index_halaman = 8;
			Sleep(2000);
			system("cls");
			break;
		}
		else if (idx_pemenang == 3 && kosong == 0)
		{
			kursorOut(68, 5);
			printf("Draw");
			strcpy((*pemenang), " ");
			*index_halaman = 8;
			Sleep(2000);
			system("cls");
			break;
		}
	}
}

// Modul untuk mengecek kondisi draw untuk 3x3
int cekKosong3(char papan[3][3])
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (papan[i][j] == ' ')
			{
				count++;
			}
		}
	}
	return count;
}

// Modul untuk memeriksa pemenang pada 3x3
int cekPemenang3(char papan[3][3])
{
	// Cek pemanang baris
	for (int baris = 0; baris < 3; baris++)
	{
		if (papan[baris][0] == papan[baris][1] && papan[baris][1] == papan[baris][2])
		{
			if (papan[baris][1] == 'X')
			{
				return 1;
			}
			else if (papan[baris][1] == 'O')
			{
				return 2;
			}
		}
	}

	// Cek pemenang kolom
	for (int kolom = 0; kolom < 3; kolom++)
	{
		if (papan[0][kolom] == papan[1][kolom] && papan[1][kolom] == papan[2][kolom])
		{
			if (papan[1][kolom] == 'X')
			{
				return 1;
			}
			else if (papan[1][kolom] == 'O')
			{
				return 2;
			}
		}
	}

	// Cek pemenang diagonal 1
	if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2])
	{
		if (papan[1][1] == 'X')
		{
			return 1;
		}
		else if (papan[1][1] == 'O')
		{
			return 2;
		}
	}
	// Cek pemenang diagonal 2
	if (papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0])
	{
		if (papan[1][1] == 'X')
		{
			return 1;
		}
		else if (papan[1][1] == 'O')
		{
			return 2;
		}
	}
	return 3;
}

// Modul untuk mengisi papan 3x3
void giliran3(char (*papan)[3][3], int *giliran, int modeMain)
{
	int n, i, j;

	// pengecekan kondisi vs Player atau Computer
	if (modeMain == 2)
	{
		kursorOut(68, 19);
		printf("Giliran pemain %d", *giliran);
		kursorOut(68, 21);
		printf("Masukkan nomor papan:   %c", 174);
		timer(90, 21);
		if (kbhit() == 1)
		{
			kursorOut(90, 21);
			scanf("%d", &n);
			i = (n - 1) / 3;
			j = (n - 1) % 3;
			if (n > 9 || n < 1)
			{
				kursorOut(68, 23);
				printf("Harap masukkan angka yang sesuai");
				sleep(1);

				// Untuk membersihkan hasil print di layar
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
				fflush(stdin);
			}
			else if ((*papan)[i][j] == ' ' && (*giliran) == 1)
			{
				(*papan)[i][j] = 'X';
				(*giliran) = 2;
			}
			else if ((*papan)[i][j] == ' ' && (*giliran) == 2)
			{
				(*papan)[i][j] = 'O';
				(*giliran) = 1;
			}
			else
			{
				kursorOut(68, 23);
				printf("kotak sudah terisi");
				sleep(1);

				// Untuk membersihkan hasil print di layar
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
				fflush(stdin);
			}
		}
		else
		{
			if ((*giliran) == 1) {
				*giliran = 2;
			} else {
				*giliran = 1;
			}
		}
	}
	else
	{
		kursorOut(68, 19);
		printf("Masukkan nomor papan:   %c", 174);
		if (*giliran == 1)
		{
			timer(90, 19);
			if (kbhit())
			{
				kursorOut(90, 19);
				scanf("%d", &n);
				i = (n - 1) / 3;
				j = (n - 1) % 3;
				if (n > 9 || n < 1)
				{
					kursorOut(68, 21);
					printf("Harap masukkan angka yang sesuai");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
					fflush(stdin);
				}
				else if ((*papan)[i][j] == ' ')
				{
					(*papan)[i][j] = 'X';
					(*giliran) = 2;
				}
				else
				{
					kursorOut(68, 21);
					printf("kotak sudah terisi");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
					fflush(stdin);
				}
			}
			else
			{
				i = posisiTerbaik3(papan3).i;
				j = posisiTerbaik3(papan3).j;
				(*papan)[i][j] = 'O';
				*giliran = 1;
			}
		}
		else
		{
			i = posisiTerbaik3(papan3).i;
			j = posisiTerbaik3(papan3).j;
			(*papan)[i][j] = 'O';
			*giliran = 1;
		}
	}
}

// Inisialisasi papan kosong 3x3
void setPapan3(char (*papan)[3][3])
{
	for (int brs = 0; brs < 3; brs++)
	{
		for (int klm = 0; klm < 3; klm++)
		{
			(*papan)[brs][klm] = ' ';
		}
	}
}
