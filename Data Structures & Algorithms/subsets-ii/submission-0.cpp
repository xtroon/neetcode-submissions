class Solution {
public:
    vector<vector<int>> ss;
    
    void solve(int idx, vector<int>& nums, vector<int>& temp){
        if(idx == nums.size()){
            ss.push_back(temp);
            return;
        }

        //take + next
        temp.push_back(nums[idx]);
        solve(idx+1, nums, temp);

        while(idx+1 < nums.size() && nums[idx]==nums[idx+1]) idx++;

        //backtrack
        temp.pop_back();
        solve(idx+1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, nums, temp);
        return vector<vector<int>>(ss.begin(), ss.end());
    }
};