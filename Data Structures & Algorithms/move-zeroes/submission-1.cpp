class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int& num: nums) {
            if (num == 0) count += 1;
        }

        int N = nums.size();
        int pos = 0;
        for (int idx = 0; idx < N; idx++) {
            if (nums[idx] != 0) {
                nums[pos] = nums[idx];
                pos += 1;
            }
        }

        while (count-- > 0) {
            nums[pos] = 0;
            pos += 1;
        }
    }
};