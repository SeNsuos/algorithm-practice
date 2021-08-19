//泰波那契序列 Tn 定义如下： 
//
// T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2 
//
// 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。 
//
// 
//
// 示例 1： 
//
// 输入：n = 4
//输出：4
//解释：
//T_3 = 0 + 1 + 1 = 2
//T_4 = 1 + 1 + 2 = 4
// 
//
// 示例 2： 
//
// 输入：n = 25
//输出：1389537
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 37 
// 答案保证是一个 32 位整数，即 answer <= 2^31 - 1。 
// 
// Related Topics 记忆化搜索 数学 动态规划 👍 123 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) return n == 0 ? 0 : 1;
        int x = 2, y = 1, z = 1, a = 0;

        for (int i = 3; i <= n; ++i) {
            x = y + z + a;
            a = z;
            z = y;
            y = x;
        }

        return x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution* solution = new Solution();
    int n = 25;
    cout << solution->tribonacci(25) << endl;
}