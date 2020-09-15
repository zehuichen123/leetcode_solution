class Solution {
public:
    bool checkCol(vector<vector<char>>&board, int col_num){
        set<char>_set;
        for(int i=0; i<9; i++){
            if(_set.find(board[i][col_num]) == _set.end()||board[i][col_num]=='.'){
                _set.insert(board[i][col_num]);
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool checkRow(vector<vector<char>>&board, int row_num){
        set<char>_set;
        for(int i=0; i<9; i++){
            if(_set.find(board[row_num][i]) == _set.end()||board[row_num][i]=='.'){
                _set.insert(board[row_num][i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>&board, int x, int y){
        set<char>_set;
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(_set.find(board[i][j]) == _set.end()||board[i][j]=='.'){
                    _set.insert(board[i][j]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    bool findSolution(vector<vector<char>>& board, int count){
        if(count < 81){
            int col_num = count / 9, row_num = count % 9;
            if(board[row_num][col_num] == '.'){
                for(int i=0; i<9; i++){
                    board[row_num][col_num] = i + '1';
                    // if(board[6][0] == '9' ){
                    //     for(auto m: board){
                    //         for(auto n: m){
                    //             cout<<n<<" ";
                    //         }
                    //         cout<<endl;
                    //     }
                    // }
                    int x_index = row_num / 3, y_index = col_num / 3;
                    if(!checkCol(board, col_num)){
                        continue;
                    }
                    if(!checkRow(board, row_num)){
                        continue;
                    }
                    if(!checkBox(board, x_index*3, y_index*3)){
                        continue;
                    }
                    if(findSolution(board, count +1)){
                        return true;
                    }
                    board[row_num][col_num] = '.';
                }
                board[row_num][col_num] = '.';
                return false;
            }
            else{
                if(findSolution(board, count+1)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        else{
            return true;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool tmp = findSolution(board, 0);
    }
};