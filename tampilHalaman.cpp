/*
File		: tampilHalaman.cpp
Deskripsi	: Body modul tampilHalaman() untuk menampilkan halaman berdasarkan index halaman yang bersesuaian.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/
#include <stdio.h>
#include "header.h"

void tampilHalaman(int *index_halaman, bool *keluar) {
	permainan temp_game;
	char pemenang[20];
	Player high_score[20];
	
	switch(*index_halaman) {
		case 1: // menu awal
			menuAwal(&(*index_halaman), &(*keluar));
			break;
		case 2: // pilih opsi load game
			loadGame(&(*index_halaman), &temp_game);
			break;
		case 3: // pilih opsi high score
			tampilHighScore(&(*index_halaman));
			break;
		case 4: // input Nama player kalo pilih mode vs komputer
			pilihMode(&(*index_halaman), &temp_game.modeMain);
			break;
		case 5: // buat milih jenis papan
			pilihPapan(&(*index_halaman), &temp_game.jenis_papan);
			break;
		case 6:
			inputNama(&temp_game, &(*index_halaman), temp_game.modeMain); 
			break;
		case 7:
			mainGame(&temp_game, &pemenang, &(*index_halaman));
			break;
		case 8:
			menuAkhir(temp_game, pemenang, &(*index_halaman), &(*keluar));
			break;
	};
}
