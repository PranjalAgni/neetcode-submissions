class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqMap;
        for (char& ch: s) {
            freqMap[ch] += 1;
        }

        // stored all the elements in map with freq
        for (char& ch: t) {
            freqMap[ch] -= 1;
        }

        for (const auto& it: freqMap) {
            if (it.second != 0) return false;
        }

        return true;
    }
};
