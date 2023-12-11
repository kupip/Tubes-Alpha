/*
File		: tampilHighScore.cpp
Deskripsi	: Body modul tampilHighScore() untuk menampilkan daftar high score.
Dibuat oleh	: Nadia Rachma Yuninda / 231524017
Tgl			: 08/12/2023
*/
#include <stdio.h>
#include "header.h"
#include <string.h>

void tampilHighScore(int *index_halaman)
{
	FILE *file1;
	Player pemain[10000];
	Player pemainTampil[10000];
	Player tempPlayer;
	permainan tempGame;
	char listNama[10000][20];

	// mengambil data dari file
	file1 = fopen("data.bin", "rb");
	if (file1 == NULL)
	{
		system("cls");
		banner();

		printf("\n\tData is empty");
		printf("\n\tPress any button to back");

		fclose(file1);
		int butt = getch();
	}
	else
	{
		// menyalin nama dan score
		int i = 0;
		while (fread(&tempGame, sizeof(permainan), 1, file1))
		{
			strcpy(pemain[i].nama, tempGame.pemain1.nama);
			pemain[i].skor = tempGame.pemain1.skor;
			strcpy(pemain[i + 1].nama, tempGame.pemain2.nama);
			pemain[i + 1].skor = tempGame.pemain2.skor;
			i += 2;
		}
		fclose(file1);

		// mengecek nama yang sama
		int awal = 0;
		for (int k = 0; k < i; k++)
		{
			for (int j = 0; j < i; j++)
			{
				if (cekNamaDuplikat(awal, listNama, pemain[k].nama) == 0)
				{
					strcpy(listNama[awal], pemain[k].nama);
					awal++;
				}
			}
		}

		// menjumlahkan score pada nama yang sama
		int data = 0;
		bool ada = false;
		for (int j = 0; j < awal; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (strcmp(listNama[j], pemain[k].nama) == 0)
				{
					strcpy(pemainTampil[data].nama, pemain[k].nama);
					pemainTampil[data].skor += pemain[k].skor;
					ada = true;
				}
			}
			if (ada == true)
				data++;
			ada = false;
		}

		for (int j = 0; j < data; j++)
		{
			for (int k = 0; k < data - 1; k++)
			{
				if (pemainTampil[k].skor < pemainTampil[k + 1].skor)
				{
					tempPlayer = pemainTampil[k];
					pemainTampil[k] = pemainTampil[k + 1];
					pemainTampil[k + 1] = tempPlayer;
				}
			}
		}

		if (data > 5)
		{
			data = 5;
		}

		system("cls");
		banner();
		kursorOut(47, 10);
		printf(" TOP 5 skor terbesar");
		for (int j = 0; j < data; j++)
		{
			printHighScore(pemainTampil[j].nama, pemainTampil[j].skor, j, data);
		}
		kursorOut(10, 32);
		printf("Press any key to back to menu...");
		if (getch())
		{
			*index_halaman = 1;
		}
		system("cls");
	}
}

int cekNamaDuplikat(int _awal, char listNama[10000][20], char _namaPlayer[20])
{
	for (int b = 0; b <= _awal; b++)
	{
		if (strcmp(_namaPlayer, listNama[b]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void printHighScore(char namapemain[20], int skor, int urutanData, int akhir)
{

	int titiky = 12;
	titiky = titiky + urutanData * 2;
	if (urutanData == 0)
	{
		kursorOut(37, titiky);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		kursorOut(37, titiky + 1);
		printf("%c %s", 186, namapemain);
		if (skor > 9)
		{
			kursorOut(77, titiky + 1);
			printf("%c %d %c", 186, skor, 186);
		}
		else
		{
			kursorOut(77, titiky + 1);
			printf("%c  %d %c", 186, skor, 186);
		}
	}
	else if (urutanData == (akhir - 1))
	{
		kursorOut(37, titiky + 1);
		printf("%c %s", 186, namapemain);
		if (skor > 9)
		{
			kursorOut(77, titiky + 1);
			printf("%c %d %c", 186, skor, 186);
		}
		else
		{
			kursorOut(77, titiky + 1);
			printf("%c  %d %c", 186, skor, 186);
		}
		kursorOut(37, titiky + 2);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}
	else
	{
		kursorOut(37, titiky);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		kursorOut(37, titiky + 1);
		printf("%c %s", 186, namapemain);
		if (skor > 9)
		{
			kursorOut(77, titiky + 1);
			printf("%c %d %c", 186, skor, 186);
		}
		else
		{
			kursorOut(77, titiky + 1);
			printf("%c  %d %c", 186, skor, 186);
		}
		kursorOut(37, titiky + 2);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	}
}
