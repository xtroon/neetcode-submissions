class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prod = 1;

        for(int i=1; i<n; i++){
            prod *= nums[i-1];
            ans[i] = prod;
        }
        // 1 1 2 6
        prod = 1;
        for(int i=n-2; i>=0; i--){
            prod *= nums[i+1];
            ans[i] *= prod;
        }
        //  1 1 2 6
        return ans;
    }
};