class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            set<char>rows;
            set<char>cols;
            for(int j=0; j<9; j++){
                if(rows.find(board[i][j]) == rows.end()||board[i][j]=='.'){
                    rows.insert(board[i][j]);
                }
                else{
                    return false;
                }
                if(cols.find(board[j][i]) == cols.end()||board[j][i]=='.'){
                    cols.insert(board[j][i]);
                }
                else{
                    return false;
                }
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int x = i * 3, y = j * 3;
                set<char>_set;
                for(int m=0;m<3;m++){
                    for(int n=0;n<3;n++){
                        if(_set.find(board[x+m][y+n]) == _set.end()||board[x+m][y+n]=='.'){
                            _set.insert(board[x+m][y+n]);
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};