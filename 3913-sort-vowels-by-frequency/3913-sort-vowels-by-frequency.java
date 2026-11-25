import java.util.*;

class Solution {
    public String sortVowels(String s) {
        ArrayList<Character> l = new ArrayList<>();
        String v = "aeiou";

        int[] freq = new int[26];
        int[] first = new int[26];

        Arrays.fill(first, Integer.MAX_VALUE);

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (v.indexOf(ch) != -1) {
                l.add(ch);

                freq[ch - 'a']++;

                if (first[ch - 'a'] == Integer.MAX_VALUE) {
                    first[ch - 'a'] = i;
                }
            }
        }

        Collections.sort(l, (a, b) -> {
            if (freq[a - 'a'] != freq[b - 'a']) {
                return freq[b - 'a'] - freq[a - 'a'];
            }

            return first[a - 'a'] - first[b - 'a'];
        });

        StringBuilder res = new StringBuilder(s);
        int p = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (v.indexOf(ch) != -1) {
                res.setCharAt(i, l.get(p));
                p++;
            }
        }

        return res.toString();
    }
}