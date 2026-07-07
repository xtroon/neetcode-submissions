class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        int ans = 0;
        for(auto it : st){
            if(st.find(it -1) == st.end()){
                int count = 0;
                int x = it;

                while(st.find(x) != st.end()){
                    x = x+1;
                    count++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};