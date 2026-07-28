class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string first = "";
        char mid;

        for (int i = 0; i < 26; i++) {
            first += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2)
                mid = 'a' + i;
        }

        string second(first.rbegin(), first.rend());

        if (s.length() % 2)
            return first + mid + second;

        return first + second;
    }
};