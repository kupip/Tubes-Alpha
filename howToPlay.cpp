/*
File		: howToPlay.cpp
Deskripsi	: Body modul howToPlay() untuk menampilkan cara bermain.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include "header.h"

void howToPlay(int *index_halaman) {
	system("cls");
	
	banner();
	kursorOut(15, 13);
	printf("Cara Bermain");
	kursorOut(15, 14);
	printf("1. Anda dapat mengisi kotak dengan memasukkan nomor kotak yang Anda inginkan melalui keyboard.");
	kursorOut(15, 15);
	printf("   Nomor yang dimasukkan harus sesuai dengan nomor kotak yang tersedia.");
	kursorOut(15, 16);
	printf("2. Anda tidak dapat mengisi kotak yang sudah yg terisi.");
	kursorOut(15, 17);
	printf("3. Setelah memasukkan angka, simbol X tidak akan langsung muncul.");
	kursorOut(15, 18);
	printf("4. Untuk memunculkannya, Anda dapat menekan Enter.");
	kursorOut(15, 19);
	printf("5. Untuk memenangkan permainan, Anda perlu membentuk deret X baik secara horizontal, vertikal, maupun diagonal.");
	kursorOut(15, 20);
	printf("6. Untuk papan 3x3, Anda perlu membentuk deret dengan 3 simbol. Sedangkan, untuk papan 5x5,");
	kursorOut(15, 21);
	printf("   Anda perlu membentuk deret dengan 4 simbol. Kemudian, untuk papan 7x7, Anda perlu membentuk deret dengan 5 simbol.");
	kursorOut(15, 24);
	printf("Tekan apa saja untuk kembali...");
	
	getch();
	*index_halaman = 1;
	system("cls");
}

/*

   
*/
