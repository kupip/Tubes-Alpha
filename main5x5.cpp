/*
File		: main5x5.cpp
Deskripsi	: Body modul-modul main5 untuk memainkkan tic tac toe dengan papan 5x5.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 10/12/2023
*/

#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"

char papan5[5][5] = {{' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '}};

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 5x5                      |*/
/*+---------------------------------------------------------------+*/
void main5(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	int turn = 1;
	int kosong = 9;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan5(&papan5);
	while (kosong != 0)
	{
		printPapan5(papan5);
		giliran5(&papan5, &turn, (*game).modeMain);
		kosong = cekKosong5(papan5);
		idx_pemenang = cekPemenang5(papan5);
		printPapan5(papan5);

		if (idx_pemenang == 1)
		{
			strcpy((*pemenang), (*game).pemain1.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain1.skor++;
			*index_halaman = 8;
			Sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 2)
		{
			strcpy((*pemenang), (*game).pemain2.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain2.skor++;
			*index_halaman = 8;
			Sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 3 && kosong == 0)
		{
			printf("Draw");
			strcpy((*pemenang), " ");
			*index_halaman = 8;
			Sleep(2);
			system("cls");
			break;
		}
	}
}

// Inisialisasi papan kosong 5x5
void setPapan5(char (*papan)[5][5])
{
	for (int brs = 0; brs < 5; brs++)
	{
		for (int klm = 0; klm < 5; klm++)
		{
			(*papan)[brs][klm] = ' ';
		}
	}
}

int temp_i5, temp_j5; // dua variabel untuk menampung indeks yang diinputkan oleh user
// Modul untuk mengisi papan 5x5
void giliran5(char (*papan)[5][5], int *giliran, int modeMain)
{
	int n, i, j;

	if (modeMain == 2)
	{
		kursorOut(61, 27);
		printf("Giliran pemain %d", *giliran);
		kursorOut(61, 28);
		printf("Masukkan nomor papan:   \b\b");
		timer(90, 28);

		// jika pengguna menekan keyboard
		if (kbhit())
		{
			kursorOut(90, 28);
			scanf("%d", &n);
			i = (n - 1) / 5;
			j = (n - 1) % 5;
			if (n > 25 || n < 1)
			{
				kursorOut(61, 37);
				printf("Harap masukkan angka yang sesuai");
				sleep(1);

				// Untuk membersihkan hasil print di layar
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
				fflush(stdin);
			}
			else if ((*papan)[i][j] == ' ' && *giliran == 1)
			{
				(*papan)[i][j] = 'X';
				(*giliran) = 2;
			}
			else if ((*papan)[i][j] == ' ' && *giliran == 2)
			{
				(*papan)[i][j] = 'O';
				(*giliran) = 1;
			}
			else
			{
				kursorOut(61, 37);
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
		kursorOut(68, 28);
		printf("Masukkan nomor papan:   %c", 174);
		if (*giliran == 1)
		{
			timer(90, 28);
			if (kbhit())
			{
				kursorOut(90, 28);
				scanf("%d", &n);
				i = (n - 1) / 5;
				j = (n - 1) % 5;
				if (n > 25 || n < 1)
				{
					kursorOut(68, 30);
					printf("Harap masukkan angka yang sesuai");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
					fflush(stdin);
				}
				else if ((*papan)[i][j] == ' ')
				{
					(*papan)[i][j] = 'X';
					temp_i5 = i;
					temp_j5 = j;
					*giliran = 2;
				}
				else
				{
					kursorOut(68, 30);
					printf("kotak sudah terisi");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
					fflush(stdin);
				}
			}
			else
			{
				*giliran = 2;
			}
		}
		else
		{
			i = posisiTerbaik5(papan5, temp_i5, temp_j5).i;
			j = posisiTerbaik5(papan5, temp_i5, temp_j5).j;
			(*papan)[i][j] = 'O';
			*giliran = 1;
		}
	}
}

// Modul untuk menegecek kondisi draw untuk 5x5
int cekKosong5(char papan[5][5])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (papan[i][j] == ' ')
			{
				count++;
			}
		}
	}
	return count;
}

int cekPemenang5(char papan[5][5])
{
	// Cek pemenang baris
	for (int baris = 0; baris < 5; baris++)
	{
		if ((papan[baris][0] == papan[baris][1] || papan[baris][3] == papan[baris][4]) && papan[baris][1] == papan[baris][2] && papan[baris][2] == papan[baris][3])
		{
			if (papan[baris][2] == 'X' && (papan[baris][0] == 'X' || papan[baris][4] == 'X'))
			{
				return 1;
			}
			else if (papan[baris][2] == 'O' && (papan[baris][0] == 'O' || papan[baris][4] == 'O'))
			{
				return 2;
			}
		}
	}

	// Cek pemenang kolom
	for (int kolom = 0; kolom < 5; kolom++)
	{
		if ((papan[0][kolom] == papan[1][kolom] || papan[3][kolom] == papan[4][kolom]) && papan[1][kolom] == papan[2][kolom] && papan[2][kolom] == papan[3][kolom])
		{
			if (papan[2][kolom] == 'X' && (papan[0][kolom] == 'X' || papan[4][kolom] == 'X'))
			{
				return 1;
			}
			else if (papan[2][kolom] == 'O' && (papan[0][kolom] == 'O' || papan[4][kolom] == 'O'))
			{
				return 2;
			}
		}
	}

	// Cek pemenang diagonal '\' besar
	if ((papan[0][0] == papan[1][1] || papan[4][4] == papan[3][3]) && papan[1][1] == papan[2][2] && papan[2][2] == papan[3][3])
	{
		if (papan[2][2] == 'X' && (papan[0][0] == 'X' || papan[4][4] == 'X'))
		{
			return 1;
		}
		else if (papan[2][2] == 'O' && (papan[0][0] == 'O' || papan[4][4] == 'O'))
		{
			return 2;
		}
	}

	// Cek pemenang diagonal '/' besar
	if ((papan[0][4] == papan[1][3] || papan[3][1] == papan[4][0]) && papan[1][3] == papan[2][2] && papan[2][2] == papan[3][1])
	{
		if (papan[2][2] == 'X' && (papan[0][4] == 'X' || papan[3][1] == 'X'))
		{
			return 1;
		}
		else if (papan[2][2] == 'O' && (papan[0][4] == 'O' || papan[3][1] == 'O'))
		{
			return 2;
		}
	}

	// Cek pemenang diagonal '/' kecil 1
	if (papan[0][3] == papan[1][2] && papan[1][2] == papan[2][1] && papan[3][0] == papan[2][1])
	{
		if (papan[0][3] == 'X')
		{
			return 1;
		}
		else if (papan[0][3] == 'O')
		{
			return 2;
		}
	}

	// Cek pemenang diagonal '/' kecil 2
	if (papan[1][4] == papan[2][3] && papan[2][3] == papan[3][2] && papan[4][1] == papan[3][2])
	{
		if (papan[1][4] == 'X')
		{
			return 1;
		}
		else if (papan[1][4] == 'O')
		{
			return 2;
		}
	}

	// Cek pemenang diagonal '\' kecil 1
	if (papan[1][0] == papan[2][1] && papan[3][2] == papan[2][1] && papan[3][2] == papan[4][3])
	{
		if (papan[4][3] == 'X')
		{
			return 1;
		}
		else if (papan[4][3] == 'O')
		{
			return 2;
		}
	}

	// Cek pemenang diagonal '\' kecil 2
	if (papan[0][1] == papan[1][2] && papan[1][2] == papan[2][3] && papan[2][3] == papan[3][4])
	{
		if (papan[0][1] == 'X')
		{
			return 1;
		}
		else if (papan[0][1] == 'O')
		{
			return 2;
		}
	}
	return 3;
}
