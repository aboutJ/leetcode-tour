#include "header.h"

// 深度优先遍历
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0;i < row;i++) {
            for(int j = 0;j < col;j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        grid[row][col] = '0';
        if(row+1 < rowLen && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if(row-1 >= 0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if(col+1 < colLen && grid[row][col+1] == '1') dfs(grid, row, col+1);
        if(col-1 >=0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
    }
};

int main() {
    vector<vector<char>> grid = {{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,0}};
    Solution s;
    cout << s.numIslands(grid);
    return 0;
}