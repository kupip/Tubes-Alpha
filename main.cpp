/*
File		: main.cpp
Deskripsi	: Driver utama Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header.h"

int main(int argc, char** argv) {
//	Player _tempPlayer1, _tempPlayer2;
//	int jwb;
//	
	idx_halaman = 1;
	tampilanAwal();
	do {
		tampilHalaman(&idx_halaman);
	} while (keluar == false)
//	jwb = getch();
//	system("cls");
//	
//	inputNama(&_tempPlayer1);
//	system("cls");
	const char *dem = "";
	tampilMenuAkhir(dem);
	int jwb = getch();
	while (jwb != 27) {
//		dashboard(_tempPlayer1, _tempPlayer2);
		jwb = getch();
	}
	return 0;
}
