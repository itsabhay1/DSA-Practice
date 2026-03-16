class Solution {
    public int smallestBalancedIndex(int[] nums) {
        int n = nums.length;
        long LIMIT = (long)1e14;

        long[] suffix = new long[n + 1];
        suffix[n] = 1;

        // build suffix product array (clamped)
        for (int i = n - 1; i >= 0; i--) {
            if (suffix[i + 1] > LIMIT / nums[i]) {
                suffix[i] = LIMIT;
            } else {
                suffix[i] = nums[i] * suffix[i + 1];
            }
        }

        long prefixSum = 0;

        for (int i = 0; i < n; i++) {
            long rightProduct = suffix[i + 1];

            if (prefixSum == rightProduct) {
                return i;
            }

            prefixSum += nums[i];
        }

        return -1;
    }
}