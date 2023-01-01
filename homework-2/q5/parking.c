#include <stdio.h>

int main() {
    int enter, duration;
    scanf("%d %d", &enter, &duration);
    int ans = 0;

    if (enter >=0 && enter <= 5)
        ans += 5;
    else if (enter >=6 && enter <= 11)
        ans += 10;
    else if (enter >=12 && enter <= 17)
        ans += 13;
    else if (enter >=18 && enter <= 23)
        ans += 15;

    if (duration <= 6)
        ans += duration * 3;
    else if (duration <= 24)
        ans += 18 + (duration - 6) * 2;
    else
        ans += 18 + 36 + (duration - 24);

    printf("%d", ans);

    return 0;
}
