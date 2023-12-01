/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include "header.h"
char papan[3][3] = {{' ', ' ', ' '},
					{' ', ' ', ' '},
					{' ', ' ', ' '}};

// Deklarasi modul untuk 3x3
int cekKosong3(char papan[3][3]);
const char *cekPemenang3(char papan[3][3], permainan *game);
void giliran3(char papan[3][3], int *turn);
void main3(permainan game, char (*pemenang)[20]);

// Deklarasi modul untuk 5x5
void main5(permainan game);
void main7(permainan game);

void mainGame(permainan game, char (*pemenang)[20], int *index_halaman) {
//	system("cls");
	switch(game.jenis_papan) {
		case 3:
			main3(game, &(*pemenang));
			break;
		case 5:
			main5(game);
			break;
		case 7:
			main7(game);
			break;
	}
//	*index_halaman = 8;
}

void main3(permainan game, char (*pemenang)[20]) {
	
	while (*pemenang == " " || cekKosong3(papan) != 0) {
		int turn=1;
		printPapan3(papan);
		giliran3(papan, &turn);
		
		if (*pemenang != " " || cekKosong3(papan) == 0) {
			break;
		}

		if (*pemenang != " " || cekKosong3(papan) == 0) {
			break;
		}
	}
}

void giliran3(char papan[3][3], int *giliran) {
	int n, i, j;
	kursorOut(68,19);
	printf("Giliran pemain");
	kursorOut(68,21);
	printf("Masukkan nomor papan: ");
	scanf("%d", &n);
	i=(n-1)/3;
	j=(n-1)%3;
	printf("\b ");
	
	if (papan[i][j] == ' ' && *giliran == 1) {
		papan[i][j] = 'X';
		*giliran = 2;
	} else if (papan[i][j] == ' ' && *giliran == 2){
		papan[i][j] = 'O';
		printf("%d", *giliran);
		*giliran = 1;
	} else {
		kursorOut(68,23);
		printf("kotak sudah terisi");
	}
}

int cekKosong3(char papan[3][3]) {
	int count=0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (papan[i][j]==' ') {
				count++;
			}
		}
	}
}


int cekPemenang3(char papan[3][3], permainan *game) {
	for(int baris = 0;baris<3;baris++){
		if(papan[baris][0] == papan[baris][1] && papan[baris][1] == papan[baris][2]{
			if (papan[baris][1] == 'X' && papan[baris][2] == 'X'){
				return 1;
			} else  if ((papan[baris][1] == 'O' && papan[baris][2] == 'O')){
				return 2;
			}
		}
	}
	
	for(int kolom = 0;kolom<3;kolom++){
		if(papan[0][kolom] == papan[1][kolom] && papan[1][kolom] == papan[2][kolom]){
			if(papan[1][kolom] == 'X' && papan[2][kolom] == 'X'){
				return 1;
			} else if(papan[0][kolom] == papan[1][kolom] && papan[1][kolom] == papan[2][kolom]){
				return 2;
			}
		}
	}

	if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] ||  ) {
		if (papan[1][1] == 'X' && papan[2][2] == 'X'){
			return 1;
		} else if (papan[1][1] == 'O' && papan[2][2] == 'O'){
			return 2;
		}
		
	}
	if (papan[0][2] == papan[1][1] && papan[0][2] == papan[2][1]){
		if(papan[1][1] == 'X' && papan[2][1] == 'X'){
			return 1;
		} else if (papan[1][1] == 'O' && papan[2][1] == 'O'){
			return 2;
		}
	}
}

void main5(permainan game) {
	system("cls");
	kursorOut(45, 19);
	printf("p main 5x5");
}

void main7(permainan game) {
	system("cls");
	kursorOut(45, 19);
	printf("p main 7x7");
}
