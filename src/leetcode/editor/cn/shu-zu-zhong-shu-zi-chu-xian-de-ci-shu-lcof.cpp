//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [4,1,4,6]
//输出：[1,6] 或 [6,1]
// 
//
// 示例 2： 
//
// 输入：nums = [1,2,10,4,1,4,3,3]
//输出：[2,10] 或 [10,2] 
//
// 
//
// 限制： 
//
// 
// 2 <= nums.length <= 10000 
// 
//
// 
// Related Topics 位运算 数组 👍 449 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); ++i) {
            x ^= nums[i];
        }
        int m = x & (~x + 1);
        int y = 0, z = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & m) y ^= nums[i];
            else z ^= nums[i];
        }

        return vector<int> {y, z};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
