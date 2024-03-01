#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Initialize graphics (ayarlarinizi uygun bir sekilde düzenlemelisiniz)

    setcolor(WHITE);  // Set the color to white

    rectangle(100, 100, 300, 300);
   

    getch();  // Wait for a key press
    closegraph();  // Close the graphics window
    return 0;
}
