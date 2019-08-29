class Solution {
public:
    int height, width;
    void dfs(int x, int y, vector<vector<char>>& board){
        if(x < height && x >= 0 && y < width && y >= 0 && board[x][y] == 'O'){
            board[x][y] = '*';
            dfs(x+1, y, board);
            dfs(x, y+1, board);
            dfs(x-1, y, board);
            dfs(x, y-1, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        height = board.size();
        if(height == 0){
            return;
        }
        width = board[0].size();
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(i != 0 && i != height-1 && j != 0 && j != width-1){
                    continue;
                }
                if(board[i][j] == 'O'){
                    dfs(i, j, board);
                }
            }
        }
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};