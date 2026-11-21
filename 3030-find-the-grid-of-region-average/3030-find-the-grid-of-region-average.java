
class Solution {
    public int[][] resultGrid(int[][] image, int threshold) {

        int m = image.length;
        int n = image[0].length;

        int[][] sum = new int[m][n];
        int[][] count = new int[m][n];

        // Check every possible 3x3 region
        for (int r = 0; r <= m - 3; r++) {
            for (int c = 0; c <= n - 3; c++) {

                boolean valid = true;
                int total = 0;

                // Check all pixels in the region
                for (int i = r; i < r + 3; i++) {
                    for (int j = c; j < c + 3; j++) {

                        total += image[i][j];

                        // Check right adjacent pixel
                        if (j < c + 2 &&
                            Math.abs(image[i][j] - image[i][j + 1]) > threshold) {
                            valid = false;
                        }

                        // Check bottom adjacent pixel
                        if (i < r + 2 &&
                            Math.abs(image[i][j] - image[i + 1][j]) > threshold) {
                            valid = false;
                        }
                    }
                }

                // Update all pixels if region is valid
                if (valid) {
                    int avg = total / 9;

                    for (int i = r; i < r + 3; i++) {
                        for (int j = c; j < c + 3; j++) {
                            sum[i][j] += avg;
                            count[i][j]++;
                        }
                    }
                }
            }
        }

        // Construct final result
        int[][] result = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (count[i][j] > 0) {
                    result[i][j] = sum[i][j] / count[i][j];
                } else {
                    result[i][j] = image[i][j];
                }
            }
        }

        return result;
    }
}
