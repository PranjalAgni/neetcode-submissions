class Solution {

    computeFrequencyMap(array) {
        const freqMap = new Map();
        for (const data of array) {
            if (!freqMap.has(data)) {
                freqMap.set(data, 0);
            }

            const current = freqMap.get(data);
            freqMap.set(data, current + 1);
        }

        return freqMap;
    }

    computeReverseFreq(freqMap) {
        const reverseFreqMap = new Map();
        for (const [key, value] of freqMap) {
            if (!reverseFreqMap.has(value)) {
                reverseFreqMap.set(value, []);
            }

            const current = reverseFreqMap.get(value);
            reverseFreqMap.set(value, [...current, key]);
        }

        return reverseFreqMap;
    }

    /**
     * @param {string} pattern
     * @param {string} s
     * @return {boolean}
     */
    wordPattern(pattern: string, s: string): boolean {
        const words = s.split(" ");
        if (words.length !== pattern.length) return false;

        const wordFreq = this.computeFrequencyMap(words);
        const letterFreq = this.computeFrequencyMap(pattern.split(""));

        const reverseWordMap = this.computeReverseFreq(wordFreq);
        const reverseLetterMap = this.computeReverseFreq(letterFreq);

        for (const [key, value] of reverseWordMap) {
            const patternV = reverseLetterMap.get(key) ?? [];
            if (value.length !== patternV.length) return false;
        }


        return true;
    }
}
