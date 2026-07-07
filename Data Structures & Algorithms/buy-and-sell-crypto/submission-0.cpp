class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxpro = 0;

        int maxi = 0, mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            mini = min(mini, prices[i]);
            mxpro = max(mxpro, prices[i]-mini);
        }
        return mxpro;
    }
};