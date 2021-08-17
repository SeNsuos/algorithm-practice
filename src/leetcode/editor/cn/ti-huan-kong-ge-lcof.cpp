//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// Related Topics 字符串 
// 👍 145 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        int length = s.length();
        int spaceCount = 0;
        for (char str : s) {
            if (str == ' ') spaceCount++;
        }

        int size = length + 2 * spaceCount;

        s.resize(size);

        for (int i = length - 1, j = size - 1; j > i; --i, --j) {
            if (s.at(i) != ' ') {
                s[j] = s[i];
            } else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }

        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
