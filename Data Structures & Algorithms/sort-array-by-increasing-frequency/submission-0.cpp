class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int& num: nums) {
            freqMap[num] += 1;
        }

        vector<int> answer;

        for (int freq = 1; freq <= 100; freq++) {
            for (int elt = 100; elt >= -100; elt--) {
                if (freqMap[elt] == freq) {
                    int times = freq;
                    while (times-- > 0) {
                        answer.push_back(elt);
                    }
                }
            }
        }

        return answer;
    }
};