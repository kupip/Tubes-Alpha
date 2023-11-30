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
	kursorOut(47, 14);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
  	kursorOut(47, 15);
  	printf("%c 3x3          %c", 186, 186);
  	kursorOut(47, 16);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  	kursorOut(47, 17);
  	printf("%c 5x5          %c", 186, 186);
  	kursorOut(47, 18);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  	kursorOut(47, 19);
  	printf("%c 7x7          %c", 186, 186);
  	kursorOut(47, 20);
  	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
  	
  	x = 45;
  	y = 15;
  	kursorOut(x,y);
  	printf("%c", 175);
  	do {
  		inp = getch();
		switch (inp) {
			case atas:
				printf("\b ");
				if (y>15) {
					y -= 2;
				}
				break;
			case bawah:
				printf("\b ");
				if (y<19) {
					y += 2;
				}
		}
	
		switch (inp) {
			case W:
				printf("\b ");
				if (y>15) {
					y -= 2;
				}
				break;
			case S:
				printf("\b ");
				if (y<19) {
					y += 2;
				}
			case w:
				printf("\b ");
				if (y>15) {
					y -= 2;
				}
				break;
			case s:
				printf("\b ");
				if (y<19) {
					y += 2;
				}
		}
  	
		kursorOut(x, y);
		printf("%c", 175);  
  } while (inp != 13);
  
  switch (y) {
  	case 15:
  		*index_halaman = 6;
  		*jenis_papan = 3;
  		break;
	case 17:
		*index_halaman = 6;
		*jenis_papan = 5;
		break;
	case 19:
		*index_halaman = 6;
		*jenis_papan = 7;
		break;
  }
}
