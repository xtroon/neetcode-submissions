class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }

        vector<pair<int, int>> store;
        for(auto [num, freq] : hash){
            store.push_back({freq, num});
        }

        sort(store.rbegin(), store.rend());

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};