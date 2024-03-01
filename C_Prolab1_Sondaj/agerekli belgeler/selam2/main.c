#include <stdio.h>
#include <stdlib.h>
#include <graphic.h>


int main()
{
    initwindow (EKRAN_X, EKRAN_Y)://GRAFIK ICIN YENI CONSOL PENCERE setcolor (GREEN); // KOORDINAT CIZGI RENGI
    line (EKRAN_X/2,0, EKRAN_X/2, EKRAN_Y); // X EKSENI line (0, EKRAN_Y/2, EKRAN_X, EKRAN_Y/2); // Y EKSENI


    return 0;
}
