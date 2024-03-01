#include <stdio.h>
#include <stdlib.h>

int main() {
    double x1 = 5, y1 = 5;
    double x2 = 13, y2 = 12;
    double x3 = 8, y3 = 17;
    double x4 = 1, y4 = 10;

    // Küçük küçük köşe koordinatları
    double a[] = {x1, y1};

    // Küçük büyük köşe koordinatları
    double b[] = {x2, y3};

    // Büyük büyük köşe koordinatları
    double c[] = {x3, y3};

    // Küçük küçük köşe koordinatları
    double d[] = {x4, y4};

    // İlk kare hesaplaması
    double s1 = 0.5 * abs((b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]));

    // İkinci kare hesaplaması
    double s2 = 0.5 * abs((c[0] - b[0]) * (d[1] - c[1]) - (c[1] - b[1]) * (d[0] - c[0]));

    // Üçüncü kare hesaplaması
    double s3 = 0.5 * abs((d[0] - c[0]) * (a[1] - d[1]) - (d[1] - c[1]) * (a[0] - d[0]));

    // İşlenmiş alan hesaplaması
    double s = s1 + s2 + s3;

    printf("Asimetrik şeklin alanı: %lf\n", s);

    return 0;
}
