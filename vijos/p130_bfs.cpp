class Solution {
public:
    int height, width;
    class Point{
        public:
        int x;
        int y;
        Point(int i, int j){
            x = i;
            y = j;
        }
    };
    void bfs(vector<vector<char>>& board, int x, int y){
        queue<Point>_queue;
        auto tmp = Point(x, y);
        _queue.push(tmp);
        while(!_queue.empty()){
            auto _point = _queue.front();
            _queue.pop();
            int _x=_point.x;
            int _y=_point.y;
            if(_x >= 0 && _x < height && _y >=0 && _y < width && board[_x][_y] == 'O'){
                board[_x][_y] = '*';
                _queue.push(Point(_x+1, _y));
                _queue.push(Point(_x-1, _y));
                _queue.push(Point(_x, _y+1));
                _queue.push(Point(_x, _y-1));
            }
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
                    bfs(board, i, j);
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