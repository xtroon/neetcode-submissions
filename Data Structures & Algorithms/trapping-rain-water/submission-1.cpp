class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //left max
        vector<int> left(n, -1);
        int lMax = height[0];
        for(int i=0; i<n; i++){
            lMax = max(lMax, height[i]);
            left[i] = lMax;
        }

        //right max
        vector<int> right(n, -1);
        int rMax = height[n-1];
        for(int i=n-1; i>=0; i--){
            rMax = max(rMax, height[i]);
            right[i] = rMax;
        }

        int ans = 0;
        // 1 + (0) + 1 + 2 + 1 + (0) + 0 + 1 + 0 
        for(int i=1; i<n-1; i++){
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};