//给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。 
//
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "hello"
//输出："holle"
// 
//
// 示例 2： 
//
// 
//输入：s = "leetcode"
//输出："leotcede" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由 可打印的 ASCII 字符组成 
// 
// Related Topics 双指针 字符串 👍 203 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> map {
            {'a', true},
            {'e', true},
            {'i', true},
            {'o', true},
            {'u', true}
        };
        string::iterator begin = s.begin(), end = s.end() - 1;
        int i = 0;
        while (begin < end) {
            if (map[tolower(*begin)] && map[tolower(*end)]) {
                char temp = *begin;
                *begin = *end;
                *end = temp;
                begin++;
                end--;
                continue;
            }
            if (!map[tolower(*begin)]) begin++;
            if (!map[tolower(*end)]) end--;
        }

        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution* solution = new Solution();
    string s = "leetcode";

    cout << solution->reverseVowels(s) << endl;
}