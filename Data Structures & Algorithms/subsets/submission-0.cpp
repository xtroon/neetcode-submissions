class Solution {
public:
    void solve(vector<vector<int>>& ans, int i, vector<int> &nums, vector<int> temp){
        if( i == nums.size() ){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        solve(ans, i+1, nums, temp);

        //not take - backtrack
        temp.pop_back();
        solve(ans, i+1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, 0, nums, temp);
        
        return ans;
    }
};