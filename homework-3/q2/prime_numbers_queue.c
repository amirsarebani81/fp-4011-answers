#include <stdio.h>
#include <stdbool.h>

bool is_prime_slow(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_prime_medium(int n) {
    for(int i=2;i*i <= n;i++)
        if(n%i == 0)
            return false;
    return true;
}

bool is_prime_fast(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int find_next_prime_number(int number) {
    if(number == 2)
        return 3;
    while(1) {
        number += 2;
        if(
            //you can use is_prime_slow, is_prime_medium or is_prime_fast but to get the best performance use is_prime_fast
//                is_prime_slow(number)
//                is_prime_medium(number)
                is_prime_fast(number)
                )
            return number;
    }
}

int find_length_of_current_number(int number) {
    int length = 0;
    while(number > 0) {
        number /= 10;
        length++;
    }
    return length;
}

int find_specified_number_in_sequence(int number) {
    int current_number = 2;
    int current_number_length = 1;
    number -= current_number_length;
    while(number>0) {
        current_number = find_next_prime_number(current_number);
        current_number_length = find_length_of_current_number(current_number);
        number -= current_number_length;
    }
    while(number < 0) {
        current_number /= 10;
        number++;
    }
    return current_number % 10;
}

int main() {
    int number;
    scanf("%d", &number);
    printf("%d", find_specified_number_in_sequence(number));
}

