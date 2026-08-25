class Solution {
public:
    vector<vector<string>> ans;

    bool isValid(vector<string> board, int row, int col){
        
        //check vertical
        for(int i = row; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }
        // check top left 
        for(int i=row,j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        // check top right 
        for(int i=row,j=col; i>=0 && j<board.size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(vector<string> board, int row, int n){
        if(row >= n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solve(board, row+1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};