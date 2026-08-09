class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0;
        int water = 0;
        int i =0, j = height.size()-1;

        while(i <= j){
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);

            if(lmax < rmax){
                water += lmax - height[i];
                i++;
            }
            else{
                water += rmax - height[j];
                j--;
            }
        }
        return water;
    }
};