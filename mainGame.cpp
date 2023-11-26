/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include "header.h"

void mainGame(permainan game, char *pemenang, int *index_halaman, char papan[][]) {
	setUlangPapan();
	while (pemenang == "" || cekKotakKosong()>0) {
		printPapan(game.jenis_papan);
	}
}

int cekKotakKosong(char papan[][], int jenis_papan) {
	
}
