class Solution {
private:
    void go(vector<int>& nums, int pos, int& N, int& answer, int prod) {
        if (pos >= N) return;
        go(nums, pos + 1, N, answer, prod * nums[pos]);
        go(nums, pos + 1, N, answer, nums[pos]);
        answer = max(answer, prod);
        
    }
public:
    int maxProduct(vector<int>& nums) {
        int answer = nums[0];
        int minEnd = nums[0];
        int maxEnd = nums[0];
        int N = nums.size();
        for (int idx = 1; idx < N; idx++) {
            int x = nums[idx];
            int nextMin = min({x, x * minEnd, x * maxEnd});
            int nextMax = max({x, x * minEnd, x * maxEnd});

            minEnd = nextMin;
            maxEnd = nextMax;
            answer = max({answer, minEnd, maxEnd});
        }


        return answer;
    }
};
