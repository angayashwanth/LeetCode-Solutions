
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void fraction(char *s, ll *num, ll *den) {
    char integer[20] = "0";
    char non[20] = "";
    char rep[20] = "";

    char *dot = strchr(s, '.');
    char *open = strchr(s, '(');

    if (dot == NULL) {
        *num = atoll(s);
        *den = 1;
        return;
    }

    int ilen = dot - s;
    strncpy(integer, s, ilen);
    integer[ilen] = '\0';

    if (open == NULL) {
        strcpy(non, dot + 1);
        int n = strlen(non);
        ll p = 1;
        for (int i = 0; i < n; i++) p *= 10;

        *num = atoll(integer) * p + (n ? atoll(non) : 0);
        *den = p;
    } else {
        char *close = strchr(s, ')');
        int n = open - dot - 1;
        int r = close - open - 1;

        strncpy(non, dot + 1, n);
        non[n] = '\0';
        strncpy(rep, open + 1, r);
        rep[r] = '\0';

        ll p = 1, q = 1;
        for (int i = 0; i < n; i++) p *= 10;
        for (int i = 0; i < r; i++) q *= 10;

        *den = p * (q - 1);
        *num = atoll(integer) * (*den)
             + (n ? atoll(non) : 0) * (q - 1)
             + atoll(rep);
    }

    ll g = gcd(*num, *den);
    if (g) {
        *num /= g;
        *den /= g;
    }
}

bool isRationalEqual(char* s, char* t) {
    ll a, b, c, d;

    fraction(s, &a, &b);
    fraction(t, &c, &d);

    return a * d == c * b;
}
