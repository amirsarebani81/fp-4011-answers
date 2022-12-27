#include <stdio.h>
#include <stdbool.h>

int find_first_digit_from_right(int number) {
    return number % 10;
}

int find_left_most_digit(int number, int baseTen) {
    return number / baseTen;
}

int find_second_digit_from_right(int number) {
    return (number % 100) / 10;
}

bool is_in_range_of_ten_to_twenty(int number, int i) { return i == 2 && find_second_digit_from_right(number) == 1; }

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
            break;
        case 1:
            printf("one"); break;
        case 2:
            printf("two"); break;
        case 3:
            printf("three"); break;
        case 4:
            printf("four"); break;
        case 5:
            printf("five"); break;
        case 6:
            printf("six"); break;
        case 7:
            printf("seven"); break;
        case 8:
            printf("eight"); break;
        case 9:
            printf("nine"); break;
        default:
            printf("impossible-small"); break;
    }
}

void print_string_of_digit(int number, int index) {
    int base_ten = power(10, index);//TODO duplicate
    int left_most_digit = find_left_most_digit(number, base_ten) % 10;
    if(base_ten == 1) {
        print_number_from_one_to_ten(left_most_digit);
    } else if(base_ten == 10) {
        switch (left_most_digit) {
            case 0:
                break;
            case 1:
                printf("ten ");  break;
            case 2:
                printf("twenty ");   break;
            case 3:
                printf("thirty ");   break;
            case 4:
                printf("forty ");    break;
            case 5:
                printf("fifty ");    break;
            case 6:
                printf("sixty ");    break;
            case 7:
                printf("seventy ");  break;
            case 8:
                printf("eighty ");   break;
            case 9:
                printf("ninety ");   break;
            default:
                printf("impossible-ty");   break;
        }
    } else if (base_ten == 100) {
        if(left_most_digit != 0) {
            print_number_from_one_to_ten(left_most_digit);
            printf(" ");
            printf("hundred ");
        }
    } else if (base_ten == 1000) {
        if(left_most_digit != 0) {
            print_number_from_one_to_ten(left_most_digit);
            printf(" ");
            printf("thousand ");
        }
    }
}

void print_string_of_digit_between_ten_and_twenty(int number) {
    int leftMostDigit = find_first_digit_from_right(number);
    switch (leftMostDigit) {
        case 1:
            printf("eleven"); break;
        case 2:
            printf("twelve"); break;
        case 3:
            printf("thirteen"); break;
        case 4:
            printf("fourteen"); break;
        case 5:
            printf("fifteen"); break;
        case 6:
            printf("sixteen"); break;
        case 7:
            printf("seventeen"); break;
        case 8:
            printf("eighteen"); break;
        case 9:
            printf("nineteen"); break;
        default:
            printf("impossible-een"); break;
    }
}

bool ends_with_ten(int number) {
    return find_second_digit_from_right(number) == 1 && find_first_digit_from_right(number) == 0;
}

int find_length(int number) {
    int counter = 0;
    while(number!=0) {
        number/=10;
        counter++;
    }
    return counter;
}

void print(int number) {
    if(number == 0) {
        printf("zero");
    }
    int number_length = find_length(number);
    for(int i=number_length; i > 0; i--) {
        if(is_in_range_of_ten_to_twenty(number, i) && !ends_with_ten(number)) {
            print_string_of_digit_between_ten_and_twenty(number);
            return;
        } else {
            print_string_of_digit(number, i);
        }
    }
}

int main() {
    int number;
    scanf("%d", &number);
    print(number);
}
