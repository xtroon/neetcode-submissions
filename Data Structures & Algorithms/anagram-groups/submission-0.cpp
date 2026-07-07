class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};
        vector<vector<string>> ans;
        vector<pair<string, int>> temp;

        for(int i=0; i<strs.size(); i++){
            temp.push_back({strs[i], i});
        }

        for(int i=0; i<temp.size(); i++){
            sort(temp[i].first.begin(), temp[i].first.end());
        }
        
        sort(temp.begin(), temp.end());

        int i =0;
        while( i < strs.size()){
            vector<string> each;
            each.push_back(strs[temp[i].second]);
            while(i+1 < strs.size() &&temp[i].first == temp[i+1].first){
                each.push_back(strs[temp[i+1].second]);
                i++;
            }
            ans.push_back(each);
            i++;
        }
        return ans;
    }
};