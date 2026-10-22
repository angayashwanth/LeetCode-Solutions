
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solveEquation(char* equation) {
    int coeff = 0, constant = 0;
    int sign = 1, num = 0, hasNum = 0;
    int side = 1;

    for (int i = 0; ; i++) {
        char c = equation[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            hasNum = 1;
            continue;
        }

        if (c == 'x') {
            coeff += side * sign * (hasNum ? num : 1);
            num = 0;
            hasNum = 0;
            continue;
        }

        if (hasNum)
            constant += side * sign * num;

        num = 0;
        hasNum = 0;

        if (c == '=') {
            side = -1;
            sign = 1;
        } else if (c == '+' || c == '-') {
            sign = (c == '+') ? 1 : -1;
        } else if (c == '\0') {
            break;
        }
    }

    if (coeff == 0) {
        if (constant == 0)
            return strdup("Infinite solutions");
        return strdup("No solution");
    }

    char *result = malloc(30);
    sprintf(result, "x=%d", -constant / coeff);
    return result;
}
