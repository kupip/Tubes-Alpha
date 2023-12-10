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

// Tipe data posisi agar lebih memudahkan AI
typedef struct
{
	int i, j;
} posisi;

HWND WINAPI GetConsoleWindowNT(void);

void kursorOut(int x, int y);

void tampilanAwal();

void tampilHalaman(int *index_halaman, bool *keluar);

void timer(int x, int y);

// yang ada di tampilHalaman
void banner();
void inputNama(permainan *game, int *index_halaman, int modeMain);
void loadGame(int *index_halaman, permainan *temp_game);
void menuAwal(int *index_halaman, bool *keluar);
void pilihMode(int *index_halaman, int *modeMain);
void pilihPapan(int *index_halaman, int *jenis_papan);
void tampilHighScore(int *index_halaman);
void howToPlay(int *index_halaman);

// Game Utama
void dashboard(Player pemain1, Player pemain2);
void mainGame(permainan *game, char (*pemenang)[20], int *index_halaman);

// Untuk Komputer
int cekPemenang3(char papan[3][3]);
int cekPemenang5(char papan[5][5]);
posisi posisiTerbaik3(char papan[3][3]);
posisi posisiTerbaik5(char papan[5][5]);
posisi posisiTerbaik7(char papan[7][7], int i_pemain, int j_pemain);

// Setelah Game
void menuAkhir(permainan game, char pemenang[20], int *index_halaman, bool *keluar);
void saveGame(permainan game);
void loadGame(int *index_halaman, permainan *game);

// Print Papan
void printPapan3(char papan[3][3]);
void printPapan5(char papan[5][5]);
void printPapan7(char papan[7][7]);

void timer(int x, int y);
// Deklarasi modul untuk 3x3
void main3(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong3(char papan[3][3]);
int cekPemenang3(char papan[3][3]);
void giliran3(char (*papan)[3][3], int *giliran, int modeMain);
void setPapan3(char (*papan)[3][3]);

// Deklarasi modul untuk 5x5
void main5(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong5(char papan[5][5]);
int cekPemenang5(char papan[5][5]);
void giliran5(char (*papan)[5][5], int *giliran, int modeMain);
void setPapan5(char (*papan)[5][5]);

// Deklarasi modul untuk 7x7
void main7(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong7(char papan[7][7]);
int cekPemenang7(char papan[7][7]);
void giliran7(char (*papan)[7][7], int *giliran, int modeMain);
void setPapan7(char (*papan)[7][7]);

// Modul Highscore
void printHighScore(char namapemain[20], int skor, int urutanData, int akhir);
int cekNamaDuplikat(int _awal, char listNama[10000][20], char _namaPlayer[20]);
