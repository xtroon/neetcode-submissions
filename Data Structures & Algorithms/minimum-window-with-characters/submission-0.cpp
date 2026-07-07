class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(256, 0), window(256, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int matched = 0;

        int start = -1;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            // Expand window
            char ch = s[right];
            window[ch]++;

            if (need[ch] > 0 && window[ch] <= need[ch])
                matched++;

            // Shrink window
            while (matched == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if (need[remove] > 0 && window[remove] < need[remove])
                    matched--;

                left++;
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};