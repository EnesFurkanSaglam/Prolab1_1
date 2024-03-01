#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "input.txt";
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Dosya açma hatası: %s\n", filename);
        return 1;
    }

    int kordinatlar[20][100] = {0};
    int nmrkonum = 0;
    int FKontrol = 0;

    int eleman[20] = {0};
    int elemankontrol = 0;
    int satir;

    while (!feof(file)) {
        char karakter;
        int gecici[8];

        while (fscanf(file, "%d", &gecici[nmrkonum]) == 1) {
            nmrkonum++;
            char c = fgetc(file);
            if (c == 'F') {
                eleman[elemankontrol] = nmrkonum;
                nmrkonum = 0;
                elemankontrol++;
                break;
            }
        }
    }

    printf("Kaçıncı satırın alanını hesaplamak istiyorsunuz? ");
    scanf("%d", &satir);
    satir = satir - 1;

    int alan = 0;
    for (int i = 0; i < eleman[satir] - 4; i = i + 2) {
        // Dikdörtgenin kenar uzunluklarını hesapla
        int uzunluk = abs(kordinatlar[satir][i] - kordinatlar[satir][i + 2]);
        int genislik = abs(kordinatlar[satir][i + 1] - kordinatlar[satir][i + 3]);
        // Dikdörtgenin alanını birim kare sayısı ile hesapla
        alan += uzunluk * genislik;
    }

    printf("Seçilen %d. satırdaki şeklin alanı: %d birim kare\n", satir + 1, alan);

    fclose(file);
    return 0;
}
