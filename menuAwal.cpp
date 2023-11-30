/*
File		: menuAwal.cpp
Deskripsi	: Body modul menuAwal() untuk menampilkan menu awal permainan ke layar.
Dibuat oleh	: Thafa Fadillah Ramdani / 2315240
Tgl			: 29/11/2023
*/

#include <stdio.h>
#include "header.h"
#define W 87
#define w 119 
#define S 83
#define s 115
#define atas 72
#define bawah 80

void menuAwal(int *index_halaman, bool *keluar)
{
  int x, y, inp;
  kursorOut(45, 7);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
  kursorOut(45, 8);
  printf("%c START        %c", 186, 186);
  kursorOut(45, 9);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(45, 10);
  printf("%c LOAD GAME    %c", 186, 186);
  kursorOut(45, 11);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(45, 12);
  printf("%c HIGHSCORE    %c", 186, 186);
  kursorOut(45, 13);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(45, 14);
  printf("%c EXIT         %c", 186, 186);
  kursorOut(45, 15);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
  
  x = 43;
  y = 8;
  kursorOut(x,y);
  printf("%c", 175);
  do {
  	inp = getch();
	switch (inp) {
		case atas:
			printf("\b ");
			if (y>8) {
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
			if (y>8) {
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
			if (y>8) {
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
  	case 8:
  		*index_halaman = 4;
  		break;
	case 10:
		*index_halaman = 2;
		break;
	case 12:
		*index_halaman = 3;
		break;
	case 14:
		*keluar = true;
		break;
  }
}
