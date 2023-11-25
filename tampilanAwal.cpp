/*
File		: tampilanAwal.cpp
Deskripsi	: Body modul tampilanAwal() untuk menampilkan halaman pembuka
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 24/11/2023
*/

#include <stdio.h>
#include "header.h"
#include <windows.h>

void tampilanAwal() {
	// X BESAR
	kursorOut(48, 9); // Start bagian atas X
	printf("%c%c           %c%c         %c%c%c", 178, 178, 178, 178, 178, 178, 178);
	kursorOut(50, 10);
	printf("%c%c       %c%c         %c%c   %c%c", 178, 178, 178, 178, 178, 178, 178, 178);
	kursorOut(52, 11);
	printf("%c%c   %c%c         %c%c       %c%c", 178, 178, 178, 178, 178, 178, 178, 178);
	kursorOut(54, 12); // Tengah-tengah X
	printf("%c%c%c         %c%c           %c%c", 178, 178, 178, 178, 178, 178, 178);
	kursorOut(52, 13); // Start Bagian Bawah X
	printf("%c%c   %c%c         %c%c       %c%c", 178, 178, 178, 178, 178, 178, 178, 178);
	kursorOut(50, 14);
	printf("%c%c       %c%c         %c%c   %c%c", 178, 178, 178, 178, 178, 178, 178, 178);
	kursorOut(48, 15);
	printf("%c%c           %c%c         %c%c%c", 178, 178, 178, 178, 178, 178, 178);
	
	// TIC TAC TOE
	kursorOut(45, 16);
	printf("%c%c%c %c  %c%c  %c%c%c  %c   %c%c  %c%c%c  %c  %c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	kursorOut(45, 17);
	printf(" %c  %c %c     %c  %c%c%c %c     %c  %c %c %c%c%c", 219, 219, 219, 219, 219, 220, 219, 219, 219, 219, 219, 219, 254, 254);
	kursorOut(45, 18);
	printf(" %c  %c  %c%c   %c  %c %c  %c%c   %c   %c  %c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	
	kursorOut(45, 21);
	printf("Press any key to continue...");
}
