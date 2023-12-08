/*
File		: miniMax.cpp
Deskripsi	: Body modul minimax() untuk menemukan gerakan terbaik bagi komputer.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/
#include <stdio.h>
#include <stdbool.h>
#include "header.h"
//#include "mainGame.cpp"
					

// Modul minimax untuk mengecek kemungkinan nilai dari sebuah gerakan
int minimax3(char papan[3][3], int kedalaman, bool maximizing) {
	int skor = cekPemenang3(papan);
	int sementara, best;
	if (skor == 1) {
		return -1;
	}
	else if (skor == 2) {
		return 1;
	}
	else if (skor == 3) {
		return 0;
	}
	
	if (maximizing)
	{
		int best = -1000;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'O';
					sementara = minimax3(papan, kedalaman+1, false);
					
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
	} else {
		int best = 1000;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (papan[i][j] == ' ')
				{
					papan[i][j] = 'X';
					sementara = minimax3(papan, kedalaman+1, true);
					
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

// Modul untuk mencari posisi papan terbaik
posisi posisiTerbaik3(char papan[3][3], int giliran) {
	int best = -1000;
	int sementara;
	int depth = 0;
	posisi posTerbaik;

	// Menguji setiap posisi yang mungkin
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (papan[i][j] == ' ') {
				papan[i][j] = 'O';
				sementara = minimax3(papan, depth, false);
				
				// meng-undo gerakan yang telah dibuat
				papan[i][j] = ' ';
				if (sementara > best) {
					best = sementara;
					posTerbaik.i = i;
					posTerbaik.j = j;
				}
			}
		}
	}
	return posTerbaik;
}
