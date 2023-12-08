/*
File		: inputNama.cpp
Deskripsi	: Body modul inputNama() untuk menerima input nama player dari pengguna
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 25/11/2023
*/

#include <stdio.h>
#include <windows.h>
#include "header.h"

void inputNama(permainan *game, int *index_halaman, int modeMain)
{
	system("cls");
	if (modeMain == 1)
	{
		banner();
		kursorOut(45, 21);
		printf("Masukkan nama anda: ");
		scanf("%[^\n]", (*game).pemain1.nama);
		(*game).pemain1.skor = 0;
		strcpy((*game).pemain2.nama, "Computer");
		(*game).pemain2.skor = 0;
		*index_halaman = 7;
	}
	else
	{
		banner();
		switch ((*game).jenis_papan)
		{
		case 3:
			kursorOut(45, 20);
			printf("Papan 3x3");
			break;
		case 5:
			kursorOut(45, 20);
			printf("Papan 5x5");
			break;
		case 7:
			kursorOut(45, 20);
			printf("Papan 7x7");
			break;
		}
		kursorOut(45, 21);
		printf("Masukkan nama Player 1: ");
		scanf("%[^\n]", (*game).pemain1.nama);;
		(*game).pemain1.skor = 0; // pemberian nilai awal buat skor biar ga kebawa skor yg lalu lalu
		
		fflush(stdin);
		system("cls");

		banner();
		switch ((*game).jenis_papan)
		{
		case 3:
			kursorOut(45, 20);
			printf("Papan 3x3");
			break;
		case 5:
			kursorOut(45, 20);
			printf("Papan 5x5");
			break;
		case 7:
			kursorOut(45, 20);
			printf("Papan 7x7");
			break;
		}
		kursorOut(45, 21);
		printf("Masukkan nama Player 2: ");
		scanf("%[^\n]", (*game).pemain2.nama);
		(*game).pemain2.skor = 0;
		*index_halaman = 7;
	}
	fflush(stdin);
	system("cls");
}
