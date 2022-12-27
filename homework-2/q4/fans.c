#include <stdio.h>

#define PI 3.14

int main() {
    float w,l,r;
    int n;

    scanf("%f %f %f %d", &w, &l, &r, &n);

    const float ans = r * 2 * PI * n;
    const float perimeter = w * 2 + l * 2;

    if (ans >= perimeter)
        printf("It's enough");
    else
        printf("It's not enough");

    return 0;
}
