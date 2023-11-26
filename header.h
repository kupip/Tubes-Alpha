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

typedef struct {
	int jenis_papan;
	char modeMain[10];
	Player pemain1;
	Player pemain2;
} permainan;

void kursorOut(int x, int y);

void tampilanAwal();

void tampilHalaman(int *index_halaman);

// yang ada di tampilHalaman
void tampilMenuAwal(int *index_halaman);
void pilihMode(int *index_halaman, char *modeMain);
void pilihPapan(int *index_halaman, int jenis_papan);
void inputNama(int *index_halaman, Player *pemain);


void dashboard(Player pemain1, Player pemain2);

const char *cekPemenang(char papan[][5], int _jenisPapan);

void printPapan(int hasilPilihPapan);

void tampilMenuAkhir(const char *pemenang);
