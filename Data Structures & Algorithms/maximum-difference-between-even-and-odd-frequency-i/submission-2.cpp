class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freqMap;
        for (char& ch: s) {
            freqMap[ch] += 1;
        }

        int oddF = INT_MIN;
        int evenF = INT_MAX;
        for (const auto it: freqMap) {
            int f = it.second;
            if (f % 2 == 0) evenF = min(evenF, f);
            else oddF = max(oddF, f);;
        }

        return oddF - evenF;
    }
};