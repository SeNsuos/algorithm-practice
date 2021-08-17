//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 数组 回溯 矩阵 
// 👍 377 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(),
            column = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (visit(i, j, row, column, board, word, 0)) return true;
            }
        }

        return false;
    }
    bool visit(int i, int j, int row, int column, vector<vector<char>>& board, string word, int count) {
        if (i < 0 || j < 0 || i >= row || j >= column || word.at(count) != board[i][j]) return false;
        if (count == word.size() - 1) return true;

        board[i][j] = '\0';

        bool result = visit(i + 1, j, row, column, board, word, count + 1) ||
                      visit(i, j + 1, row, column, board, word, count + 1) ||
                      visit(i - 1, j, row, column, board, word, count + 1) ||
                      visit(i, j - 1, row, column, board, word, count + 1);

        board[i][j] = word[count];
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution* solution = new Solution();
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board2 {
        {'a', 'b'},
        {'c', 'd'}
    };

    vector<vector<char>> board3 {
        {'a', 'b'}
    };

    bool res = solution->exist(board, "ABCCED");
    bool res1 = solution->exist(board2, "abcd");
    bool res2 = solution->exist(board3, "ba");

    cout << res << " " << res1 << " " << res2 << endl;
}