class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = 0, hi = m*n - 1;

        while(low <= hi){
            int mid = low + ((hi - low) >> 1);

            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) hi = mid -1;
            else low = mid + 1;
        }

        return false;
    }
};