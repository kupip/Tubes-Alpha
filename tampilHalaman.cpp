/*
File		: tampilHalaman.cpp
Deskripsi	: Body modul tampilHalaman() untuk menampilkan halaman berdasarkan index halaman yang bersesuaian.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/
#include <stdio.h>
#include "header.h"

void tampilHalaman(int *index_halaman, permainan *temp_game, bool *keluar) {
	char pemenang[10];
	switch(*index_halaman) {
		case 1: // menu awal;
			tampilMenuAwal(*index_halaman, &keluar);
			break;
		case 2: // pilih opsi start
			pilihMode(*index_halaman, temp_game.modeMain);
			break;
		case 3: // pilih papan
			pilihPapan(*index_halaman, *temp_game.jenis_papan);
			break;
		case 4: //input Nama player kalo pilih mode vs komputer
			if (temp_game.modeMain == "Komputer") {
				inputNama(*temp_game.pemain1);
				strcpy(temp_game.pemain2.nama, "Komputer");
			} else {
				inputNama(*temp_game.pemain1);
				inputNama(*temp_game.pemain2);
			}
			break;
		case 5:
			while (pemenang == "" || cekKotakKosong() > 0) {
				mainGame(&(*temp_game), pemenang, &index_halaman);
			}
			break;
		case 6:
			tampilMenuAKhir(pemenang, &index_halaman, &keluar);
			break;
	};
}
