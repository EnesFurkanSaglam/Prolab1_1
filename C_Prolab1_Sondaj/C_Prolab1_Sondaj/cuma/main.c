#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//#include <graphics.h>
#include <math.h>




//ALANNNNN htsn

struct Point
{
    double x;
    double y;
};

struct Shape
{
    struct Point *points;
    int num_points;
};

// Alan hesaplamak için kullanılan fonksiyon
double calculate_area(struct Shape shape)
{
    double area = 0.0;
    int j;
    for (int i = 0; i < shape.num_points; i++)
    {
        j = (i + 1) % shape.num_points;
        area += (shape.points[i].x * shape.points[j].y - shape.points[j].x * shape.points[i].y);
    }
    area = fabs(area) / 2.0;
    return area;
}

int main()
{

    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "C:\\TC\\BGI");

    FILE *file;
    char filename[] = "input.txt"; // Dosya adı "input.txt"
    file = fopen(filename, "r");   // Dosyayı okuma modunda aç

    if (file == NULL)
    {
        printf("Dosya açma hatası: %s\n", filename);
        return 1;
    }

    char characters[100]; // Karakterleri saklayacak dizi
    int numbers[3][100] = {0};     // Sayıları saklayacak dizi

    int charIndex = 0; // Karakter dizisinin indeksi
    int numIndex = 0;  // Sayı dizisinin indeksi

    char currentChar;
    char numStr[10]; // Sayıları geçici olarak saklamak için kullanılacak dizi
    int numStrIndex = 0;

    int FControl = 0; //0. index 1. index 2. index diye kullanıyıuz

    int eleman[3] = {0}; //her bir satırdaki eleman sayı sayısını gösteriyor
    int elemankontrol = 0;

    int satir;



    while ((currentChar = fgetc(file)) != EOF)
    {
        if (isalpha(currentChar))
        {
            characters[charIndex] = currentChar;
            charIndex++;
            if(currentChar == 'F')
            {
                FControl++;
                eleman[elemankontrol] = numIndex;
                numIndex = 0;
                elemankontrol++;
            }


        }
        else if (isdigit(currentChar))
        {
            numStr[numStrIndex] = currentChar;
            numStrIndex++;

            // Sayıları alırken bir sonraki karakteri kontrol et
            char nextChar = fgetc(file);
            if (!isdigit(nextChar))
            {
                // Eğer bir sonraki karakter sayı değilse, bu sayıyı bitirdik
                numStr[numStrIndex] = '\0';
                numbers[FControl][numIndex] = atoi(numStr);
                numIndex++;
                numStrIndex = 0;
            }

            // Bir sonraki karakteri dosyaya geri ekleyin
            ungetc(nextChar, file);
        }
    }

    // Dosyayı kapat
    fclose(file);


    printf("kacinci satiri istiyorsun: ");
    scanf("%d",&satir);
    satir = satir - 1;


    int satir1[eleman[0]-1];
    int satir2[eleman[1]-1];
    int satir3[eleman[2]-1];

    for(int i = 0; i<eleman[0]-1; i++)
    {
        satir1[i]=numbers[0][i+1];
    }
    for(int i = 0; i<eleman[1]; i++)
    {
        satir2[i]=numbers[1][i+1];
    }
    for(int i = 0; i<eleman[2]; i++)
    {
        satir3[i]=numbers[2][i+1];
    }


    // Üçgenin köşe noktaları

    if(satir == 0)
    {
        for(int i = 0;i<eleman[0]-1;i++)
        {
        struct Point shape[] = {};

        int num_points = sizeof(shape) / sizeof(shape[0]);
        struct Shape myShape = {shape, num_points};

        // Alan hesaplaması yapılıyor
        double area = calculate_area(myShape);

        // Sonucu ekrana yazdırma
        printf("Üçgen alanı: %f\n", area);

        }


    }
    else if(satir == 1)
    {

        struct Point shape[] = {};

        int num_points = sizeof(shape) / sizeof(shape[0]);
        struct Shape myShape = {shape, num_points};

        // Alan hesaplaması yapılıyor
        double area = calculate_area(myShape);

        // Sonucu ekrana yazdırma
        printf("Üçgen alanı: %f\n", area);

    }
    else if(satir == 2)
    {
        struct Point shape[] = {};

        int num_points = sizeof(shape) / sizeof(shape[0]);
        struct Shape myShape = {shape, num_points};

        // Alan hesaplaması yapılıyor
        double area = calculate_area(myShape);

        // Sonucu ekrana yazdırma
        printf("Üçgen alanı: %f\n", area);

    }













    /*
    int x,y;
    for(x=0; x<=2000; x=x+10)
    {
        setcolor(1);
        line(x,0,x,2000);
    }
    for(y=0; y<=2000; y=y+10)
    {
        setcolor(1);
        line(0,y,2000,y);
    }

    setcolor(5);

    for(int i = 0; i<eleman[satir] - 4; i = i+2)
    {
    	line((numbers[satir][i+1])*10,(numbers[satir][i+2])*10,(numbers[satir][i+3])*10,(numbers[satir][i+4])*10);
    }





    getch();
    closegraph();


    */



    return 0;
}
