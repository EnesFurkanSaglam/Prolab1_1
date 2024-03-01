#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

struct Shape {
    struct Point *points;
    int num_points;
};

// Alan hesaplamak için kullanılan fonksiyon
double calculate_area(struct Shape shape) {
    double area = 0.0;
    int j;
    for (int i = 0; i < shape.num_points; i++) {
        j = (i + 1) % shape.num_points;
        area += (shape.points[i].x * shape.points[j].y - shape.points[j].x * shape.points[i].y);
    }
    area = fabs(area) / 2.0;
    return area;
}

int main() {
    // Üçgenin köşe noktaları

    struct Point shape[] = {{40.0, 22.0},{50.0, 32.0}, {30.0, 32.0}};

    int num_points = sizeof(shape) / sizeof(shape[0]);
    struct Shape myShape = {shape, num_points};

    // Alan hesaplaması yapılıyor
    double area = calculate_area(myShape);

    // Sonucu ekrana yazdırma
    printf("Üçgen alanı: %f\n", area);

    return 0;
}
