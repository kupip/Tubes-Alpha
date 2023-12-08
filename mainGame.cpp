/*
File		: mainGame.cpp
Deskripsi	: Body modul mainGamel() untuk menjalankan permainan Tic Tac Toe
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include <unistd.h>
#include "header.h"

char papan3[3][3] = {{' ', ' ', ' '},
					 {' ', ' ', ' '},
					 {' ', ' ', ' '}};
					
char papan5[5][5] = {{' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' '}};
					 
char papan7[7][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
int turn = 1;
int kosong=9;

// Deklarasi modul untuk 3x3
void main3(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong3(char papan[3][3]);
int cekPemenang3(char papan[3][3]);
void giliran3(char papan[3][3], int *giliran);
void setPapan3(char (*papan)[3][3]);

// Deklarasi modul untuk 5x5
void main5(permainan *game, char (*pemenang)[20], int *index_halaman);
int cekKosong5(char papan[5][5]);
int cekPemenang5(char papan[5][5]);
void giliran5(char (*papan)[5][5], int *giliran);
void setPapan5(char (*papan)[5][5]);

// Deklarasi modul untuk 7x7
void main7(permainan *game);
int cekKosong7(char papan[7][7]);
int cekPemenang7(char papan[7][7]);
void giliran7(char papan[7][7], int *giliran);
void setPapan7(char papan[7][7]);

void mainGame(permainan *game, char (*pemenang)[20], int *index_halaman) {
	switch((*game).jenis_papan) {
		case 3:
			main3(&(*game), &(*pemenang), &(*index_halaman));
			break;
		case 5:
			main5(&(*game), &(*pemenang), &(*index_halaman));
			break;
		case 7:
			main7(&(*game));
			break;
	}
}

void main3(permainan *game, char (*pemenang)[20], int *index_halaman) {
	int idx_pemenang=0;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan3(&papan3);
	while (kosong != 0) {
		printPapan3(papan3);
		giliran3(papan3, &turn);
		kosong = cekKosong3(papan3);
		idx_pemenang = cekPemenang3(papan3);
		printPapan3(papan3);
		
		if (idx_pemenang == 1) {
			strcpy((*pemenang), (*game).pemain1.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain1.skor++;
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 2) {
			strcpy((*pemenang), (*game).pemain2.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain2.skor++;
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 3 && kosong == 0)
		{
			printf("Draw");
			strcpy((*pemenang), " ");
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
	}
}

void main5(permainan *game, char (*pemenang)[20], int *index_halaman) {
	int idx_pemenang=0;
	dashboard((*game).pemain1, (*game).pemain2);
	setPapan5(&papan5);
	while (kosong != 0) {
		printPapan5(papan5);
		giliran5(&papan5, &turn);
		kosong = cekKosong5(papan5);
		idx_pemenang = cekPemenang5(papan5);
		printPapan5(papan5);
		
		if (idx_pemenang == 1) {
			strcpy((*pemenang), (*game).pemain1.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain1.skor++;
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 2) {
			strcpy((*pemenang), (*game).pemain2.nama);
			kursorOut(55, 5);
			printf("pemenang: %s\n", (*pemenang));
			(*game).pemain2.skor++;
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
		else if (idx_pemenang == 3 && kosong == 0)
		{
			printf("Draw");
			strcpy((*pemenang), " ");
			*index_halaman = 8;
			sleep(2);
			system("cls");
			break;
		}
	}
}

// Modul untuk menegecek kondisi draw untuk 3x3
int cekKosong3(char papan[3][3]) {
	int count=0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (papan[i][j]==' ') {
				count++;
			}
		}
	}
	return count;
}

// Modul untuk menegecek kondisi draw untuk 5x5
int cekKosong5(char papan[5][5]) {
	int count=0;
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (papan[i][j]==' ') {
				count++;
			}
		}
	}
	return count;
}

int cekPemenang3(char papan[3][3]) {
	// Cek pemanang baris
	for(int baris = 0;baris<3;baris++){
		if(papan[baris][0] == papan[baris][1] && papan[baris][1] == papan[baris][2]) {
			if (papan[baris][1] == 'X'){
				return 1;
			} else if (papan[baris][1] == 'O'){
				return 2;
			}
		}
	}
	
	// Cek pemenang kolom
	for(int kolom = 0;kolom<3;kolom++){
		if(papan[0][kolom] == papan[1][kolom] && papan[1][kolom] == papan[2][kolom]){
			if(papan[1][kolom] == 'X'){
				return 1;
			} else if(papan[1][kolom] == 'O'){
				return 2;
			}
		}
	}
	
	// Cek pemenang diagonal 1
	if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2]) {
		if (papan[1][1] == 'X'){
			return 1;
		} else if (papan[1][1] == 'O'){
			return 2;
		}
		
	}
	// Cek pemenang diagonal 2
	if (papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0]){
		if(papan[1][1] == 'X'){
			return 1;
		} else if (papan[1][1] == 'O'){
			return 2;
		}
	}
	return 3;
}

int cekPemenang5(char papan[5][5]) {
	// Cek pemenang baris
	for(int baris = 0; baris<5; baris++){
		if((papan[baris][0] == papan[baris][1]  || papan[baris][3] == papan[baris][4]) && papan[baris][1] == papan[baris][2] && papan[baris][2] == papan[baris][3]){
			if (papan[baris][2] == 'X' && (papan[baris][0] == 'X' || papan[baris][4] == 'X')){
				return 1;
			} else if (papan[baris][2] == 'O' && (papan[baris][0] == 'O' || papan[baris][4] == 'O')){
				return 2;
			}
		}
	}
	
	// Cek pemenang kolom
	for(int kolom = 0; kolom<5; kolom++){
		if((papan[0][kolom] == papan[1][kolom]  || papan[3][kolom] == papan[4][kolom]) && papan[1][kolom] == papan[2][kolom] && papan[2][kolom] == papan[3][kolom]){
			if(papan[2][kolom] == 'X' && (papan[0][kolom] == 'X' || papan[4][kolom] == 'X')){
				return 1;
			} else if(papan[2][kolom] == 'O' && (papan[0][kolom] == 'O' || papan[4][kolom] == 'O')){
				return 2;
			}
		}
	}

	// Cek pemenang diagonal '\' besar
	if ((papan[0][0] == papan[1][1]  || papan[4][4] == papan[3][3]) && papan[1][1] == papan[2][2] && papan[2][2] == papan[3][3]) {
		if (papan[2][2] == 'X' &&  (papan[0][0] == 'X' || papan[4][4] == 'X')){
			return 1;
		} else if (papan[2][2] == 'O' && (papan[0][0] == 'O' || papan[4][4] == 'O')){
			return 2;
		}
		
	}
	
	// Cek pemenang diagonal '/' besar
	if ((papan[0][4] == papan[1][3]  || papan[3][1] == papan[4][0]) && papan[1][3] == papan[2][2] && papan[2][2] == papan[3][1]){
		if(papan[3][3] == 'X' && (papan[0][4] == 'X' || papan[3][1] == 'X')){
			return 1;
		} else if (papan[3][3] == 'O' && (papan[0][4] == 'O' || papan[3][1] == 'O')){
			return 2;
		}
	}
	
	// Cek pemenang diagonal '/' 1
	if (papan[0][3] == papan[1][2] && papan[1][2] == papan[2][1] && papan[3][0] == papan[2][1]){
		if(papan[0][3] == 'X'){
			return 1;
		} else if (papan [0][3] == 'O'){
			return 2;
		}
	}
	
	// Cek pemenang diagonal '/' 2
	if (papan[1][4] == papan[2][3] && papan[2][3] == papan[3][2] && papan[4][1] == papan[3][2]){
		if(papan[1][4] == 'X'){
			return 1;
		} else if (papan [1][4] == 'O'){
			return 2;
		}
	}
	
	// Cek pemenang diagonal '\' 1
	if (papan[1][0] == papan[2][1] && papan[3][2] == papan[2][1] && papan[3][2] == papan[4][3]){
		if(papan[4][3] == 'X'){
			return 1;
		} else if (papan [4][3] == 'O'){
			return 2;
		}
	}
	
	// Cek pemenang diagonal '\' 2
	if (papan[0][1] == papan[1][2] && papan[1][2] == papan[2][3] && papan[2][3] == papan[3][4]){
		if(papan[0][1] == 'X'){
			return 1;
		} else if (papan [0][1] == 'O'){
			return 2;
		}
	}
	return 3;
}


void giliran3(char papan[3][3], int *giliran) {
	int n, i, j;
	kursorOut(68,19);
	printf("Giliran pemain %d", *giliran);
	kursorOut(68,21);
	printf("Masukkan nomor papan:  \b");
	scanf("%d", &n);
	i=(n-1)/3;
	j=(n-1)%3;
	
	if (papan[i][j] == ' ' && *giliran == 1) {
		papan[i][j] = 'X';
		*giliran = 2;
	} else if (papan[i][j] == ' ' && *giliran == 2){
		papan[i][j] = 'O';
		*giliran = 1;
	} else {
		kursorOut(68,23);
		printf("kotak sudah terisi");
		sleep(1);
		
		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
		fflush(stdin);
	}
}

void giliran5(char (*papan)[5][5], int *giliran) {
	int n, i, j;
	kursorOut(61, 27);
	printf("Giliran pemain %d", *giliran);
	kursorOut(61, 28);
	printf("Masukkan nomor papan:   \b\b");
	scanf("%d", &n);
	i=(n-1)/5;
	j=(n-1)%5;
	fflush(stdin);
	
	if ((*papan)[i][j] == ' ' && *giliran == 1) {
		(*papan)[i][j] = 'X';
		*giliran = 2;
	} else if ((*papan)[i][j] == ' ' && *giliran == 2){
		(*papan)[i][j] = 'O';
		*giliran = 1;
	} else {
		kursorOut(61, 29);
		printf("kotak sudah terisi");
		sleep(1);
		
		// Untuk membersihkan hasil print di layar
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                  ");
		fflush(stdin);
	}
}

// Inisialisasi papan kosong 3x3
void setPapan3(char (*papan)[3][3]) {
	for (int brs=0; brs<3; brs++) {
		for (int klm=0; klm<3; klm++) {
			(*papan)[brs][klm] = ' ';
		}
	}
}

// Inisialisasi papan kosong 5x5
void setPapan5(char (*papan)[5][5]) {
	for (int brs=0; brs<5; brs++) {
		for (int klm=0; klm<5; klm++) {
			(*papan)[brs][klm] = ' ';
		}
	}
}

void main7(permainan *game) {
	kursorOut(45, 19);
	printf("p main 7x7");
}
