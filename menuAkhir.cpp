/*
File		: menuAkhir.cpp
Deskripsi	: Body modul menuAkhir() untuk menampilkan menu akhir setelah permainan berakhir.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 25/11/2023
*/

#include <stdio.h>
#include "header.h"
#include <windows.h>

void menuAkhir(const char *pemenang, int *index_halaman, bool *keluar) {
	if (pemenang == "") {
		kursorOut(50, 5);
		printf("DRAW");
		kursorOut(45, 7);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		kursorOut(45, 8);
		printf("%c CONTINUE %c", 185, 185);
		kursorOut(45, 9);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 184);
		kursorOut(45, 10);
		printf("%c SAVE GAME %c", 185, 185);
		kursorOut(45, 11);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 184);
		kursorOut(45, 10);
		printf("%c BACK TO MENU %c", 185, 185);
	}
}
