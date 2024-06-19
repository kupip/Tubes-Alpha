/*
File		: computer.cpp
Deskripsi	: Body modul minimax() untuk menemukan gerakan terbaik bagi komputer.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

// https://www.geeksforgeeks.org/finding-optimal-move-in-tic-tac-toe-using-minimax-algorithm-in-game-theory/
// Modul minimax untuk mengecek kemungkinan nilai dari sebuah gerakan
int minimax3(char papan[3][3], bool maximizing)
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
					sementara = minimax3(papan, false);

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
					sementara = minimax3(papan, true);

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
					sementara = minimax3(papan, false);

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

// Modul untuk mencari posisi terbaik pada papan 5x5
posisi posisiTerbaik5(char papan[5][5], int i_pemain, int j_pemain)
{
	int i, j, count, r;
	posisi posTerbaik5;
	posisi tempPos[8];

	/*
	1|2|3
	-----
	4|X|5
	-----
	7|6|8
	*/

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
	
	i=0;
	count = 0;
	while (i<8) {
		if (tempPos[i].i<0 || tempPos[i].i>6 || tempPos[i].j<0 || tempPos[i].j>6 || papan[tempPos[i].i][tempPos[i].j] == 'O' || papan[tempPos[i].i][tempPos[i].j] == 'X') {
			tempPos[i].i = -1;
			tempPos[i].j = -1;
		} else {
			count++;
		}
		i++;
	}

	// posisi posSah[count];
	posisi *posSah=new posisi[count];
	j=0;
	for (int idx=0; i<count; idx++) {
		while (j<8) {
			if (tempPos[j].i != -1 && tempPos[j].j != -1) {
				posSah[idx].i = tempPos[j].i;
				posSah[idx].j = tempPos[j].j;
				j++;
				break;
			} else {
				j++;
			}
		}
	}
	srand(0);
	r = rand()%count;
	posTerbaik5.i = posSah[r].i;
	posTerbaik5.j = posSah[r].j;
	return posTerbaik5;
}

// Modul untuk mencari posisi terbaik pada papan 7x7
posisi posisiTerbaik7(char papan[7][7], int i_pemain, int j_pemain)
{
	int i, j, count;
	posisi posTerbaik7;
	posisi tempPos[8];

	/*
	1|2|3
	-----
	4|X|5
	-----
	7|6|8
	*/

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
	
	i=0;
	count = 0;
	while (i<8) {
		if (tempPos[i].i<0 || tempPos[i].i>6 || tempPos[i].j<0 || tempPos[i].j>6 || papan[tempPos[i].i][tempPos[i].j] == 'O' || papan[tempPos[i].i][tempPos[i].j] == 'X') {
			tempPos[i].i = -1;
			tempPos[i].j = -1;
		} else {
			count++;
		}
		i++;
	}

	// posisi posSah[count];
	posisi *posSah=new posisi[count];
	j=0;
	for (int idx=0; idx<count; idx++) {
		while (j<8) {
			if (tempPos[j].i != -1 && tempPos[j].j != -1) {
				posSah[idx].i = tempPos[j].i;
				posSah[idx].j = tempPos[j].j;
				j++;
				break;
			} else {
				j++;
			}
		}
	}
	srand(0);
	int r = rand()%count;
	posTerbaik7.i = posSah[r].i;
	posTerbaik7.j = posSah[r].j;
	return posTerbaik7;
}
