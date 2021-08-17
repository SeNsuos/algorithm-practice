//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
// Related Topics 字符串 👍 1729 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if (!strs.size()) return "";
       else {
           return longestCommonPrefix(strs, 0, strs.size() - 1);
       }
    }
    string longestCommonPrefix(vector<string>& strs, int start, int end) {
        if (start == end) return strs[start];
        else {
            int mid = start + (end - start) / 2;
            string left = longestCommonPrefix(strs, start, mid);
            string right = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(left, right);
        }
    }
    string commonPrefix(const string& left, const string& right) {
        int minLength = min(left.size(), right.size());
        for (int i = 0; i < minLength; ++i) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }

        return left.substr(0, minLength);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution* solution = new Solution();
    vector<string> vec{ "flower","flow","flight" };
    cout << solution->longestCommonPrefix(vec) << endl;
}