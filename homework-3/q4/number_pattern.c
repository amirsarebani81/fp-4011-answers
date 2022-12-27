#include <stdio.h>

void print_descending_part(int n, int number) {
    for(int i=0;i<n;i++)
        printf("%d", number-i);
}

void print_repeating_part(int number) {
    for(int i=0;i<number;i++)
        printf("%d", number);
}

void print_row(int biggestNumber, int number) {
    int n = biggestNumber - number;
    print_descending_part(n, biggestNumber);
    print_repeating_part(number);
}

void print_pattern(int number) {
    for(int i=0;i<number;i++) {
        print_row(number, number - i);
        printf("\n");
    }
}

int main() {
    int number;
    scanf("%d", &number);
    print_pattern(number);
}

