#include <stdio.h>
#include <stdbool.h>

bool is_negative(int number) {
    return number < 0;
}

int find_length(int number) {
    int counter = 0;
    while(number!=0) {
        number/=10;
        counter++;
    }
    return counter;
}

int find_left_most_digit(int number, int baseTen) {
    return (int) (number / baseTen % 10)  ;
}

int power(int base, int power) {
    int result = 1;
    for(int i=0; i < power; i++) {
        result *= base;
    }
    return result;
}

void print_number_from_one_to_ten(int digit) {
    switch (digit) {
        case 0:
            printf("zero"); break;
        case 1:
            printf("one");  break;
        case 2:
            printf("two");  break;
        case 3:
            printf("three");    break;
        case 4:
            printf("four"); break;
        case 5:
            printf("five"); break;
        case 6:
            printf("six");  break;
        case 7:
            printf("seven");    break;
        case 8:
            printf("eight");    break;
        case 9:
            printf("nine"); break;
        default:
            printf("impossible-small"); break;
    }
}

void print_string_of_number(int number) {
    if(is_negative(number)) {
        printf("minus ");
        number = -number;
    }
    int number_length = find_length(number);
    for(int i=number_length; i > 0; i--) {
        int base_ten = power(10, i);
        int left_most_digit = find_left_most_digit(number, base_ten);
        print_number_from_one_to_ten(left_most_digit);
        printf(" ");
    }
}

int main() {
    int number;
    scanf("%d", &number);
    print_string_of_number(number);
}

