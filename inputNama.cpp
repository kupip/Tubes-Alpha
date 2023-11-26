/*
File		: inputNama.cpp
Deskripsi	: Body modul inputNama() untuk menerima input nama player dari pengguna
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 25/11/2023
*/

#include <stdio.h>
#include <windows.h>
#include "header.h"

void inputNama(int *index_halaman, Player *pemain1) {
	kursorOut(45, 21);
	printf("Masukkan nama anda: ");
	scanf("%s", &(*pemain1).nama);
}
