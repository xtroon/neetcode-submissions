class Solution {
public:
    void solve(int i, vector<int>& nums, int tar, vector<vector<int>> &ans, vector<int> temp){
        if( i >= nums.size() || tar < 0) 
            return;

        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        //include + stayy
        if(nums[i] <= tar){
            temp.push_back(nums[i]);
            solve(i, nums, tar-nums[i], ans, temp);
            temp.pop_back();
        }

        //exclude + next
        solve(i+1, nums, tar, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, ans, temp);

        return ans;
    }
};