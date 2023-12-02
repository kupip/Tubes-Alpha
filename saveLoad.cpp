/*
File		: saveLoad.cpp
Deskripsi	: Body modul saveGame() dan loadGame() untuk menyimpan dan me-load data permainan.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include <string.h>
#include "header.h"

void saveGame(permainan game) {
	FILE *wr=fopen("data.txt", "a");
	fprintf(wr, "%d-%d-%s-%d-%s-%d\n", game.jenis_papan, game.modeMain, game.pemain1.nama, game.pemain1.skor, game.pemain2.nama, game.pemain2.skor);
}

void loadGame(permainan *game) {
	char *tempNamaP1;
	char *tempNamaP2;
	FILE *re=fopen("data.txt", "r");
	fscanf(re, "%d-%d-%[^-]-%d-%[^-]-%d\n", &(*game).jenis_papan, &(*game).modeMain, (*game).pemain1.nama, &(*game).pemain1.skor, (*game).pemain2.nama, &(*game).pemain2.skor);
}
