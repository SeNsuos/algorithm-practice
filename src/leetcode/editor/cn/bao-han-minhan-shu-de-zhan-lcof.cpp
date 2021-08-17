//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 
//
// 
//
// 示例: 
//
// MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.min();   --> 返回 -2.
// 
//
// 
//
// 提示： 
//
// 
// 各函数的调用总次数不超过 20000 次 
// 
//
// 
//
// 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/ 
// Related Topics 栈 设计 
// 👍 164 👎 0


#include <iostream>
#include "vector"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
    stack<int> left, right;
public:
    /** initialize your data structure here. */
    MinStack() {
        if (!left.empty()) {
            left.pop();
        }
        if (!right.empty()) {
            right.pop();
        }
    }
    
    void push(int x) {
        if (left.empty()) {
            right.push(x);
        } else {
            int value = right.top();
            if (x <= value) {
                right.push(x);
            }
        }
        left.push(x);
    }
    
    void pop() {
        if (!right.empty() && left.top() == right.top()) {
            right.pop();
        }

        left.pop();
    }
    
    int top() {
        return left.top();
    }
    
    int min() {
        return right.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    MinStack* obj = new MinStack;
    obj->push(-2);
    obj->push(0);
    obj->push(-1);
    cout << obj->min() << endl;
    cout << obj->top() << endl;
    obj->pop();
    cout << obj->min() << endl;
}