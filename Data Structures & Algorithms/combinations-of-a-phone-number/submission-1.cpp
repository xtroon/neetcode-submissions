class Solution {
public:
    void solve(string& dig, unordered_map<char, string>& hash, int idx, string str, vector<string>& ans){
        if(idx == dig.size()){
            ans.push_back(str);
            return;
        }
        string letter = hash[dig[idx]];

        for(char ch : letter){
            str.push_back(ch);
            solve(dig, hash, idx+1, str, ans);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> hash = {
            {'2', "abc"}, 
            {'3', "def"},
            {'4', "ghi"}, 
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"}, 
            {'8', "tuv"}, 
            {'9', "wxyz"}
        };

        vector<string> ans;
        if(!digits.size()) return ans;
        solve(digits, hash, 0, "", ans);
        return ans;
    }
};