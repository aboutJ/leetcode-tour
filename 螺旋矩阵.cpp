#include "header.h"

class Solution {
    static constexpr  int directions[4][2] = {{0, 1}, {1, 0}, {0,-1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();

        vector<vector<bool>> visited(row, vector<bool>(col));

        vector<int> record;
        int r = 0;
        int c = 0;
        int direction = 0;

        for(int i=0;i < col * row;i++) {
            record.push_back(matrix[r][c]);
            int nextRow = directions[direction][0] + r;
            int nextCol = directions[direction][1] + c;
            visited[r][c] = true;
            if (nextRow < 0 || nextCol < 0 || nextRow >= row || nextCol >= col || visited[nextRow][nextCol]) {
                direction = (direction + 1) % 4;
            }

            r += directions[direction][0];
            c += directions[direction][1];
        }
        return record;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},{4,5,6},{7,8,9}
    };

    Solution s;
    s.spiralOrder(matrix);
    return 0;
}