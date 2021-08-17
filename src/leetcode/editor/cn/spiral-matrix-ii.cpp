//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 👍 462 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> vec(n, vector<int>(n, 0));
            int left = 0, right = n - 1, top = 0, bottom = n - 1;
            int count = 1, max = n * n;
            while (count <= max) {
                for (int i = left; i <= right; ++i) { // left to right
                    vec[top][i] = count;
                    count++;
                }
                top++;
                for (int i = top; i <= bottom; ++i) { // top to bottom
                    vec[i][right] = count;
                    count++;
                }
                right--;
                for (int i = right; i >= left; --i) { // right to left
                    vec[bottom][i] = count;
                    count++;
                }
                bottom--;
                for (int i = bottom; i >= top; --i) { // bottom to top
                    vec[i][left] = count;
                    count++;
                }
                left++;
            }

            return vec;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
