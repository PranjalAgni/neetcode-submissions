class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        if (n == 0 || m == 0) return "";
        string small = n <= m ? str1 : str2;
        string big = n > m ? str1 : str2;


        int N = min(n, m);
        int M = max(n, m);

        for (int letters = N; letters >= 1; letters--) {
            string divisor = small.substr(0, letters);

            int len = divisor.length();

            if (N % len != 0 || M % len != 0) continue;

            int diffSmall = N / len;
            int diffBig = M / len;

            string x = divisor;
            while (diffSmall-- > 1) {
                x += divisor;
            }

            string y = divisor;
            while (diffBig-- > 1) {
                y += divisor;
            }

            if (x == small && y == big) {
                return divisor;
            }
        }

        return "";


    }
};


// N <= M and N > M

// aba ababab
// small = aba
// big = ababab

// aba def
// small = aba
// big = def

// defc x
// small = x
// big = defc