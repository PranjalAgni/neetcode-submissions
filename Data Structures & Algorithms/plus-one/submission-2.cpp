class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for (int& d: digits) {
            num = num * 10 + d;
        }

        vector<int> answer;
        num += 1;
        while (num != 0) {
            answer.push_back(num % 10);
            num /= 10;
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};

