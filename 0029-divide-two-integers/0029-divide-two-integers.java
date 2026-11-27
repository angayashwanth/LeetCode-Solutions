class Solution {
    public int divide(int dividend, int divisor) {

        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;

        boolean neg = (dividend < 0) ^ (divisor < 0);

        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);

        long ans = 0;

        while (a >= b) {
            long temp = b;
            long count = 1;

            while (a >= (temp << 1)) {
                temp = temp << 1;
                count = count << 1;
            }

            a = a - temp;
            ans = ans + count;
        }

        if (neg)
            ans = -ans;

        return (int) ans;
    }
}