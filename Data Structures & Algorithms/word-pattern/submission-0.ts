class Solution {
    /**
     * @param {string} pattern
     * @param {string} s
     * @return {boolean}
     */
    wordPattern(pattern: string, s: string): boolean {
        const words = s.split(" ");
        if (words.length !== pattern.length) return false;
        const wordFreq = new Map();
        for (const word of words) {
            if (!wordFreq.has(word)) {
                wordFreq.set(word, 0);
            }

            const current = wordFreq.get(word);
            wordFreq.set(word, current + 1);
        }

        const letterFreq = new Map();
        for (const l of pattern.split("")) {
            if (!letterFreq.has(l)) {
                letterFreq.set(l, 0);
            }

            const current = letterFreq.get(l);
            letterFreq.set(l, current + 1);
        }


        const reverseWordMap = new Map();
        const reverseLetterMap = new Map();

        for (const [key, value] of wordFreq) {
            if (!reverseWordMap.has(value)) {
                reverseWordMap.set(value, []);
            }

            const current = reverseWordMap.get(value);
            reverseWordMap.set(value, [...current, key]);
        }


        for (const [key, value] of letterFreq) {
            if (!reverseLetterMap.has(value)) {
                reverseLetterMap.set(value, []);
            }

            const current = reverseLetterMap.get(value);
            reverseLetterMap.set(value, [...current, key]);
        }

        for (const [key, value] of reverseWordMap) {
            const patternV = reverseLetterMap.get(key) ?? [];
            if (value.length !== patternV.length) return false;
        }


        return true;
    }
}
