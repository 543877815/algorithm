/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// 深度优先遍历+栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <math.h>

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int in_val, Node *in_prev, Node *in_next, Node *in_child) : val(in_val), prev(in_prev), next(in_next),
                                                                     child(in_child) {
    }
};

class Solution {
public:
    Node *flatten(Node *head) {
        Node *curr = head;
        stack < Node * > sk;
        while (curr) {
            if (curr->child) {
                sk.push(curr->next);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if (!curr->next) {
                while (!sk.empty() && !sk.top()) sk.pop();
                if (!sk.empty()) {
                    curr->next = sk.top();
                    sk.top()->prev = curr;
                    sk.pop();
                }
            }
            curr = curr->next;
        }
        return head;

    }
};

int main() {
    Node one = Node(1, nullptr, nullptr, nullptr);
    Node two = Node(2, nullptr, nullptr, nullptr);
    Node three = Node(3, nullptr, nullptr, nullptr);
    Node four = Node(4, nullptr, nullptr, nullptr);
    Node five = Node(5, nullptr, nullptr, nullptr);
    Node six = Node(6, nullptr, nullptr, nullptr);
    Node seven = Node(7, nullptr, nullptr, nullptr);
    Node eight = Node(8, nullptr, nullptr, nullptr);
    Node nine = Node(9, nullptr, nullptr, nullptr);
    Node ten = Node(10, nullptr, nullptr, nullptr);
    Node eleven = Node(11, nullptr, nullptr, nullptr);
    Node twelve = Node(12, nullptr, nullptr, nullptr);
    one.next = &two;
    two.prev = &one;
    two.next = &three;
    three.prev = &two;
    three.next = &four;
    four.prev = &three;
    four.next = &five;
    five.prev = &four;
    five.next = &six;
    six.prev = &five;
    three.child = &seven;
    seven.next = &eight;
    eight.prev = &seven;
    eight.next = &nine;
    nine.prev = &eight;
    nine.next = &ten;
    ten.prev = &nine;
    eight.child = &eleven;
    eleven.next = &twelve;
    twelve.prev = &eleven;

    Solution c = Solution();
    c.flatten(&one);
}