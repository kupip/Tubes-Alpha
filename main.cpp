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
#include "dashboard.cpp"

int main(int argc, char** argv) {
	Player _tempPlayer1, _tempPlayer2;
	int jwb;
	
	tampilanAwal();
	jwb = getch();
	system("cls");
	
	inputNama(&_tempPlayer1);
	while (jwb != 27) {
		dashboard(_tempPlayer1, _tempPlayer2);
		jwb = getch();
	}
	return 0;
}
