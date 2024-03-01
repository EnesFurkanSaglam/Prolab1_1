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
    char filename[] = "input.txt"; // Dosya adý "input.txt"
    file = fopen(filename, "r");   // Dosyayý okuma modunda aç

    if (file == NULL)
    {
        printf("Dosya açma hatasý: %s\n", filename);
        return 1;
    }

    char karakterler[100]; // Karakterleri saklayacak dizi
    int kordinatlar[20][100] = {0};     // Sayýlarý saklayacak dizi

    int krktrkonum = 0; // Karakter dizisinin indeksi
    int nmrkonum = 0;  // Sayý dizisinin indeksi

    char karakter;
    char gecici[10]; // Sayýlarý geçici olarak saklamak için kullanýlacak dizi
    int gecicikonum = 0;

    int FKontrol = 0; //0. index 1. index 2. index diye kullanýyýuz

    int eleman[20] = {0}; //her bir satýrdaki eleman sayý sayýsýný gösteriyor
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

            // Sayýlarý alýrken bir sonraki karakteri kontrol et

            char yenikarakter = fgetc(file);
            if (!isdigit(yenikarakter))
            {
                // Eðer bir sonraki karakter sayý deðilse, bu sayýyý bitirdik
                gecici[gecicikonum] = '\0';
                kordinatlar[FKontrol][nmrkonum] = atoi(gecici);
                nmrkonum++;
                gecicikonum = 0;
            }

            // Bir sonraki karakteri dosyaya geri ekleyin
            ungetc(yenikarakter, file);
        }
    }

    // Dosyayý kapat
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
        // Dikdörtgenin kenar uzunluklarýný hesapla
        int uzunluk = abs(kordinatlar[satir][i] - kordinatlar[satir][i + 2]);
        int genislik = abs(kordinatlar[satir][i + 1] - kordinatlar[satir][i + 3]);
        // Dikdörtgenin alanýný birim kare sayýsý ile hesapla
        alan += uzunluk * genislik/2;
    }

    

    printf("Seçilen %d. satirdaki seklin alani: %d birim kare\n", satir + 1, alan);

    printf("\n");
    
    fflush(stdin);
    char bosluk;
    
    float optimizasyon = alan/2.5;
    
    printf("Optimize hali için herhangi bir tusa basiniz: \n");
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


