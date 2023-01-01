#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    int month = n % 100;
    int year = n / 100;
    printf("saal:%02d\n", year);
    printf("maah:%02d", month);
}