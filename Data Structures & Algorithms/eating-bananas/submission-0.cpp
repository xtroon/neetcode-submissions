class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        int lo = 1, hi = maxi;
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int time = 0;

            for(int i =0; i < piles.size(); i++){
                time += ceil((double)piles[i]/mid);
                if(time > h) break;
            }

            if(time <= h){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};