/*
File		: pilihPapan.cpp
Deskripsi	: Body modul pilihPapan() untuk menampilkan menu pemilihan jenis papan.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 30/11/2023
*/
#include <stdio.h>
#include "header.h"
#define W 87
#define w 119 
#define S 83
#define s 115
#define atas 72
#define bawah 80

void pilihPapan(int *index_halaman, int *jenis_papan) {
	system("cls");
	int x, y, inp;
	kursorOut(47, 9);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
  	kursorOut(47, 10);
  	printf("%c 3x3         %c", 186, 186);
  	kursorOut(47, 11);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  	kursorOut(47, 12);
  	printf("%c 5x5         %c", 186, 186);
  	kursorOut(47, 13);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  	kursorOut(47, 14);
  	printf("%c 7x7         %c", 186, 186);
  	kursorOut(47, 15);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
  	
  	x = 45;
  	y = 10;
  	kursorOut(x,y);
  	printf("%c", 175);
  	do {
  		inp = getch();
		switch (inp) {
			case atas:
				printf("\b ");
				if (y>10) {
					y -= 2;
				}
				break;
			case bawah:
				printf("\b ");
				if (y<14) {
					y += 2;
				}
		}
	
		switch (inp) {
			case W:
				printf("\b ");
				if (y>10) {
					y -= 2;
				}
				break;
			case S:
				printf("\b ");
				if (y<14) {
					y += 2;
				}
			case w:
				printf("\b ");
				if (y>10) {
					y -= 2;
				}
				break;
			case s:
				printf("\b ");
				if (y<14) {
					y += 2;
				}
		}
  	
		kursorOut(x, y);
		printf("%c", 175);  
  } while (inp != 13);
  
  switch (y) {
  	case 10:
  		*index_halaman = 5;
  		*jenis_papan = 3;
  		break;
	case 12:
		*index_halaman = 5;
		*jenis_papan = 5;
		break;
	case 14:
		*index_halaman = 5;
		*jenis_papan = 7;
		break;
  }
}
