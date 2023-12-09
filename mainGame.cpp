/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"

char papan3[3][3] = {{' ', ' ', ' '},
										 {' ', ' ', ' '},
										 {' ', ' ', ' '}};

char papan5[5][5] = {{' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' '}};

char papan7[7][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
										 {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
int turn = 1;
int kosong = 9;
void timer();

// Deklarasi modul untuk 3x3
void main3(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong3(char papan[3][3]);
int cekPemenang3(char papan[3][3]);
void giliran3(char (*papan)[3][3], int *giliran);
void setPapan3(char (*papan)[3][3]);

// Deklarasi modul untuk 5x5
void main5(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong5(char papan[5][5]);
int cekPemenang5(char papan[5][5]);
void giliran5(char (*papan)[5][5], int *giliran);
void setPapan5(char (*papan)[5][5]);

// Deklarasi modul untuk 7x7
void main7(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong7(char papan[7][7]);
int cekPemenang7(char papan[7][7]);
void giliran7(char (*papan)[7][7], int *giliran);
void setPapan7(char (*papan)[7][7]);

void mainGame(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	switch ((*game).jenis_papan)
	{
	case 3:
		main3(&(*game), &(*pemenang), &(*index_halaman));
		break;
	case 5:
		main5(&(*game), &(*pemenang), &(*index_halaman));
		break;
	case 7:
		main7(&(*game), &(*pemenang), &(*index_halaman));
		break;
	}
}

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 3x3                      |*/
/*+---------------------------------------------------------------+*/
void main3(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan3(&papan3);
	while (kosong != 0)
	{
		printPapan3(papan3);
		giliran3(&papan3, &turn);
		kosong = cekKosong3(papan3);
		idx_pemenang = cekPemenang3(papan3);
		printPapan3(papan3);

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

void giliran3(char (*papan)[3][3], int *giliran)
{
	int n, i, j;
	kursorOut(68, 19);
	printf("Giliran pemain %d", *giliran);
	kursorOut(68, 21);
	printf("Masukkan nomor papan:   \b\b");
	scanf("%d", &n);
	i = (n - 1) / 3;
	j = (n - 1) % 3;

	if (n > 9 || n < 1)
	{
		kursorOut(68, 23);
		printf("Harap masukkan angka yang sesuai");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
		fflush(stdin);
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 1)
	{
		(*papan)[i][j] = 'X';
		*giliran = 2;
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 2)
	{
		(*papan)[i][j] = 'O';
		*giliran = 1;
	}
	else
	{
		kursorOut(68, 23);
		printf("kotak sudah terisi");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
		fflush(stdin);
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

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 5x5                      |*/
/*+---------------------------------------------------------------+*/
void main5(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan5(&papan5);
	while (kosong != 0)
	{
		printPapan5(papan5);
		giliran5(&papan5, &turn);
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

void giliran5(char (*papan)[5][5], int *giliran)
{
	int n, i, j;
	kursorOut(61, 27);
	printf("Giliran pemain %d", *giliran);
	kursorOut(61, 28);
	printf("Masukkan nomor papan:   \b\b");
	scanf("%d", &n);
	i = (n - 1) / 5;
	j = (n - 1) % 5;
	fflush(stdin);

	if (n > 26 || n < 1)
	{
		kursorOut(61, 29);
		printf("Harap masukkan angka yang sesuai");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
		fflush(stdin);
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 1)
	{
		(*papan)[i][j] = 'X';
		*giliran = 2;
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 2)
	{
		(*papan)[i][j] = 'O';
		*giliran = 1;
	}
	else
	{
		kursorOut(61, 29);
		printf("kotak sudah terisi");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
		fflush(stdin);
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

/*+---------------------------------------------------------------+*/
/*|                      MODUL PERMAINAN 5x5                      |*/
/*+---------------------------------------------------------------+*/
void main7(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	int idx_pemenang = 0;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan7(&papan7);
	while (kosong != 0)
	{
		printPapan7(papan7);
		giliran7(&papan7, &turn);
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

void giliran7(char (*papan)[7][7], int *giliran)
{
	int n, i, j;
	kursorOut(61, 35);
	printf("Giliran pemain %d", *giliran);
	kursorOut(61, 36);
	printf("Masukkan nomor papan:   \b\b");
	scanf("%d", &n);
	i = (n - 1) / 7;
	j = (n - 1) % 7;
	fflush(stdin);

	if (n > 49 || n < 1)
	{
		kursorOut(61, 37);
		printf("Harap masukkan angka yang sesuai");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
		fflush(stdin);
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 1)
	{
		(*papan)[i][j] = 'X';
		*giliran = 2;
	}
	else if ((*papan)[i][j] == ' ' && *giliran == 2)
	{
		(*papan)[i][j] = 'O';
		*giliran = 1;
	}
	else
	{
		kursorOut(61, 37);
		printf("kotak sudah terisi");
		Sleep(1);

		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
		fflush(stdin);
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

// timer
void timer()
{
	kursorOut(73, 2);
	int time = 10;
	printf("Waktu: %d", time);
	kursorOut(90, 21);
	Sleep(1);
	time--;
	while (!kbhit() && time >= 0)
	{
		kursorOut(73, 2);
		printf("\b ");
		printf("Waktu: %d ", time);
		kursorOut(90, 21);
		time--;
		Sleep(1);
	}
}