//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指
//向链表中的任意节点或者 null。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 示例 4： 
//
// 输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
// 
//
// 
//
// 提示： 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random 为空（null）或指向链表中的节点。 
// 节点数目不超过 1000 。 
// 
//
// 
//
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-point
//er/ 
//
// 
// Related Topics 哈希表 链表 
// 👍 249 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // O(N) O(N)
//        if (head == NULL) return NULL;
//        Node* cur = head;
//        unordered_map<Node*, Node*> map;
//        while (cur != NULL) {
//            Node *node = new Node(cur->val);
//            map[cur] = node;
//            cur = cur->next;
//        }
//        // 指针复位
//        cur = head;
//        while (cur != NULL) {
//            map[cur]->next = map[cur->next];
//            map[cur]->random = map[cur->random];
//            cur = cur->next;
//        }
//
//        return map[head];
        if (head == nullptr) return nullptr;
        Node *cur = head;
        while(cur != nullptr) {
            Node *node = new Node(cur->val);
            Node *temp = cur->next;
            cur->next = node;
            node->next = temp;
            cur = temp;
        }
        cur = head;
        while(cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head->next;
        Node *pre = head, *res = head->next;
        while(cur != nullptr) {
            pre->next = cur->next;
            cur->next = pre->next->next;
            pre = cur->next;
            cur = pre->next;
        }
        pre->next = nullptr;

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
