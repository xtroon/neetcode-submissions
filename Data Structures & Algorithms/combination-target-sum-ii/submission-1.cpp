class Solution {
public:
    set<vector<int>> res;
    void solve(int i, vector<int>& nums, int tar, vector<int> temp){
        if(tar == 0){
            res.insert(temp);
            return;
        }

        if( i >= nums.size() || tar < 0) 
            return;

        //include + next
        temp.push_back(nums[i]);
        solve(i+1, nums, tar-nums[i], temp);


        //exclude + next
        temp.pop_back();

        //skipping similars
        while(i+1 < nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        solve(i+1, nums, tar, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(0, candidates, target, temp);
        return vector<vector<int>>(res.begin(), res.end());
    }
};