class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int N = nums.size();
        while (k-- > 0) {
            int smallestIdx = 0;
            int small = nums[smallestIdx];

            for (int idx = 1; idx < N; idx++) {
                if (nums[idx] < small) {
                    smallestIdx = idx;
                    small = nums[idx];
                }
            }

            nums[smallestIdx] *= multiplier;
        }

        return nums;

    }
};