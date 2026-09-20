#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function untuk menjalankan proses permainn secara rekursif
int permainantebakangka(int jawaban, int minimum, int maksimum, int *percobaan, int maks_percobaan) {
    int tebakan;

    printf("masukkan tebakan anda (%d - %d) : ", minimum, maksimum);
    scanf("%d", &tebakan);

    (*percobaan)++;

    if (tebakan == jawaban) {
        printf("\nwidih keren! berhasil nih nebak angka %d cuma %d kali aja, mantap!\n", jawaban, *percobaan);
        return 1;
    }

    if (*percobaan >= maks_percobaan) {
        printf("\n GAME OVER!! yah sayang bamget kesempatan kamu udah abis nih (%d kali)\n", maks_percobaan);
        return 0;
    }
    if (tebakan < jawaban) {
        printf("telalu kecil nih! masukin lagi!\n");
        return permainantebakangka(jawaban, tebakan + 1, maksimum, percobaan, maks_percobaan);
    } else {
        printf("terlalu besar nih! masukin lagi!\n");
        return permainantebakangka(jawaban, minimum, tebakan - 1, percobaan, maks_percobaan);
    }
}

void tampilkanhasil(int percobaan) {
    if (percobaan <= 3) {
        printf("good job! cepet banget sih, keren!");
    } else if (percobaan <= 5) {
        printf("good job! it's okey!");
    } else {
        printf("hampir aja, latihan lagi gih sono! biar lebih jago lagi");
    }
}

void jalankanpermainan() {
    int minimum = 1;
    int maksimum = 100;
    int percobaan = 0;
    int maks_percobaan = 7;

    int jawaban = (rand() % (maksimum - minimum + 1)) + minimum;

    printf("=====================================================\n");
    printf("        tebak angkanya dong!\n");
    printf("=====================================================\n");
    printf("    welcome to the game tebak angka!\n");
    printf("saya telah memilih sebuah angka antara %d dan %d.\n", minimum, maksimum);
    printf("Kamu punya %d kesempatan untuk menebaknya!\n", maks_percobaan);
    printf("=====================================================\n\n");

   int menang = permainantebakangka(jawaban, minimum, maksimum, &percobaan, maks_percobaan);

    if (menang) {
        tampilkanhasil(percobaan);
    } else {
        printf("Angka yang benar sebenarnya adalah: %d\n", jawaban);
        printf("yah, kalah ni yee! ayo coba lagi! kalau enggak cupu lo! \n");
    }
}

int main () {
    char main_lagi;
    srand(time(NULL));
    do {
        jalankanpermainan();

        printf("\nApakah kamu ingin bermain lagi? (y/n): ");
        scanf(" %c", &main_lagi);
        printf("\n");

    } while (main_lagi == 'y' || main_lagi == 'Y');

    printf("Terima kasih sudah bermain! Sampai jumpa lagi!\n");

    return 0;
}