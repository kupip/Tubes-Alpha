/*
File		: inputNama.cpp
Deskripsi	: Body modul inputNama() untuk menerima input nama player dari pengguna
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 25/11/2023
*/

#include <stdio.h>
#include <windows.h>
#include "header.h"

void inputNama(permainan *game, int *index_halaman, int modeMain) {
	system("cls");
	const char *tempNama;
	if (modeMain == 1) {
		kursorOut(45, 21);
		printf("Masukkan nama anda: ");
		scanf("%s", (*game).pemain1.nama);
		*index_halaman = 7;
//		strcpy((*game).pemain1.nama, tempNama);
		strcpy((*game).pemain2.nama, "Computer"); 
	} else {
		kursorOut(45, 21);
		printf("Masukkan nama Player 1: ");
		scanf("%s", (*game).pemain1.nama);
//		strcpy((*game).pemain1.nama, tempNama);
		fflush(stdin);
		kursorOut(45, 21);
		printf("Masukkan nama Player 2: ");
		scanf("%s", (*game).pemain2.nama);
//		strcpy((*game).pemain2.nama, tempNama);
		*index_halaman = 7;
	}
	
}
