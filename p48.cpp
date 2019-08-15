class Solution {
public:
    int X;
    void swapFourElement(vector<vector<int>>& matrix, int x, int y){
        int tmp = matrix[x][y];
        matrix[x][y] = matrix[X-1-y][x];
        matrix[X-1-y][x] = matrix[X-1-x][X-1-y];
        matrix[X-1-x][X-1-y] = matrix[y][X-1-x];
        matrix[y][X-1-x] = tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        X = matrix.size();
        for(int i=0; i<X/2; i++){
            for(int j=i; j<X-1-i; j++){
                swapFourElement(matrix, i, j);
            }
        }
    }
};