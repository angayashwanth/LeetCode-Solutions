int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int a = nums[i][i];
        int b = nums[i][numsSize - i - 1];

        if (isPrime(a) && a > ans)
            ans = a;

        if (isPrime(b) && b > ans)
            ans = b;
    }

    return ans;
}