/*
File		: howToPlay.cpp
Deskripsi	: Body modul howToPlay() untuk menampilkan cara bermain.
Dibuat oleh	: M. Rafif Genadratama / 231524016
Tgl			: 01/12/2023
*/

#include <stdio.h>
#include "header.h"

void howToPlay(int *index_halaman) {
	banner();
	kursorOut(45, 10);
	printf("Cara Bermain");
	kursorOut(45, 11);
	printf("1. Anda dapat mengisi kotak dengan memasukkan nomor kotak yang Anda inginkan melalui keyboard.");
	kursorOut(45, 12);
	printf("Nomor yang dimasukkan harus sesuai dengan nomor kotak yang tersedia.");
	kursorOut(45, 13);
	printf("2. Anda tidak dapat mengisi kotak yang sudah yg terisi.");
	kursorOut(45, 14);
	printf("3. Setelah memasukkan angka, simbol X tidak akan langsung muncul.");
	kursorOut(45, 15);
	printf("4. Untuk memunculkannya, Anda dapat menekan Enter.");
	kursorOut(45, 16);
	printf("5. Untuk memenangkan permainan, Anda perlu membentuk deret X baik secara horizontal, vertikal, maupun diagonal.");
}

/*
6. Untuk papan 3x3, Anda perlu membentuk deret dengan 3 simbol. Sedangkan, untuk papan 5x5,
   Anda perlu membentuk deret dengan 4 simbol. Kemudian, untuk papan 7x7, Anda perlu membentuk deret dengan 5 simbol.
*/
