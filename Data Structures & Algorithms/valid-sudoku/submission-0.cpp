class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> r,c;

        map<pair<int,int>,unordered_set<char>> square;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                pair<int,int> key = {i/3,j/3};
                if(r[i].count(board[i][j]) || c[j].count(board[i][j]) || square[key].count(board[i][j])){
                    return false;
                }
                r[i].insert(board[i][j]);
                c[j].insert(board[i][j]);
                square[key].insert(board[i][j]);
            }

        }
        return true;
    }
};
