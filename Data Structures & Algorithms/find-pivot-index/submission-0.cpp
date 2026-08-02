class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixSum(N);
        vector<int> postfixSum(N);

        int val = 0;

        // [1,5,3,2,4]
        // 
        for (int idx = 0; idx < N; idx++) {
            prefixSum[idx] = val;
            val += nums[idx];
        }

        val = 0;

        for (int idx = N - 1; idx >= 0; idx--) {
            postfixSum[idx] = val;
            val += nums[idx];
        }

        for (int idx = 0; idx < N; idx++) {
            if (prefixSum[idx] == postfixSum[idx]) {
                return idx;
            }
        }

        return -1;
    }
};