#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>



int main()
{
	
	//ilk olarak assagidaki kod satirini cmd ye istedigimiz klasore gore yaziyoruz.
	//curl http://bilgisayar.kocaeli.edu.tr/prolab/prolab/prolab.txt -o input.txt'
	// biz gecici olarak bir input.txt dosyasi ekledik usteki kod calisirsa istenilen sekiller cizilir

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");  //ara yüz acma kodu

    FILE *file;
    char filename[] = "input.txt"; // Dosya adi "input.txt"
    file = fopen(filename, "r");   // Dosya okuma modunda açma kodu

    if (file == NULL)
    {
        printf("Dosya açma hatasi: %s\n", filename);
        return 1;
    }

    char karakterler[100]; // Karakterleri saklayacak dizi
    int kordinatlar[20][100] = {0};     // Sayilari saklayacak dizi

    int krktrkonum = 0; // Karakter dizisinin indeksi
    int nmrkonum = 0;  // Sayi dizisinin indeksi

    char karakter;
    char gecici[10]; // Sayilari gecici olarak saklamak için kullanilacak dizi
    int gecicikonum = 0;

    int FKontrol = 0; //0. index 1. index 2. index..... matris boyutunu arttiriyor

    int eleman[20] = {0}; //her bir sairdaki eleman sayisini gösteriyor
    int elemankontrol = 0; 

    int satir;

    int rezerv ;
    int sondajmaliyeti;
    int platformmaliyeti;
    int toplamsondajmaliyeti;
    int toplamplatformmaliyeti;
    int toplamplatformsayisi;
    int toplamsondajsayisi;
    int kar ;
    int toplammaliyet;



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



            // Sayilari alirken bir sonraki karakteri kontrol ediyoruz
            char yenikarakter = fgetc(file);
            if (!isdigit(yenikarakter))
            {
                
                gecici[gecicikonum] = '\0';    // Eger bir sonraki karakter sayi degilse  bu sayiyi bitirdik
                kordinatlar[FKontrol][nmrkonum] = atoi(gecici); //char integer gecisi yapiyoruz
                nmrkonum++;
                gecicikonum = 0;
                
            }

            
            ungetc(yenikarakter, file); // Bir sonraki karakteri dosyaya geri ekleme kodu
        }
    }

    
    fclose(file); // Dosyayi kapat
    
    setcolor(1);

    for(int i=0; i<=2000; i+=10) //arka plan cizdirme kodu
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

    for(int i = 0; i<eleman[satir] - 4; i = i+2) //secilen sekilleri cizdirdik
    {
        line((kordinatlar[satir][i+1])*10,(kordinatlar[satir][i+2])*10,(kordinatlar[satir][i+3])*10,(kordinatlar[satir][i+4])*10);
    }


    int alan = 0;
    
    for (int i = 0; i < eleman[satir] - 4; i = i + 2)
    {
        
        int uzunluk = abs(kordinatlar[satir][i] - kordinatlar[satir][i + 2]);   // kenar uzunluklari hesaplayip alani buluyoruz
        int genislik = abs(kordinatlar[satir][i + 1] - kordinatlar[satir][i + 3]);
        
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
    
    
   
   
    
    





    getch();
    closegraph();



    return 0;
}


