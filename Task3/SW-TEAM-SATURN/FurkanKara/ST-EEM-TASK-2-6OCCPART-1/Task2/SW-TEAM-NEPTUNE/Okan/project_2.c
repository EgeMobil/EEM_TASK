#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1000  // Büyük bir dizi

// Girilen degerin tamamen sayi olup olmadigini kontrol eden fonksiyon
int is_valid_number(char *input) {
    int i = 0;

    // Tum karakterlerin rakam olup olmadigini kontrol et
    for (; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0;  // Sayi degilse gecersiz giris
        }
    }
    return 1;  // Gecerli sayi
}

int main() {
    int data[SIZE];  // Buyuk bir dizi
    int* ptr = data; // Isaretciyi dizinin basina al

    // Diziyi isaretci aritmetigi ile doldur
    for (int i = 0; i < SIZE; i++) {
        *(ptr + i) = i * 2;  // Isaretci ile diziyi doldur
    }

    char input[100]; // Kullanici girisini string olarak al
    int index;

    while (1) { // Sonsuz dongu
        printf("\nLutfen bir sira numarasi girin (0 - %d): ", SIZE - 1);
        
        // Kullanici girisini al
        if (scanf("%s", input) != 1) {
            printf("Hatali giris! Lutfen bir sayi girin.\n");
            while (getchar() != '\n');  // Giris tamponunu temizle
            continue;
        }

        // Eger giris tamamen sayi degilse hata ver ve tekrar sor
        if (!is_valid_number(input)) {
            printf("Hatali giris! Lutfen yalnizca bir sayi girin.\n");
            continue;
        }

        // String olarak alinan girisi tam sayiya cevir
        index = atoi(input);

        // Negatif giris kontrolu
        if (index < 0) {
            printf("Hatali giris! Negatif deger girilemez. Lutfen gecerli bir sira numarasi girin.\n");
            continue;  // Tekrar giris iste
        }

        // Gecerli indeks kontrolu
        if (index >= 0 && index < SIZE) {
            printf("Sira numarasi %d olan degeri: %d\n", index, *(ptr + index));
        } else {
            printf("Hatali giris! Lutfen 0 ile %d arasinda bir sayi girin.\n", SIZE - 1);
        }
    }

    return 0;
}
