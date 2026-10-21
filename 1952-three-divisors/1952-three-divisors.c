
bool isThree(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i) {
                count++;
            }
        }

        if (count > 3) {
            return false;
        }
    }

    return count == 3;
}
