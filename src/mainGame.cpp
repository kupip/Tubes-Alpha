/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include <unistd.h>
#include <process.h>

#include "header.h"

void mainGame(permainan *game, char (*pemenang)[20], int *index_halaman)
{
	switch (game->jenis_papan)
	{
	case 3:
		main3(game, pemenang, index_halaman);
		break;
	case 5:
		main5(game, pemenang, index_halaman);
		break;
	case 7:
		main7(game, pemenang, index_halaman);
		break;
	}
}