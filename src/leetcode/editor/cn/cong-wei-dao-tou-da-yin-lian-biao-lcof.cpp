//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 栈 递归 链表 双指针 
// 👍 168 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> vec;
        if (head == NULL) return vec;
        ListNode* ptr = head;
        while(ptr != NULL) {
            stk.push(ptr->val);
            ptr = ptr->next;
        }

        while(!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }

        return vec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution* solution = new Solution();


}