/*
File		: kursorOut.cpp
Deskripsi	: Body modul kursorOut() untuk pemosisian kursor sebelum print
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/

#include <stdio.h>
#include "header.h"
#include <windows.h>

void kursorOut(int x, int y) {
	COORD p;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = x;
	p.Y = y;
	SetConsoleCursorPosition(hOut, p);
}
