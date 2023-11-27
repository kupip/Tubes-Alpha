/*
File		: printPapan.cpp
Deskripsi	: Body modul printPapan() untuk menampilkan papan ke layar.
Dibuat oleh	: Thafa Fadillah Ramdani / 2315240
Tgl			: 26/11/2023
*/

#include <stdio.h>
#include "header.h"

void printPapan(int hasilPilihPapan)
{
  if (hasilPilihPapan == 3)
  {
    char papan[3][3];
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        papan[i][j] = ' ';
      }
    }
    kursorOut(68, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 191);
    kursorOut(68, 7);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 8);
    printf("%c  %c  %c  %c  %c  %c  %c", 179, papan[0][0], 179, papan[0][1], 179, papan[0][2], 179);
    kursorOut(68, 9);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(68, 11);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 12);
    printf("%c  %c  %c  %c  %c  %c  %c", 179, papan[1][0], 179, papan[1][1], 179, papan[1][2], 179);
    kursorOut(68, 13);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(68, 15);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 16);
    printf("%c  %c  %c  %c  %c  %c  %c", 179, papan[2][0], 179, papan[2][1], 179, papan[2][2], 179);
    kursorOut(68, 17);
    printf("%c     %c     %c     %c", 179, 179, 179, 179);
    kursorOut(68, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 217);
  }
  else if (hasilPilihPapan == 5)
  {
    char papan[5][5];
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        papan[i][j] = ' ';
      }
    }
    kursorOut(61, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 191);
    kursorOut(61, 7);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 8);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[0][0], 179, papan[0][1], 179, papan[0][2], 179, papan[0][3], 179, papan[0][4], 179);
    kursorOut(61, 9);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(61, 11);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 12);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[1][0], 179, papan[1][1], 179, papan[1][2], 179, papan[1][3], 179, papan[1][4], 179);
    kursorOut(61, 13);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(61, 15);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 16);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[2][0], 179, papan[2][1], 179, papan[2][2], 179, papan[2][3], 179, papan[2][4], 179);
    kursorOut(61, 17);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(61, 19);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 20);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[3][0], 179, papan[3][1], 179, papan[3][2], 179, papan[3][3], 179, papan[3][4], 179);
    kursorOut(61, 21);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(61, 23);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 24);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[4][0], 179, papan[4][1], 179, papan[4][2], 179, papan[4][3], 179, papan[4][4], 179);
    kursorOut(61, 25);
    printf("%c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179);
    kursorOut(61, 26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 217);
  }
  else if (hasilPilihPapan == 7)
  {
    char papan[7][7];
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        papan[i][j] = ' ';
      }
    }
    kursorOut(54, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 191);
    kursorOut(54, 7);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 8);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[0][0], 179, papan[0][1], 179, papan[0][2], 179, papan[0][3], 179, papan[0][4], 179, papan[0][5], 179, papan[0][6], 179);
    kursorOut(54, 9);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 11);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 12);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[1][0], 179, papan[1][1], 179, papan[1][2], 179, papan[1][3], 179, papan[1][4], 179, papan[1][5], 179, papan[1][6], 179);
    kursorOut(54, 13);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 15);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 16);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[2][0], 179, papan[2][1], 179, papan[2][2], 179, papan[2][3], 179, papan[2][4], 179, papan[2][5], 179, papan[2][6], 179);
    kursorOut(54, 17);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 19);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 20);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[3][0], 179, papan[3][1], 179, papan[3][2], 179, papan[3][3], 179, papan[3][4], 179, papan[3][5], 179, papan[3][6], 179);
    kursorOut(54, 21);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 23);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 24);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[4][0], 179, papan[4][1], 179, papan[4][2], 179, papan[4][3], 179, papan[4][4], 179, papan[4][5], 179, papan[4][6], 179);
    kursorOut(54, 25);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 27);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 28);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[5][0], 179, papan[5][1], 179, papan[5][2], 179, papan[5][3], 179, papan[5][4], 179, papan[5][5], 179, papan[5][6], 179);
    kursorOut(54, 29);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
    kursorOut(54, 31);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 32);
    printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 179, papan[6][0], 179, papan[6][1], 179, papan[6][2], 179, papan[6][3], 179, papan[6][4], 179, papan[6][5], 179, papan[6][6], 179);
    kursorOut(54, 33);
    printf("%c     %c     %c     %c     %c     %c     %c     %c", 179, 179, 179, 179, 179, 179, 179, 179);
    kursorOut(54, 34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 217);
  }
}
