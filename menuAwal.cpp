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
  banner();
  kursorOut(55, 15);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
  kursorOut(55, 16);
  printf("%c START        %c", 186, 186);
  kursorOut(55, 17);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(55, 18);
  printf("%c LOAD GAME    %c", 186, 186);
  kursorOut(55, 19);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(55, 20);
  printf("%c HIGHSCORE    %c", 186, 186);
  kursorOut(55, 21);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  kursorOut(55, 22);
  printf("%c EXIT         %c", 186, 186);
  kursorOut(55, 23);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
  
  x = 53;
  y = 16;
  kursorOut(x,y);
  printf("%c", 175);
  do {
  	inp = getch();
	switch (inp) {
		case atas:
			printf("\b ");
			if (y>16) {
				y -= 2;
			}
			break;
		case bawah:
			printf("\b ");
			if (y<22) {
				y += 2;
			}
	}
	
	switch (inp) {
		case W:
			printf("\b ");
			if (y>16) {
				y -= 2;
			}
			break;
		case S:
			printf("\b ");
			if (y<22) {
				y += 2;
			}
		case w:
			printf("\b ");
			if (y>16) {
				y -= 2;
			}
			break;
		case s:
			printf("\b ");
			if (y<22) {
				y += 2;
			}
	}
  	
	kursorOut(x, y);
	printf("%c", 175);  
  } while (inp != 13);
  
  switch (y) {
  	case 16:
  		*index_halaman = 4;
  		break;
	case 18:
		*index_halaman = 2;
		break;
	case 20:
		*index_halaman = 3;
		break;
	case 22:
		*keluar = true;
		break;
  }
}
