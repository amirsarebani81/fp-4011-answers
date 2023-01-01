#include <stdio.h>

int main() {
    int w, d;
    scanf("%d %d", &w, &d);

    int num = w * 7 - d;
    if (num <= 6 * 31)
        printf("%d", num / 31 + 1);
    else
        printf("%d", (num - 186) / 30 + 7);

    return 0;
}
