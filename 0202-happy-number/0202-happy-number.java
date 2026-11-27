import java.util.*;
class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> hs = new HashSet<>();

        while (n != 1 && !hs.contains(n)) {
            hs.add(n);

            int s = 0;

            while (n != 0) {
                int r = n % 10;
                s = s + r * r;
                n = n / 10;
            }

            n = s;
        }

        return n == 1;
    }
}