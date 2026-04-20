#include <graphics.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    circle(250, 200, 100); // Draws a circle
    getch();
    closegraph();
    return 0;
}
