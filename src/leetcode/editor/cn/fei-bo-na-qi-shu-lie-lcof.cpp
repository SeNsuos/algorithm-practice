//写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下： 
//
// 
//F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1. 
//
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。 
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：n = 5
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 100 
// 
// Related Topics 记忆化搜索 数学 动态规划 
// 👍 180 👎 0

#include "iostream"
#include "vector"

using namespace std;

// f(n) = f(n - 1) + f(n - 2) (n >= 3)

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n == 1 ? 1 : 0;

        int x = 0, y = 1, z = 0;
        for (int i = 2; i <= n; ++i) {
            x = (y + z) % 1000000007;
            z = y;
            y = x;
        }

        return x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    // n = 2
    Solution* solution = new Solution();

    int res2 = solution->fib(2);
    int res5 = solution->fib(45);

    cout << "res2: " << res2 << " "
         << "res5: " << res5 << " "
         << endl;
}
