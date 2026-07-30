class NumArray {
public:
    vector<int> numList;
    NumArray(vector<int>& nums) {
        numList = nums;
    }
    
    int sumRange(int left, int right) {
        int answer = 0;
        for (int idx = left; idx <= right; idx++) {
            answer += numList[idx];
        }

        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */