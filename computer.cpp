/*
File		: computer.cpp
Deskripsi	: Body modul minimax() untuk menemukan gerakan terbaik bagi komputer.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include "header.h"
// #include "mainGame.cpp"

// Modul minimax untuk mengecek kemungkinan nilai dari sebuah gerakan
int minimax3(char papan[3][3], int kedalaman, bool maximizing)
{
	int skor = cekPemenang3(papan);
	int sementara;
	if (skor == 1)
	{
		return -1;
	}
	else if (skor == 2)
	{
		return 1;
	}
	else if (skor == 3)
	{
		return 0;
	}

	if (maximizing)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'O';
					sementara = minimax3(papan, kedalaman + 1, false);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara > best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'X';
					sementara = minimax3(papan, kedalaman + 1, true);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara < best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
}

// Modul untuk mencari posisi terbaik pada papan 3x3
posisi posisiTerbaik3(char papan[3][3])
{
	int best = -1000;
	int sementara;
	int depth = 0;
	posisi posTerbaik = {-1, -1};

	// Menguji setiap posisi yang mungkin
	if (papan[1][1] == ' ')
	{
		posTerbaik.i = 1;
		posTerbaik.j = 1;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'O';
					sementara = minimax3(papan, 0, false);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara > best)
					{
						best = sementara;
						posTerbaik.i = i;
						posTerbaik.j = j;
					}
				}
			}
		}
	}
	return posTerbaik;
}

// Modul minimax untuk mengecek kemungkinan nilai dari sebuah gerakan
int minimax5(char papan[5][5], int kedalaman, bool maximizing)
{
	int skor = cekPemenang5(papan);
	int sementara;
	if (skor == 1)
	{
		return -1;
	}
	else if (skor == 2)
	{
		return 1;
	}
	else if (skor == 3)
	{
		return 0;
	}

	if (maximizing)
	{
		int best = -10;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'O';
					sementara = minimax5(papan, kedalaman + 1, false);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara > best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
	else
	{
		int best = 10;
		for (int i = 5; i < 5; i++)
		{
			for (int j = 5; j < 5; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'X';
					sementara = minimax5(papan, kedalaman + 1, true);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara < best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
}

// Modul untuk mencari posisi terbaik pada papan 5x5
posisi posisiTerbaik5(char papan[5][5])
{
	int best = -1000;
	int sementara;
	int depth = 0;
	posisi posTerbaik;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (papan[i][j] == ' ')
			{
				papan[i][j] = 'O';
				sementara = minimax5(papan, depth, false);

				// meng-undo gerakan yang telah dibuat
				papan[i][j] = ' ';
				if (sementara > best)
				{
					best = sementara;
					posTerbaik.i = i;
					posTerbaik.j = j;
				}
//				printf("%d ", sementara);
			}
		}
	}
	return posTerbaik;
}

// Modul minimax untuk mengecek kemungkinan nilai dari sebuah gerakan
int minimax7(char papan[7][7], int kedalaman, bool maximizing)
{
	int skor = cekPemenang7(papan);
	int kosong = cekKosong7(papan);

	int sementara;
	if (skor == 1)
	{
		return -10;
	}
	else if (skor == 2)
	{
		return 10;
	}
	else if (skor == 3 && kosong == 0)
	{
		return 0;
	}

	if (maximizing)
	{
		int best = -1000000;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'O';
					sementara = minimax7(papan, kedalaman + 1, false);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara > best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000000;
		for (int i = 7; i < 7; i++)
		{
			for (int j = 7; j < 7; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'X';
					sementara = minimax7(papan, kedalaman + 1, true);

					// meng-undo gerakan yang telah dibuat
					papan[i][j] = ' ';
					if (sementara < best)
					{
						best = sementara;
					}
				}
			}
		}
		return best;
	}
}

// Modul untuk mencari posisi terbaik pada papan 7x7
posisi posisiTerbaik7(char papan[7][7], int i_pemain, int j_pemain)
{
	int best = -1000;
	int sementara;
	int depth = 0;
	posisi posTerbaik;
	posisi tempPos[8];

	// #1
	tempPos[0].i = i_pemain - 1;
	tempPos[0].j = j_pemain - 1;
	
	// #2
	tempPos[1].i = i_pemain - 1;
	tempPos[1].j = j_pemain;

	// #3
	tempPos[2].i = i_pemain - 1;
	tempPos[2].j = j_pemain + 1;

	// #4
	tempPos[3].i = i_pemain;
	tempPos[3].j = j_pemain - 1;

	// #5
	tempPos[4].i = i_pemain;
	tempPos[4].j = j_pemain + 1;

	// #6
	tempPos[5].i = i_pemain + 1;
	tempPos[5].j = j_pemain - 1;

	// #7
	tempPos[6].i = i_pemain + 1;
	tempPos[6].j = j_pemain;

	// #8
	tempPos[7].i = i_pemain + 1;
	tempPos[7].j = j_pemain + 1;

	// for (int i=0; i<8; i++) {
	// 	if (tempPos[i].i<0 || tempPos[i].i>6 || tempPos[i].j<0 || tempPos[i].j>6 || papan[tempPos[i].i][tempPos[i].j] == 'O' || papan[tempPos[i].i][tempPos[i].j] == 'X') {
	// 		tempPos[i].i = -1;
	// 		tempPos[i].j = -1;
	// 	}
	// }
	posTerbaik.i = tempPos[0].i;
	posTerbaik.j = tempPos[0].j;

	// for (int i=0; i<8; i++) {
	// 	if (tempPos[i].i != -1 && tempPos[i].j != -1) {
	// 		// papan[tempPos[i].i][tempPos[i].j] == 'O';
	// 		// sementara = minimax7(papan, depth, false);

	// 		// meng-undo gerakan yang telah dibuat
	// 		// papan[tempPos[i].i][tempPos[i].j] = ' ';
	// 		// if (sementara > best)
	// 		// {
	// 			// best = sementara;
	// 			posTerbaik.i = tempPos[i].i;
	// 			posTerbaik.j = tempPos[i].j;
	// 			break;
	// 		// }
	// 	}
	// }

	// for (int i = 0; i < 7; i++)
	// {
	// 	for (int j = 0; j < 7; j++)
	// 	{
	// 		if (papan[i][j] == ' ')
	// 		{
	// 			papan[i][j] = 'O';
	// 			sementara = minimax7(papan, depth, false);

	// 			// meng-undo gerakan yang telah dibuat
	// 			papan[i][j] = ' ';
	// 			if (sementara > best)
	// 			{
	// 				best = sementara;
	// 				posTerbaik.i = i;
	// 				posTerbaik.j = j;
	// 			}
	// 			// printf("%d ", sementara);
	// 		}
	// 	}
	// }
	return posTerbaik;
}
