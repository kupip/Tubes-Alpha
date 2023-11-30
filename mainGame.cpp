/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include "header.h"

const char *cekPemenang(char papan[][5], int jenis_papan);
void setUlangPapan();
int cekKosong3(char papan[3][3]);
void main3x3(permainan game);

void mainGame(permainan game, char *pemenang, int *index_halaman) {
	switch(game.jenis_papan) {
		case 3:
			main3x3(game);
		case 5:
			main5x5(game);
		case 7:
			main7x7(game);
	}
}

void main3x3(permainan game) {
	char papan[3][3] = {{'', '', ''},
						{'', '', ''},
						{'', '', ''}};
	printPapan3(papan);
	do {
		printPapan3(papan);
		giliran1(papan);
	} while (pemenang == '' || cekKosong3(papan) != 0);
}

