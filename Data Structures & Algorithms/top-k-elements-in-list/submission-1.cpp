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
        int m = store.size();

        //store elements such, at index m-k -> smaller left to it, bigger right to it.
        // the element that would be there if the array were fully sorted.
        nth_element(store.begin(), store.begin() + (m-k), store.end());

        vector<int> ans;
        for(int i=m-k; i<m; i++){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};