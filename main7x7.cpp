/*
File		: main7x7.cpp
Deskripsi	: Body modul-modul main7 untuk memainkkan tic tac toe dengan papan 7x7.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 10/12/2023
*/

#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"

char papan7[7][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 7x7                      |*/
/*+---------------------------------------------------------------+*/
void main7(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	int turn = 1;
	int kosong = 9;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan7(&papan7);
	while (kosong != 0)
	{
		printPapan7(papan7);
		giliran7(&papan7, &turn, (*game).modeMain);
		kosong = cekKosong7(papan7);
		idx_pemenang = cekPemenang7(papan7);
		printPapan7(papan7);

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

// Modul untuk mengosongkan papan 7x7
void setPapan7(char (*papan)[7][7])
{
	for (int brs = 0; brs < 7; brs++)
	{
		for (int klm = 0; klm < 7; klm++)
		{
			(*papan)[brs][klm] = ' ';
		}
	}
}

// Modul untuk mengisi papan 7x7
void giliran7(char (*papan)[7][7], int *giliran, int modeMain)
{
	int n, i, j;
	int temp_i = 1, temp_j = 1;

	// pengecekan kondisi vs Player atau Computer
	if (modeMain == 2)
	{
		kursorOut(68, 35);
		printf("Giliran pemain %d", *giliran);
		kursorOut(68, 36);
		printf("Masukkan nomor papan:   %c", 174);
		timer(90, 36);
		if (kbhit() == 1)
		{
			kursorOut(90, 36);
			scanf("%d", &n);
			i = (n - 1) / 7;
			j = (n - 1) % 7;
			if (n > 49 || n < 1)
			{
				kursorOut(68, 38);
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
				kursorOut(68, 38);
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
		kursorOut(68, 36);
		printf("Masukkan nomor papan:   %c", 174);
		if (*giliran == 1)
		{
			timer(90, 36);
			if (kbhit() == 1)
			{
				kursorOut(90, 36);
				scanf("%d", &n);
				i = (n - 1) / 7;
				j = (n - 1) % 7;
				if (n > 49 || n < 1)
				{
					kursorOut(68, 38);
					printf("Harap masukkan angka yang sesuai");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
					fflush(stdin);
				}
				else if ((*papan)[i][j] == ' ')
				{
					(*papan)[i][j] = 'X';
					*giliran = 2;
				}
				else
				{
					kursorOut(68, 38);
					printf("kotak sudah terisi");
					sleep(1);

					// Untuk membersihkan hasil print di layar
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
					fflush(stdin);
				}
                temp_i = i;
                temp_j = j;
			}
			else
			{
				*giliran = 2;
			}
		}
		else
		{
			printf(" %d %d", temp_i, temp_j);
            i = posisiTerbaik7(papan7, temp_i, temp_j).i;
			j = posisiTerbaik7(papan7, temp_i, temp_j).j;
			(*papan)[i][j] = 'O';
			*giliran = 1;
		}
	}
}

int cekKosong7(char papan[7][7])
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (papan[i][j] == ' ')
			{
				count++;
			}
		}
	}
	return count;
}

// Modul untuk memeriksa pemenang pada 7x7
int cekPemenang7(char papan[7][7])
{
	// Untuk mengecek kemenangan pada baris
	// Dalam 1 baris, ada 3 pola kemenangan
	for (int baris = 0; baris < 7; baris++)
	{
		if (papan[baris][0] == papan[baris][1] &&
				papan[baris][1] == papan[baris][2] &&
				papan[baris][2] == papan[baris][3] &&
				papan[baris][3] == papan[baris][4])
		{
			if (papan[baris][0] == 'X')
			{
				return 1;
			}
			else if (papan[baris][0] == 'O')
			{
				return 2;
			}
		}
		if (papan[baris][1] == papan[baris][2] &&
				papan[baris][2] == papan[baris][3] &&
				papan[baris][3] == papan[baris][4] &&
				papan[baris][4] == papan[baris][5])
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
		if (papan[baris][2] == papan[baris][3] &&
				papan[baris][3] == papan[baris][4] &&
				papan[baris][4] == papan[baris][5] &&
				papan[baris][5] == papan[baris][6])
		{
			if (papan[baris][2] == 'X')
			{
				return 1;
			}
			else if (papan[baris][2] == 'O')
			{
				return 2;
			}
		}
	}

	// Untuk mengecek kemenangan pada kolom
	// Dalam 1 kolom, ada 3 pola kemenangan
	for (int kolom = 0; kolom < 7; kolom++)
	{
		if (papan[0][kolom] == papan[1][kolom] &&
				papan[1][kolom] == papan[2][kolom] &&
				papan[2][kolom] == papan[3][kolom] &&
				papan[3][kolom] == papan[4][kolom])
		{
			if (papan[0][kolom] == 'X')
			{
				return 1;
			}
			else if (papan[0][kolom] == 'O')
			{
				return 2;
			}
		}
		if (papan[1][kolom] == papan[2][kolom] &&
				papan[2][kolom] == papan[3][kolom] &&
				papan[3][kolom] == papan[4][kolom] &&
				papan[4][kolom] == papan[5][kolom])
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
		if (papan[2][kolom] == papan[3][kolom] &&
				papan[3][kolom] == papan[4][kolom] &&
				papan[4][kolom] == papan[5][kolom] &&
				papan[5][kolom] == papan[6][kolom])
		{
			if (papan[2][kolom] == 'X')
			{
				return 1;
			}
			else if (papan[2][kolom] == 'O')
			{
				return 2;
			}
		}
	}

	// Untuk mengecek diagonal '\' besar
	// Diagonal besar '\' ada 3 kemungkinan
	// kemungkinan 1
	if (papan[0][0] == papan[1][1] &&
			papan[1][1] == papan[2][2] &&
			papan[2][2] == papan[3][3] &&
			papan[3][3] == papan[4][4])
	{
		if (papan[0][0] == 'X')
		{
			return 1;
		}
		else if (papan[0][0] == 'O')
		{
			return 2;
		}
	}
	// kemungkinan 2
	if (papan[1][1] == papan[2][2] &&
			papan[2][2] == papan[3][3] &&
			papan[3][3] == papan[4][4] &&
			papan[4][4] == papan[5][5])
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
	// kemungkinan 3
	if (papan[2][2] == papan[3][3] &&
			papan[3][3] == papan[4][4] &&
			papan[4][4] == papan[5][5] &&
			papan[5][5] == papan[6][6])
	{
		if (papan[2][2] == 'X')
		{
			return 1;
		}
		else if (papan[2][2] == 'O')
		{
			return 2;
		}
	}

	// Untuk mengecek diagonal '/' besar
	// Diagonal besar '/' ada 3 kemungkinan
	// kemungkinan 1
	if (papan[0][6] == papan[1][5] &&
			papan[1][5] == papan[2][4] &&
			papan[2][4] == papan[3][3] &&
			papan[3][3] == papan[4][2])
	{
		if (papan[0][6] == 'X')
		{
			return 1;
		}
		else if (papan[0][6] == 'O')
		{
			return 2;
		}
	}
	// kemungkinan 2
	if (papan[1][5] == papan[2][4] &&
			papan[2][4] == papan[3][3] &&
			papan[3][3] == papan[4][2] &&
			papan[4][2] == papan[5][1])
	{
		if (papan[1][5] == 'X')
		{
			return 1;
		}
		else if (papan[1][5] == 'O')
		{
			return 2;
		}
	}
	// kemungkinan 3
	if (papan[2][4] == papan[3][3] &&
			papan[3][3] == papan[4][2] &&
			papan[4][2] == papan[5][1] &&
			papan[5][1] == papan[6][0])
	{
		if (papan[2][4] == 'X')
		{
			return 1;
		}
		else if (papan[2][4] == 'O')
		{
			return 2;
		}
	}

	// Untuk mengecek diagonal '/' sedang, ada 2 diagonal '/' sedang
	// setiap diagonal '/' sedang, ada 2 kemungkinan
	// diagonal '/' sedang 1
	if ((papan[0][5] == papan[1][4] || papan[5][0] == papan[4][1]) &&
			papan[1][4] == papan[2][3] &&
			papan[2][3] == papan[3][2] &&
			papan[3][2] == papan[4][1])
	{
		if (papan[2][3] == 'X' && (papan[0][5] == 'X' || papan[5][0] == 'X'))
		{
			return 1;
		}
		else if (papan[2][3] == 'O' && (papan[0][5] == 'O' || papan[5][0] == 'O'))
		{
			return 2;
		}
	}
	// diagonal '/' sedang 2
	if ((papan[1][6] == papan[2][5] || papan[6][1] == papan[5][2]) &&
			papan[2][5] == papan[3][4] &&
			papan[3][4] == papan[4][3] &&
			papan[4][3] == papan[5][2])
	{
		if (papan[3][4] == 'X' && (papan[1][6] == 'X' || papan[6][1] == 'X'))
		{
			return 1;
		}
		else if (papan[3][4] == 'O' && (papan[1][6] == 'O' || papan[6][1] == 'O'))
		{
			return 2;
		}
	}

	// Untuk mengecek diagonal '\' sedang, ada 2 diagonal '\' sedang
	// setiap diagonal '\' sedang, ada 2 kemungkinan
	// diagonal '\' sedang 1
	if ((papan[0][1] == papan[1][2] || papan[5][6] == papan[4][5]) &&
			papan[1][2] == papan[2][3] &&
			papan[2][3] == papan[3][4] &&
			papan[3][4] == papan[4][5])
	{
		if (papan[2][3] == 'X' && (papan[0][1] == 'X' || papan[5][6] == 'X'))
		{
			return 1;
		}
		else if (papan[2][3] == 'O' && (papan[0][1] == 'O' || papan[5][6] == 'O'))
		{
			return 2;
		}
	}
	// diagonal '\' sedang 2
	if ((papan[1][0] == papan[2][1] || papan[6][5] == papan[5][4]) &&
			papan[2][1] == papan[3][2] &&
			papan[3][2] == papan[4][3] &&
			papan[4][3] == papan[5][4])
	{
		if (papan[3][2] == 'X' && (papan[1][0] == 'X' || papan[6][5] == 'X'))
		{
			return 1;
		}
		else if (papan[3][2] == 'O' && (papan[1][0] == 'O' || papan[6][5] == 'O'))
		{
			return 2;
		}
	}

	// Untuk mengecek diagonal '\' kecil, ada 2 diagonal '\' kecil
	// diagonal '\' kecil 1
	if (papan[0][2] == papan[1][3] &&
			papan[1][3] == papan[2][4] &&
			papan[2][4] == papan[3][5] &&
			papan[3][5] == papan[4][6])
	{
		if (papan[0][2] == 'X')
		{
			return 1;
		}
		else if (papan[0][2] == 'O')
		{
			return 2;
		}
	}
	// diagonal '\' kecil 2
	if (papan[2][0] == papan[3][1] &&
			papan[3][1] == papan[4][2] &&
			papan[4][2] == papan[5][3] &&
			papan[5][3] == papan[6][4])
	{
		if (papan[2][0] == 'X')
		{
			return 1;
		}
		else if (papan[2][0] == 'O')
		{
			return 2;
		}
	}

	// Untuk mengecek diagonal '/' kecil, ada 2 diagonal '/' kecil
	// diagonal '/' kecil 1
	if (papan[0][4] == papan[1][3] &&
			papan[1][3] == papan[2][2] &&
			papan[2][2] == papan[3][1] &&
			papan[3][1] == papan[4][0])
	{
		if (papan[0][4] == 'X')
		{
			return 1;
		}
		else if (papan[0][4] == 'O')
		{
			return 2;
		}
	}
	// diagonal '/' kecil 2
	if (papan[2][6] == papan[3][5] &&
			papan[3][5] == papan[4][4] &&
			papan[4][4] == papan[5][3] &&
			papan[5][3] == papan[6][2])
	{
		if (papan[2][6] == 'X')
		{
			return 1;
		}
		else if (papan[2][6] == 'O')
		{
			return 2;
		}
	}
	return 3;
}