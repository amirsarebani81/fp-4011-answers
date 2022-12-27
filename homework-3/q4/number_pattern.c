#include <stdio.h>

void print_pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf("%d", n - j);
        for (int j = 0; j < n - i; j++)
            printf("%d", n - i);
        printf("\n");
    }
}

int main() {
    int number;
    scanf("%d", &number);
    print_pattern(number);
}

