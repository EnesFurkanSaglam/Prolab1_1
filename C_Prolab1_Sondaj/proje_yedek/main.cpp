#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>



int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    FILE *file;
    char filename[] = "input.txt"; // Dosya ad� "input.txt"
    file = fopen(filename, "r");   // Dosyay� okuma modunda a�

    if (file == NULL)
    {
        printf("Dosya a�ma hatas�: %s\n", filename);
        return 1;
    }

    char karakterler[100]; // Karakterleri saklayacak dizi
    int kordinatlar[20][100] = {0};     // Say�lar� saklayacak dizi

    int krktrkonum = 0; // Karakter dizisinin indeksi
    int nmrkonum = 0;  // Say� dizisinin indeksi

    char karakter;
    char gecici[10]; // Say�lar� ge�ici olarak saklamak i�in kullan�lacak dizi
    int gecicikonum = 0;

    int FKontrol = 0; //0. index 1. index 2. index diye kullan�y�uz

    int eleman[20] = {0}; //her bir sat�rdaki eleman say� say�s�n� g�steriyor
    int elemankontrol = 0;

    int satir = 0;

    int rezerv = 0;
    int sondajmaliyeti = 0;
    int platformmaliyeti = 0;
    int toplamsondajmaliyeti = 0;
    int toplamplatformmaliyeti = 0;
    int toplamplatformsayisi = 0;
    int toplamsondajsayisi = 0;
    int kar = 0;
    int toplammaliyet = 0;



    printf("Birim sondaj maliyetini giriniz: ");
    scanf("%d",&sondajmaliyeti);

    printf("\n");

    printf("Birim platform maliyetini giriniz: ");
    scanf("%d",&platformmaliyeti);

    printf("\n");





    while ((karakter = fgetc(file)) != EOF)
    {
        if (isalpha(karakter))
        {
            karakterler[krktrkonum] = karakter;
            krktrkonum++;
            if(karakter == 'F')
            {
                FKontrol++;
                eleman[elemankontrol] = nmrkonum;
                nmrkonum = 0;
                elemankontrol++;
            }
        }
        else if (isdigit(karakter))
        {
            gecici[gecicikonum] = karakter;
            gecicikonum++;

            // Say�lar� al�rken bir sonraki karakteri kontrol et

            char yenikarakter = fgetc(file);
            if (!isdigit(yenikarakter))
            {
                // E�er bir sonraki karakter say� de�ilse, bu say�y� bitirdik
                gecici[gecicikonum] = '\0';
                kordinatlar[FKontrol][nmrkonum] = atoi(gecici);
                nmrkonum++;
                gecicikonum = 0;
            }

            // Bir sonraki karakteri dosyaya geri ekleyin
            ungetc(yenikarakter, file);
        }
    }

    // Dosyay� kapat
    fclose(file);
    
    setcolor(1);

    for(int i=0; i<=2000; i+=10)
    {
        line(i,0,i,2000);
    }
    for(int i = 0; i<=2000; i+=10)
    {
        line(0,i,2000,i);
    }


    printf("Satir bilgisi giriniz: ");
    scanf("%d",&satir);
    printf("\n");
    satir = satir - 1;

    

    setcolor(3);

    for(int i = 0; i<eleman[satir] - 4; i = i+2)
    {
        line((kordinatlar[satir][i+1])*10,(kordinatlar[satir][i+2])*10,(kordinatlar[satir][i+3])*10,(kordinatlar[satir][i+4])*10);
    }


    int alan = 0;
    
    for (int i = 0; i < eleman[satir] - 4; i = i + 2)
    {
        // Dikd�rtgenin kenar uzunluklar�n� hesapla
        int uzunluk = abs(kordinatlar[satir][i] - kordinatlar[satir][i + 2]);
        int genislik = abs(kordinatlar[satir][i + 1] - kordinatlar[satir][i + 3]);
        // Dikd�rtgenin alan�n� birim kare say�s� ile hesapla
        alan += uzunluk * genislik/2;
    }

    

    printf("Se�ilen %d. satirdaki seklin alani: %d birim kare\n", satir + 1, alan);

    printf("\n");
    
    fflush(stdin);
    char bosluk;
    
    float optimizasyon = alan/2.5;
    
    printf("Optimize hali i�in herhangi bir tusa basiniz: \n");
    scanf("%c",&bosluk);
    
    setcolor(0);
    
    for(int i=0; i<=2000; i+=10)
    {
        line(i,0,i,2000);
    }
    for(int i = 0; i<=2000; i+=10)
    {
        line(0,i,2000,i);
    }
    
   
    
    
    setcolor(5);

    for(int i=0; i<=2000; i+=25)
    {
        line(i,0,i,2000);
    }
    for(int i = 0; i<=2000; i+=25)
    {
        line(0,i,2000,i);
    }
    
     setcolor(3);
    
    for(int i = 0; i<eleman[satir] - 4; i = i+2)
    {
        line((kordinatlar[satir][i+1])*10,(kordinatlar[satir][i+2])*10,(kordinatlar[satir][i+3])*10,(kordinatlar[satir][i+4])*10);
    }


    rezerv  = alan * 10;
    printf("Rezerv Degeri: %d",rezerv);
    printf("\n");

    toplamsondajmaliyeti = optimizasyon * sondajmaliyeti;
    toplamplatformsayisi = optimizasyon;
    toplamplatformmaliyeti = optimizasyon * platformmaliyeti;
    kar = rezerv - (toplamplatformmaliyeti +  toplamsondajmaliyeti);
    toplamsondajsayisi = optimizasyon;
    toplammaliyet = toplamplatformmaliyeti +  toplamsondajmaliyeti;


    printf("Toplam platform sayisi: %d",toplamplatformsayisi);
    printf("\n");
    printf("Toplam sondaj sayisi: %d",toplamsondajsayisi);
    printf("\n");
    printf("Toplam platform maliyeti: %d",toplamplatformmaliyeti);
    printf("\n");
    printf("Toplam sondaj maliyeti: %d",toplamsondajmaliyeti);
    printf("\n");
    printf("Toplam maliyet: %d",toplammaliyet);
    printf("\n");
    printf("Kar - Zarar: %d",kar);
    
    
   
    printf("\n");
    
    





    getch();
    closegraph();



    return 0;
}


