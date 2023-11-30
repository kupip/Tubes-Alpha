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
int cekKotakKosong();

void mainGame(permainan game, char *pemenang, int *index_halaman) {
	system("cls");
	kursorOut(45, 15);
	printf("p mainGame");
	setUlangPapan();
}

