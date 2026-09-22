#include "stdio.h"

int main() {
    int secim;

    printf("--- MENU ---\n");
    printf("1 - 10'luk sayiyi 2'lik sisteme cevir (Binary)\n");
    printf("2 - 2'lik sayiyi 10'luk sisteme cevir\n");
    printf("3 - 10'luk sayiyi 16'lik sisteme cevir (Hexadecimal)\n");
    printf("4 - 16'lik sayiyi 10'luk sisteme cevir\n");
    printf("5 - Iki adet Binary sayiyi topla\n");
    printf("Seciminiz (1-5): ");
    scanf("%d", &secim);

    if (secim == 1) {
        // 10'luk -> 2'lik (Çıkarma/2'nin kuvvetleri şeklinde)
        int sayi;
        printf("10'luk sistemde bir sayi giriniz: ");
        scanf("%d", &sayi);

        int basamaklar[] = {256, 128, 64, 32, 16, 8, 4, 2, 1};
        printf("Binary karsiligi: ");
        
        for (int k = 0; k < 9; k++) {
            if (sayi >= basamaklar[k]) {
                printf("1");
                sayi = sayi - basamaklar[k];
            } else {
                printf("0");
            }
        }
        printf("\n");

    } else if (secim == 2) {
        // 2'lik -> 10'luk
        long long binary;
        printf("Binary (sadece 1 ve 0) bir sayi giriniz: ");
        scanf("%lld", &binary);

        int decimal = 0, basamakDegeri = 1;
        while (binary > 0) {
            int sonBasamak = binary % 10;
            decimal += sonBasamak * basamakDegeri;
            basamakDegeri *= 2;
            binary /= 10;
        }
        printf("10'luk karsiligi: %d\n", decimal);

    } else if (secim == 3) {
        // 10'luk -> 16'lik (Hexadecimal)
        int sayi;
        printf("10'luk sistemde bir sayi giriniz: ");
        scanf("%d", &sayi);

        printf("16'lik (Hex) karsiligi: %X\n", sayi);

    } else if (secim == 4) {
        // 16'lik -> 10'luk
        int sayi;
        printf("16'lik (Hex) bir sayi giriniz (Orn: 1A, FF): ");

        scanf("%x", &sayi);
        printf("10'luk karsiligi: %d\n", sayi);

    } else if (secim == 5) {
        // Binary Toplama
        long long b1, b2;
        printf("Birinci binary sayiyi giriniz: ");
        scanf("%lld", &b1);
        printf("Ikinci binary sayiyi giriniz: ");
        scanf("%lld", &b2);

        int i = 0, elde = 0;
        int toplam[20];

        while (b1 != 0 || b2 != 0) {
            toplam[i] = (b1 % 10 + b2 % 10 + elde) % 2;
            elde = (b1 % 10 + b2 % 10 + elde) / 2;
            b1 /= 10;
            b2 /= 10;
            i++;
        }
        if (elde != 0) {
            toplam[i] = elde;
            i++;
        }

        printf("Binary Toplam Sonucu: ");
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", toplam[j]);
        }
        printf("\n");

    } else {
        printf("Gecersiz bir secim yaptiniz!\n");
    }

    return 0;
}
