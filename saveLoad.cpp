/*
File		: saveLoad.cpp
Deskripsi	: Body modul saveGame() dan loadGame() untuk menyimpan dan me-load data permainan.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

void saveGame(permainan game) {
	bool temu=false;
	permainan game_dicari;
	FILE *wr=fopen("data.bin", "ab");
	FILE *cari=fopen("data.bin", "rb");
//	strcpy(game_dicari.pemain1.nama, game.pemain1.nama);
//	strcpy(game_dicari.pemain2.nama, game.pemain2.nama);
//	while (!temu) {
//		fread(&game_dicari, sizeof(permainan), 1, cari);
//		if (strcmp(game_dicari.pemain1.nama, game.pemain1.nama)==0 && strcmp(game_dicari.pemain2.nama, game.pemain2.nama)==0) {
//			fwrite(&game, sizeof(permainan), 1, cari);
//		}
//	}
	fwrite(&game, sizeof(permainan), 1, wr);
	fclose(wr);
}

void loadGame(int *index_halaman, permainan *game) {
	int i, idx_save;
	FILE *re=fopen("data.bin", "rb");
	
	i=0;
//	system("cls");
	while(!feof(re)) {
		i++;
		printf("%d\n", feof(re));
		fread(&(*game), sizeof(permainan), 1, re);
		printf("Data %d\n", i);
		printf("Jenis Papan: %d\n", (*game).jenis_papan);
		printf("Mode main: %d\n", (*game).modeMain);
		printf("Nama Pemain 1: %s\n", (*game).pemain1.nama);
		printf("Skor Pemain 1: %d\n", (*game).pemain1.skor);
		printf("Nama Pemain 2: %s\n", (*game).pemain2.nama);
		printf("Skor Pemain 2: %d\n\n", (*game).pemain2.skor);
	}
	printf("Pilih data yang ingin anda lanjutkan (Ketik 0 untuk kembali)\n=>");
	scanf("%d", &idx_save);
	if (idx_save > i) {
		printf("Data yang anda pilih tidak valid");
		sleep(1);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                ");
	} else if(idx_save == 0){
		*index_halaman = 1;
		system("cls");
	} else {
		rewind(re);
		for (i=1; i<=idx_save; i++) {
			fread(&(*game), sizeof(permainan), 1, re);
		}
		*index_halaman=7;
	}
	fclose(re);
	system("cls");
}
