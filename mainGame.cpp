/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include "header.h"

// Deklarasi modul untuk 3x3
int cekKosong3(char papan[3][3]);
const char *cekPemenang3(char papan[3][3], permainan game);
void giliran3(char (*papan)[3][3], int *giliran);
void main3(permainan game);

// Deklarasi modul untuk 5x5
void main5(permainan game);


void mainGame(permainan game, char *pemenang, int *index_halaman) {
	switch(game.jenis_papan) {
		case 3:
			main3(game);
		case 5:
			main5(game);
		case 7:
			main7(game);
	}
}

void main3(permainan game) {
	char papan[3][3] = {{' ', ' ', ' '},
						{' ', ' ', ' '},
						{' ', ' ', ' '}};
	while (pemenang == ' ' || cekKosong3(papan) != 0) {
		printPapan3(papan);
		giliran1_3(&papan);
		pemenang = cekPemenang3(game);
		giliran2_3(&papan);
	}
}

void giliran3(char (*papan)[3][3], int *giliran) {
	int n, i, j;
	kursorOut(68,19);
	printf("Giliran pemain %d", *giliran);
	kursorOut(68,21);
	printf("Masukkan nomor papan: ");
	scanf("%d", &n);
	printf("\b ");
	switch(n) {
		case 1:
			i = 0;
			j = 0;
			break;
		case 2:
			i = 0;
			j = 1;
			break;
		case 3:
			i = 0;
			j = 2;
			break;
		case 4:
			i = 1;
			j = 0;
			break;
		case 5:
			i = 1;
			j = 1;
			break;
		case 6:
			i = 1;
			j = 2;
			break;
		case 7:
			i = 2;
			j = 0;
			break;
		case 8:
			i = 2;
			j = 1;
			break;
		case 9:
			i = 2;
			j = 2;
			break;
	}
	
	if ((*papan)[i][j] == ' ' && *giliran == 1) {
		(*papan)[i][j] = 'X';
		*giliran = 2;
	} else if ((*papan)[i][j] == ' ' && *giliran = 2){
		(*papan)[i][j] = 'O';
		giliran = 1;
	} else {
		kursorOut(68,23);
		printf("kotak sudah terisi");
	}
}

const char *cekPemenang3(char papan[3][3], permainan game) {
	if ((papan[0][0] == 'X' && papan[0][0] == papan[0][1] && papan[0][0] == papan[0][2]) ||
		(papan[1][0] == 'X' && papan[1][0] == papan[1][1] && papan[1][0] == papan[1][2]) ||
		(papan[2][0] == 'X' && papan[2][0] == papan[2][1] && papan[2][0] == papan[2][2])) {
		return game.pemain1.nama;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (papan)
		}
	}
}

void main5(permainan game) {
	system("cls");
	kursorOut(45, 19);
	printf("p main 5x5");
}
