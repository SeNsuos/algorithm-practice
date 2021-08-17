//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
//请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
//。 
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 提示： 
//
// 
// 2 <= n <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划 
// 👍 282 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        // n = 3a + b;
        int a = n / 3, b = n % 3;
        // b = 0 return pow(3, a);
        // b = 1 return pow(3, a - 1) * (2 + 2);
        // b = 2 return pow(3, a) * 2;
        int res = 0;
        switch (b) {
            case 0:
                res = pow(3, a);
                break;
            case 1:
                res = pow(3, a - 1) * 4;
                break;
            case 2:
                res = pow(3, a) * 2;
                break;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution* solution = new Solution();

    cout << solution->cuttingRope(2) << endl;
    cout << solution->cuttingRope(10) << endl;
}