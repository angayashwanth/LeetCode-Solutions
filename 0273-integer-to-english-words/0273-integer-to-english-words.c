
#include <string.h>

char *ones[] = {
    "", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};

char *tens[] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"
};

char result[1000];

void convert(int num, char *out) {
    char temp[100];

    if (num >= 100) {
        strcat(out, ones[num / 100]);
        strcat(out, " Hundred");
        num %= 100;
        if (num) strcat(out, " ");
    }

    if (num >= 20) {
        strcat(out, tens[num / 10]);
        num %= 10;
        if (num) strcat(out, " ");
    }

    if (num > 0)
        strcat(out, ones[num]);
}

char* numberToWords(int num) {
    result[0] = '\0';

    if (num == 0)
        return "Zero";

    char *units[] = {"", "Thousand", "Million", "Billion"};
    char groups[4][100];
    int count = 0;

    while (num > 0) {
        int part = num % 1000;

        groups[count][0] = '\0';

        if (part > 0) {
            convert(part, groups[count]);

            if (units[count][0]) {
                strcat(groups[count], " ");
                strcat(groups[count], units[count]);
            }
        }

        count++;
        num /= 1000;
    }

    for (int i = count - 1; i >= 0; i--) {
        if (groups[i][0]) {
            if (result[0])
                strcat(result, " ");

            strcat(result, groups[i]);
        }
    }

    return result;
}
