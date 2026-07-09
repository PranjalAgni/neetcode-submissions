class Solution {
public:
    int lengthOfLastWord(string s) {
        int N = s.length();
        int right = N - 1;
        while (right >= 0 && s[right] == ' ') {
            right -= 1;
        }

        int wordLen = 0;
        while (right >= 0 && s[right] != ' ') {
            wordLen += 1;
            right -= 1;
        }

        return wordLen;
    }
};