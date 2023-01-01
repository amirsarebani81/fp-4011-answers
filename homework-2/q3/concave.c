#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a == 180 || b == 180 || c == 180 || d == 180 || a + b + c + d != 360)
        printf("Not a quadrilateral");
    else if (a > 180 || b > 180 || c > 180 || d > 180)
        printf("Concave");
    else
        printf("Convex");

    return 0;
}
