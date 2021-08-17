//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。 
//
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 523 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
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
    unordered_map<int, int> hashMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 前序遍历 [root [left_subtree] [right_subtree]]
        // 中序遍历 [[left_subtree] root [right_subtree]]
        vector<int>::size_type size = inorder.size();
        for (int i = 0; i < size; ++i) {
            // 建立哈希映射
            hashMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, size - 1, 0, size - 1);
    }

    TreeNode* build(
            const vector<int>& preorder,
            const vector<int>& inorder,
            int preorderLeft,
            int preorderRight,
            int inorderLeft,
            int inorderRight
            ) {
        if (preorderLeft > preorderRight) return nullptr;

        // 前序遍历的根节点 -> 第一个元素
        int preorderRoot = preorderLeft;
        // 中序遍历
        int inorderRoot = hashMap[preorder[preorderRoot]];
        // 创建根节点
        TreeNode* root = new TreeNode(preorder[preorderRoot]);
        // 左子树节点数目
        int leftTreeNodeSize = inorderRoot - inorderLeft;
        // 递归创建左子树
        // 前序遍历的左边界+1开始的leftTreeNodeSize个元素对应中序遍历中从左边界开始到根节点-1的元素
        root->left = build(preorder, inorder, preorderLeft + 1, preorderLeft + leftTreeNodeSize, inorderLeft, inorderRoot - 1);
        // 递归创建右子树
        // 前序遍历的左边界+1+leftTreeNodeSize开始到右边界的元素对应中序遍历中从根节点+1到右边界的元素
        root->right = build(preorder, inorder, preorderLeft + 1 + leftTreeNodeSize, preorderRight, inorderRoot + 1, inorderRight);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution *solution = new Solution();
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
}