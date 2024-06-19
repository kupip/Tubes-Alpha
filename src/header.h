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

// Record untuk identitas pemain dan skor
typedef struct
{
	char nama[20];
	int skor;
} Player;

// Record untuk permainan
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

void kursorOut(int x, int y);
/*
	Modul untuk memindahkan pointer ke koordinat yang diinginkan.
	I.S: Pointer berjalan sequence di titik terakhir.
	F.S:Pointer berpindah ke koordinat yang diinginkan.
*/

void tampilanAwal();
/*
	Modul  untuk menampilkan halaman pembuka saat program pertama kali di jalankan
	I.S: halaman pembuka belum ditampilkan
	F.S: halaman pembuka sudah ditampilkan ke layar
*/

void tampilHalaman(int *index_halaman, bool *keluar);
/*
	Modul untuk menampilkan halaman pada console tergantung indeks halaman tertentu.
	I.S: halaman belum tampil sesuai dengan indeks yang telah ditentukan
	F.S: halaman sudah tampil sesuai dengan indeks yang sudah ditentukan
*/

void timer(int x, int y);
/*
	Modul untuk menghitung mundur waktu yang pemain peroleh di setiap giliran
	I.S: Waktu dimulai dari 10
	F.S: Terus berkurang sampai 0 dan berubah giliran
*/

/*+---------------------------------------------------------------+*/
/*|                  YANG ADA DI TAMPILAN HALAMAN                 |*/
/*+---------------------------------------------------------------+*/
void banner();
/*
	Modul  untuk menampilkan banner game Tic-Tac-Toe pada setiap halaman game.
	I.S: Banner belum ditampilkan ke layar
	F.S: Banner sudah ditampilkan ke layar
*/

void inputNama(permainan *game, int *index_halaman, int modeMain);
/*
	Modul untuk meng-input nama player yang akan bermain
	I.S: Nama player masih tak tentu
	F.S: Nama player sudah terisi dengan hasil masukan dari keyboard
*/

void loadGame(int *index_halaman, permainan *temp_game);
/*
	Modul untuk melanjutkan permainan yang sudah di save sebelumnya.
	I.S: Variabel game di main belum terisi data yang di load
	F.S: Variabel game di main sudah terisi data yang di load
*/

void menuAwal(int *index_halaman, bool *keluar);
/*
	Modul untuk menampilkan menu awal
	I.S: Menu awal belum ditampilkan ke layar
	F.S: Menu awal, dengan pilihan start game, load game, dan exit sudah ditampilkan dengan pilihan menu.
*/

void pilihMode(int *index_halaman, int *modeMain);
/*
	Modul untuk menampilkan mode (1 player dan 2 player) apa saja yang bisa dipilih oleh pengguna.
	I.S: Mode yang dapat dipilih belum ditampilkan ke layar
	F.S: Mode yang dapat dipilih sudah ditampilkan ke layar
*/

void pilihPapan(int *index_halaman, int *jenis_papan);
/*
	Modul untuk menampilkan  tiga jenis papan yang tersedia
	I.S: Daftar jenis papan belum ditampilkan ke layar
	F.S: Daftar jenis papan ditampilkan ke layar
*/

void tampilHighScore(int *index_halaman);
/*
	Modul  untuk menampilkan highscore yang sudah diperoleh
	I.S: Highscore belum ditampilkan ke layar
	F.S: Highscore ditampilkan ke layar
*/

void howToPlay(int *index_halaman);
/*
	Modul untuk menampilkan panduan penggunaan permainan tic tac toe pada aplikasi ini
	I.S: Panduan belum ditampilkan ke layar
	F.S: Panduan sudah ditampilkan ke layar
*/

/*+---------------------------------------------------------------+*/
/*|                           GAME UTAMA                          |*/
/*+---------------------------------------------------------------+*/
void dashboard(Player pemain1, Player pemain2);
/*
	Modul untuk menampilkan dashboard yang berisi nama player dan skor sementara
	I.S: dashboard belum ditampilkan ke layar
	F.S: dashboard sudah ditampilkan ke layar
*/

void mainGame(permainan *game, char (*pemenang)[20], int *index_halaman);
/*
	Modul untuk menampilkan game utama berdasarkan jenis papan dan mode (versus Player atau Computer) yang dipilih.
	I.S: game utama belum ditampilkan ke layar
	F.S: game utama sudah ditampilkan ke layar
*/

/*+---------------------------------------------------------------+*/
/*|                        UNTUK KOMPUTER                         |*/
/*+---------------------------------------------------------------+*/
int minimax3(char papan[3][3], bool maximizing);
/*
	Modul ini digunakan untuk menguji langkah yang akan diambil modul posisiTerbaik3
	I.S: Nilai dari sebuah calon indeks belum diketahui
	F.S: Nilai dari sebuah calon indeks sudah diketahui dan dikembalikan
*/

posisi posisiTerbaik3(char papan[3][3]);
/*
	Modul ini digunakan untuk mengisi papan 3x3 saat giliran komputer dengan dibantu dengan modul minimax3 jika pemain
	memilih mode 'vs Computer'
	I.S: Indeks papan yang optimal belum diketahui
	F.S: Indeks papan yang optimal belum diketahui dan dikembalikan
*/

posisi posisiTerbaik5(char papan[5][5], int i_pemain, int j_pemain);
/*
	Modul ini digunakan untuk mengisi papan 5x5 saat giliran komputer jika pemain	memilih mode 'vs Computer'
	I.S: Indeks papan yang optimal belum diketahui
	F.S: Indeks papan yang optimal belum diketahui dan dikembalikan
*/

posisi posisiTerbaik7(char papan[7][7], int i_pemain, int j_pemain);
/*
	Modul ini digunakan untuk mengisi papan 7x7 saat giliran komputer jika pemain	memilih mode 'vs Computer'
	I.S: Indeks papan yang optimal belum diketahui
	F.S: Indeks papan yang optimal belum diketahui dan dikembalikan
*/

/*+---------------------------------------------------------------+*/
/*|                         SETELAH GAME                          |*/
/*+---------------------------------------------------------------+*/
void menuAkhir(permainan game, char pemenang[20], int *index_halaman, bool *keluar);
/*
	Modul ini bertujuan untuk menampilkan menu akhir setelah sebuah permainan selesai.
	I.S: Menu akhir belum ditampilkan ke layar
	F.S: Menu akhir sudah ditampilkan ke layar
*/

void saveGame(permainan game);
/*
	Modul untuk menyimpan data state dari suatu permainan yang meliputi mode main, jenis papan, serta nama dan skor
	dari player 1 dan 2.
	I.S: data state dari permainan belum tersimpan
	F.S: data state dari permainan sudah tersimpan
*/

void loadGame(int *index_halaman, permainan *game);
/*
	Modul ini digunakan untuk meng-assign variabel game dengan data yang tersimpan pada file sehingga pengguna dapat
	melanjutkan permainan.
	I.S: data permainan tersimpan belum tampil ke layar
	F.S: data permainan tersimpan sudah tampil ke layar
*/

/*+---------------------------------------------------------------+*/
/*|                          PRINT PAPAN                          |*/
/*+---------------------------------------------------------------+*/
void printPapan3(char papan[3][3]);
/*
	Modul ini digunakan untuk menampilkan papan 3x3 ke layar.
	I.S: papan 3x3 belum ditampilkan ke layar
	F.S: papan 3x3 sudah ditampilkan ke layar
*/

void printPapan5(char papan[5][5]);
/*
	Modul ini digunakan untuk menampilkan papan 5x5 ke layar.
	I.S: papan 5x5 belum ditampilkan ke layar
	F.S: papan 5x5 sudah ditampilkan ke layar
*/

void printPapan7(char papan[7][7]);
/*
	Modul ini digunakan untuk menampilkan papan 7x7 ke layar.
	I.S: papan 7x7 belum ditampilkan ke layar
	F.S: papan 7x7 sudah ditampilkan ke layar
*/

/*+---------------------------------------------------------------+*/
/*|                   DEKLARASI MODUL UNTUK 3x3                   |*/
/*+---------------------------------------------------------------+*/
void main3(permainan *game, char (*pemenang)[20], int *index_halaman);
/*
	Modul ini digunakan sebagai badan utama dari game yang dimainkan dengan jenis papan 3x3.
	I.S: Permainan tic tac toe dengan papan 3x3 belum berjalan.
	F.S: Permainan tic tac toe dengan papan 3x3 selesai dengan state akhir (menang/seri) uang telah diketahui.
*/

int cekKosong3(char papan[3][3]);
/*
	Modul  untuk menghitung jumlah ruang kosong yang terdapat pada papan 3x3 dan mengembalikan nilai tersebut.
	I.S: Ruang kosong tidak diketahui jumlahnya.
	F.S: Ruang kosong diketahui jumlahnya dan dikembalikan nilainya.
*/

int cekPemenang3(char papan[3][3]);
/*
	Modul untuk mengecek kondisi papan 3x3 dan mengembalikan nilai 1 jika pemain 1 menang, 2 jika pemain 2 atau
	komputer, 3 jika berakhir seri.
	I.S: Hasil akhir pertandingan tidak diketahui
	F.S: Diketahui hasil akhir pertandingan (menang/seri)
*/

void giliran3(char (*papan)[3][3], int *giliran, int modeMain);
/*
	Modul ini digunakan untuk meng-assign karakter ‘X’ atau ‘O’ pada papan 3x3.
	I.S: meng-assign karakter ‘X’
	F.S: meng-assign karakter ‘O’
*/

void setPapan3(char (*papan)[3][3]);
/*
	Modul untuk mengosongkan papan 3x3.
	I.S: Papan 3x3 kosong atau sudah terisi karena permainan sebelumnya.
	F.S: Papan 3x3 kosong.
*/

/*+---------------------------------------------------------------+*/
/*|                   DEKLARASI MODUL UNTUK 5x5                   |*/
/*+---------------------------------------------------------------+*/
void main5(permainan *game, char (*pemenang)[20], int *index_halaman);
/*
	Modul ini digunakan sebagai badan utama dari game yang dimainkan dengan jenis papan 5x5.
	I.S: Permainan tic tac toe dengan papan 5x5 belum berjalan.
	F.S: Permainan tic tac toe dengan papan 5x5 selesai dengan state akhir (menang/seri) uang telah diketahui.
*/

int cekKosong5(char papan[5][5]);
/*
	Modul  untuk menghitung jumlah ruang kosong yang terdapat pada papan 5x5 dan mengembalikan nilai tersebut.
	I.S: Ruang kosong tidak diketahui jumlahnya.
	F.S: Ruang kosong diketahui jumlahnya dan dikembalikan nilainya.
*/

int cekPemenang5(char papan[5][5]);
/*
	Modul untuk mengecek kondisi papan 5x5 dan mengembalikan nilai 1 jika pemain 1 menang, 2 jika pemain 2 atau
	komputer, 3 jika berakhir seri.
	I.S: Hasil akhir pertandingan tidak diketahui
	F.S: Diketahui hasil akhir pertandingan (menang/seri)
*/

void giliran5(char (*papan)[5][5], int *giliran, int modeMain);
/*
	Modul ini digunakan untuk meng-assign karakter ‘X’ atau ‘O’ pada papan 5x5.
	I.S: meng-assign karakter ‘X’
	F.S: meng-assign karakter ‘O’
*/

void setPapan5(char (*papan)[5][5]);
/*
	Modul untuk mengosongkan papan 5x5.
	I.S: Papan 5x5 kosong atau sudah terisi karena permainan sebelumnya.
	F.S: Papan 5x5 kosong.
*/

/*+---------------------------------------------------------------+*/
/*|                   DEKLARASI MODUL UNTUK 7x7                   |*/
/*+---------------------------------------------------------------+*/
void main7(permainan *game, char (*pemenang)[20], int *index_halaman);
/*
	Modul ini digunakan sebagai badan utama dari game yang dimainkan dengan jenis papan 7x7.
	I.S: Permainan tic tac toe dengan papan 7x7 belum berjalan.
	F.S: Permainan tic tac toe dengan papan 7x7 selesai dengan state akhir (menang/seri) uang telah diketahui.
*/

int cekKosong7(char papan[7][7]);
/*
	Modul  untuk menghitung jumlah ruang kosong yang terdapat pada papan 7x7 dan mengembalikan nilai tersebut.
	I.S: Ruang kosong tidak diketahui jumlahnya.
	F.S: Ruang kosong diketahui jumlahnya dan dikembalikan nilainya.
*/

int cekPemenang7(char papan[7][7]);
/*
	Modul untuk mengecek kondisi papan 7x7 dan mengembalikan nilai 1 jika pemain 1 menang, 2 jika pemain 2 atau
	komputer, 3 jika berakhir seri.
	I.S: Hasil akhir pertandingan tidak diketahui
	F.S: Diketahui hasil akhir pertandingan (menang/seri)
*/

void giliran7(char (*papan)[7][7], int *giliran, int modeMain);
/*
	Modul ini digunakan untuk meng-assign karakter ‘X’ atau ‘O’ pada papan 7x7.
	I.S: meng-assign karakter ‘X’
	F.S: meng-assign karakter ‘O’
*/

void setPapan7(char (*papan)[7][7]);
/*
	Modul untuk mengosongkan papan 7x7.
	I.S: Papan 7x7 kosong atau sudah terisi karena permainan sebelumnya.
	F.S: Papan 7x7 kosong.
*/

/*+---------------------------------------------------------------+*/
/*|                        MODUL HIGHSCORE                        |*/
/*+---------------------------------------------------------------+*/
void printHighScore(char namapemain[20], int skor, int urutanData, int akhir);
/*
	Modul ini digunakan untuk menampilkan nama pemain dan skor  ke layar
	I.S: Nama pemain dan skor belum ditampilkan ke layar
	F.S: Nama pemain dan skor sudah ditampilkan ke layar
*/

int cekNamaDuplikat(int _awal, char listNama[10000][20], char _namaPlayer[20]);
/*
	Modul ini digunakan untuk mengecek nma yang memeiliki duplikat
	I.S: Duplikat nama belum diketahui
	F.S: Mengetahui nama duplikat atau bukan
*/