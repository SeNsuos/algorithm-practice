//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 
// 👍 120 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (nullptr != root) q.push(root);

        while(!q.empty()) {
            vector<int> temp;
            for(int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (nullptr != node->left) q.push(node->left);
                if (nullptr != node->right) q.push(node->right);
            }
            if (res.size() % 2 == 1) reverse(temp.begin(), temp.end());

            res.push_back(temp);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
