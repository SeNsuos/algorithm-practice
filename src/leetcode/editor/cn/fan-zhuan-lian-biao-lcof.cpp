//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
//
// 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 
// Related Topics 递归 链表 
// 👍 275 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *cur = head, *tail = NULL;
        ListNode *tmp = cur->next;
        cur->next = tail;
        tail = tmp;

        while (tail != NULL) {
            ListNode *temp = tail->next;
            tail->next = cur;
            cur = tail;
            tail = temp;
        }

        return cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
