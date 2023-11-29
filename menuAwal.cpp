/*
File		: menuAwal.cpp
Deskripsi	: Body modul menuAwal() untuk menampilkan menu awal permainan ke layar.
Dibuat oleh	: Thafa Fadillah Ramdani / 2315240
Tgl			: 26/11/2023
*/

#include <stdio.h>

#include "header.h"

void menuAwal()
{
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
}
