class Solution {
public:
    void solve(int st, int en, int n, string curr, vector<string>& ans){
        if(2*n == curr.size()){
            ans.push_back(curr);
            return;
        }

        if(st < n) solve(st+1, en, n, curr + "(", ans);
        if(en < st) solve(st, en+1,n, curr + ")", ans);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};
