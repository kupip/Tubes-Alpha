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
	permainan game;
	bool keluar=false;
	int idx_halaman=1;
	tampilanAwal();
	do {
		tampilHalaman(&idx_halaman, &keluar);
	} while (!keluar);
	
	return 0;
}