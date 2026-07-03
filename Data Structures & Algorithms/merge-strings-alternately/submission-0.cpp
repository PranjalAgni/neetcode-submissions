class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();

        string answer = "";
        int x = 0;
        int y = 0;

        while (x < N || y < M) {
            if (x < N) {
                answer += word1[x];
                x += 1;
            }

            if (y < M) {
                answer += word2[y];
                y += 1;
            }
        }

        return answer;
    }
};