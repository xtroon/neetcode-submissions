class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string& s, int i, int idx){
        string temp = s.substr(idx, i - idx + 1);
        string s2 = temp;
        reverse(s2.begin(), s2.end());
        return temp == s2;
    }
    void solve(int idx, string& s, vector<string> temp){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalin(s, i, idx)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;

        solve(0, s, temp);
        return ans;
    }
};