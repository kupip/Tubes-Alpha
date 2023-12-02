/*
File		: header.h
Deskripsi	: Header Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

typedef struct
{
	char nama[20];
	int skor;
} Player;

typedef struct
{
	int jenis_papan;
	int modeMain;
	Player pemain1;
	Player pemain2;
} permainan;

HWND WINAPI GetConsoleWindowNT(void);

void kursorOut(int x, int y);

void tampilanAwal();


void tampilHalaman(int *index_halaman, bool *keluar);

// yang ada di tampilHalaman
void menuAwal(int *index_halaman, bool *keluar);
void tampilHighScore(int *index_halaman);
void loadGame(int *index_halaman, permainan *temp_game);

void pilihMode(int *index_halaman, int *modeMain);
void pilihPapan(int *index_halaman, int *jenis_papan);
void inputNama(permainan *game, int *index_halaman, int modeMain);

void mainGame(permainan temp_game, char (*pemenang)[20], int *index_halaman);

void menuAkhir(char pemenang[20], int *index_halaman, bool *keluar);
void dashboard(Player pemain1, Player pemain2);
int cekKotakKosong(); // keknya ga perlu di declare di sini

// dipake di mainGame
void tampilMenuAkhir(const char *pemenang);

// print papan
void printPapan3(char papan[3][3]);
void pintPapan5(char papan[5][5]);
void printPapan7(char papan[7][7]);
