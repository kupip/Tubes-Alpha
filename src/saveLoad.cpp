/*
File		: saveLoad.cpp
Deskripsi	: Body modul saveGame() dan loadGame() untuk menyimpan dan me-load data permainan.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void saveGame(permainan game)
{
	int i;
	permainan game_dicari;
	FILE *wr = fopen("data.bin", "r+b");

	if (!wr)
	{
		wr = fopen("data.bin", "w+b");
		if (!wr)
		{
			perror("File opening failed");
			return;
		}
	}

	i = 0;

	while (fread(&game_dicari, sizeof(permainan), 1, wr) == 1)
	{
		if (strcmp(game_dicari.pemain1.nama, game.pemain1.nama) == 0 && strcmp(game_dicari.pemain2.nama, game.pemain2.nama) == 0)
			break;
		i++;
	}

	fseek(wr, i * sizeof(permainan), SEEK_SET);
	fwrite(&game, sizeof(permainan), 1, wr);
	fclose(wr);
}

void loadGame(int *index_halaman, permainan *game)
{
	int i, n, idx_save;
	FILE *re = fopen("data.bin", "rb");

	if (!re)
	{
		printf("File gagal dibuka.\n");
		printf("Tekan apapun untuk kembali!!\n");
		getchar();
		*index_halaman = 1;
		system("cls");
		return;
	}

	i = 0;
	while (fread(game, sizeof(permainan), 1, re) == 1)
		i++;
	n = i;

	rewind(re);

	for (i = 1; i <= n; i++)
	{
		fread(game, sizeof(permainan), 1, re);
		printf("Data %d\n", i);
		printf("Jenis Papan: %d\n", game->jenis_papan);
		printf("Mode main: %d\n", game->modeMain);
		printf("Nama Pemain 1: %s\n", game->pemain1.nama);
		printf("Skor Pemain 1: %d\n", game->pemain1.skor);
		printf("Nama Pemain 2: %s\n", game->pemain2.nama);
		printf("Skor Pemain 2: %d\n\n", game->pemain2.skor);
	}

	printf("Pilih data yang ingin anda lanjutkan (Ketik 0 untuk kembali)\n=> ");
	scanf("%d", &idx_save);

	if (idx_save < 0 || idx_save > n)
	{
		printf("Data yang anda pilih tidak valid\n");
		Sleep(2);
		printf("\r                                \r");
	}
	else if (idx_save == 0)
	{
		*index_halaman = 1;
		system("cls");
	}
	else
	{
		rewind(re);
		for (i = 1; i <= idx_save; i++)
		{
			fread(game, sizeof(permainan), 1, re);
		}
		*index_halaman = 7;
	}

	fclose(re);
	system("cls");
}