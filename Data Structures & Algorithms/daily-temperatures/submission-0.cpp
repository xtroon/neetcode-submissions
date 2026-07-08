class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();

            if(st.empty()) v[i] = 0;
            else v[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++){
            if(v[i] == 0) continue;
            v[i] = v[i] - i;
        }
        return v;
    }
};