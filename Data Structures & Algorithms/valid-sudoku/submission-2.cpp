class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rowC, colC, sqC;

        for(int row = 0; row < 9; row ++){
            for(int col = 0; col < 9; col ++){

                char ch = board[row][col];
                if(ch == '.') continue;

                int box = (row/3)*3 + col/3;

                if(rowC[row].find(ch) != rowC[row].end()) return false;
                if(colC[col].find(ch) != colC[col].end()) return false;
                if(sqC[box].find(ch) != sqC[box].end()) return false;

                rowC[row].insert(ch);
                colC[col].insert(ch);
                sqC[box].insert(ch);
            }
        }


        return true;
    }
};