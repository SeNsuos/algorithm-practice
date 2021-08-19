//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [3,4,3,3]
//输出：4
// 
//
// 示例 2： 
//
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10000 
// 1 <= nums[i] < 2^31 
// 
//
// 
// Related Topics 位运算 数组 👍 218 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < 32; ++i) {//计算二进制的每一位

        int sum = 0;
        for(int& num : nums) //计算每个数在二进制的同一位上的贡献
            sum += (num >> i) & 1;
        if(sum%3) //出现1，则要还原到原位
            ans|= 1 << i;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution* solution = new Solution();
    vector<int> vec{9,1,7,9,7,9,7};
    cout << solution->singleNumber(vec) << endl;
}