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

void tampilHalaman(int *index_halaman, permainan game, bool *keliar);

// yang ada di tampilHalaman
void tampilMenuAwal(int *index_halaman, bool *keluar);
void pilihMode(int *index_halaman, char *modeMain);
void pilihPapan(int *index_halaman, int jenis_papan);
void inputNama(int *index_halaman, Player *pemain);
void mainGame(permainan game, char *pemenang, int *index_halaman, char *papan);
void tampilMenuAkhir(const char *pemenang, int *index_halaman, bool *keluar);
void dashboard(Player pemain1, Player pemain2);
int cekKotakKosong(); // keknya ga perlu di declare di sini

// dipake di mainGame
const char *cekPemenang(char papan[][5], int jenis_papan);
void printPapan(int hasilPilihPapan);
void setUlangPapan();
int cekKotakKosong(char papan[][7], int jenis_papan);

void tampilMenuAkhir(const char *pemenang);
