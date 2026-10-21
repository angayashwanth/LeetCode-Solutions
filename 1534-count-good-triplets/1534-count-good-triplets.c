int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;

    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            for (int k = j + 1; k < arrSize; k++) {
                int x = arr[i] - arr[j];
                int y = arr[j] - arr[k];
                int z = arr[i] - arr[k];

                if (x < 0) x = -x;
                if (y < 0) y = -y;
                if (z < 0) z = -z;

                if (x <= a && y <= b && z <= c) {
                    count++;
                }
            }
        }
    }

    return count;
}
