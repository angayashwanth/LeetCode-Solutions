
class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;
        int[] suffixMin = new int[n];

        suffixMin[n - 1] = nums[n - 1];

        // Calculate suffix minimum
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = Math.min(nums[i], suffixMin[i + 1]);
        }

        int ans = 0;
        int prefixMax = nums[0];

        for (int i = 1; i < n - 1; i++) {

            if (nums[i] > prefixMax && nums[i] < suffixMin[i + 1]) {
                ans += 2;
            }
            else if (nums[i] > nums[i - 1] &&
                     nums[i] < nums[i + 1]) {
                ans += 1;
            }

            prefixMax = Math.max(prefixMax, nums[i]);
        }

        return ans;
    }
}
