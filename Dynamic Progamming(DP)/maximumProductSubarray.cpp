Code with explanation:

// In the problem of finding the maximum product subarray, handling the product
// of numbers can be tricky, especially when negative numbers are involved. This
// is because the product of two negative numbers can become a large positive
// number, and similarly, multiplying by a positive number can change the
// magnitude of the product significantly. The use of dpMax and dpMin helps to
// keep track of these changes efficiently. and dpMax & dpMin helps us to keep
// the track of these changes.

class Solution {
public:
    int ansRange(int l, int r, vector<int>& nums) {

        long long ans = nums[l];
        long long dpMin = nums[l], dpMax = nums[l];
        for (int i = l + 1; i <= r; i++) {
            //             while multiplying a number
            //             Positive nums[i]:

            // Multiplying the current dpMax by a positive number will either
            // increase or maintain the maximum product. Multiplying the current
            // dpMin by a positive number will either decrease or maintain the
            // minimum product. Negative nums[i]:

            // Multiplying the current dpMax by a negative number will turn it
            // into a potentially large negative product. Multiplying the
            // current dpMin by a negative number can turn it into a large
            // positive product, which might become the new dpMax. Zero or
            // nums[i] itself:

            // If nums[i] is zero, both dpMax and dpMin should reset to zero
            // because the product of any number with zero is zero. If
            // considering nums[i] itself provides a higher product than any
            // product involving previous numbers, then dpMax and dpMin should
            // be reset to nums[i].
            long long a = max(dpMax * nums[i], dpMin * nums[i]);
            long long b = min(dpMax * nums[i], dpMin * nums[i]);
            dpMax = max(a, nums[i] * 1LL);
            dpMin = min(b, nums[i] * 1LL);
            if (dpMax >= INT_MAX)
                dpMax = nums[i];
            if (dpMin <= -INT_MAX)
                dpMin = nums[i];
            ans = max(ans, dpMax);
        }
        return (int)ans;
    }
    int maxProduct(vector<int>& nums) {
        return ansRange(0, (int)(nums.size()) - 1, nums);
    }
};

Time Complexity:
O(n)

Space Complexity: O(1)
Space Complexity:
