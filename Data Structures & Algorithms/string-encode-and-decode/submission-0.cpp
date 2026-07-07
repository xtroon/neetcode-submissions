class Solution {
  public:
    string encode(vector<string>& arr) {
        // write your logic to encode the strings
        string res;
        for(int i=0; i<arr.size(); i++){
            res += to_string(arr[i].length()) + "/:" + arr[i];
        }
        return res;
    }

    vector<string> decode(string& s) {
        // write your logic to decode the string
        int i = 0, n = s.size();
        vector<string> ans;
        while( i < n){
            
            int j = i;
            while( s[j] != '/') j++;
            
            int len = stoi(s.substr(i, j-i));
            
            j+= 2; // skiping /:
            
            ans.push_back(s.substr(j, len));
            i = j+ len;
        }
        
        return ans;
    }
};