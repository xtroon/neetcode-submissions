class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char ch : s) {
            if (isalnum(ch)) {
                if (ch >= 'A' && ch <= 'Z') {
                    t += (ch + 32);
                }else{
                    t += ch;
                }
            }
        }
        string m = t;
        reverse(t.begin(), t.end());
        return m==t;
    }
};