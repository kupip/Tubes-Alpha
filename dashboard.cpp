/*
File		: dashboard.cpp
Deskripsi	: Body modul dashboard() untuk menampilkan dashboard yang berisi nama player, timer, dan skor sementara
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/

#include <stdio.h>
#include <windows.h>
#include "header.h"

void dashboard(Player pemain1, Player pemain2) {
//	system("cls");
	kursorOut(5, 12); printf("%s", pemain1.nama);
	kursorOut(5, 13); printf("%d", pemain1.skor);
	
	kursorOut(25, 12); printf("%s", pemain2.nama);
	kursorOut(25, 13); printf("%d", pemain2.skor);
}
