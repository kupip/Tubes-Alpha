/*
File		: header.h
Deskripsi	: Header Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/

typedef struct {
	char nama[50];
	int skor;
} Player;

void kursorOut(int x, int y);

void tampilanAwal();

void dashboard(Player pemain1, Player pemain2);

void inputNama(Player *pemain1);

const char *cekPemenang(char papan[][5], int _jenisPapan);

void tampilMenuAkhir();
