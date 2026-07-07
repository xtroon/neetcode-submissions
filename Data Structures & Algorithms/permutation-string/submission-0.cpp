class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1_freq(26, 0);
        vector<int> freq(26,0);

        for (char c : s1) {
            s1_freq[c - 'a']++;
        }

        int l=0, r=0, n=s2.size();
        while(r < n){
            freq[s2[r]-'a']++;

            if(r-l+1 > s1.size()){
                freq[s2[l]-'a']--;
                l++;
            }

            if(s1_freq == freq) return true;

            r++;
        }

        return false;
    }
};