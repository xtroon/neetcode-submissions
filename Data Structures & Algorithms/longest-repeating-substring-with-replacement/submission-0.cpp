class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for(char ch : charSet){
            int cnt= 0, l = 0;

            for(int r=0; r<s.size(); r++){
                if(s[r] == ch) cnt++;

                while((r-l+1)-cnt > k){
                    if(ch == s[l]) cnt--;
                    l++;
                }

                res = max(res, r-l+1);
            }
        }

        return res;
    }
};