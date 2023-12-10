/*
File		: timer.cpp
Deskripsi	: Body modul timer() untuk menjalankan pewaktu.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 10/12/2023
*/
#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"
// Modul pewaktu pengisian
void timer(int x, int y)
{
	kursorOut(73, 2);
	int time = 10;
	printf("Waktu: %d", time);
	kursorOut(x, y);
	Sleep(1000);
	time--;
	while (!kbhit() && time >= 0)
	{
		kursorOut(73, 2);
		printf("\b ");
		printf("Waktu: %d ", time);
		kursorOut(x, y); // balik ke samping kanan teks Masukkan nomor papan
		time--;
		Sleep(1000);
	}
}
