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

// 哈希映射
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* newHead = new Node(head->val);
        Node* pre = newHead;
        Node* tmp = head->next;
        unordered_map<Node* , Node*>record;
        record[head] = newHead;
        while (tmp) {
            Node* curr = new Node(tmp->val);
            record[tmp] = curr;
            pre->next = curr;
            pre = curr;
            tmp = tmp->next;
        }

        while (head) {
            Node * curr = record[head];
            if (head && head->random) curr->random = record[head->random];
            head = head->next;
        }

        return newHead;
    }
};

int main() {
    auto *solution = new Solution();
    Node* seven = new Node(7);
    Node* thirteen  = new Node(13);
    Node* eleven = new Node(11);
    Node* ten = new Node(10);
    Node* one = new Node(1);
    seven->next = thirteen;
    thirteen->next = eleven;
    eleven->next = ten;
    ten->next = one;
    thirteen->random = seven;
    eleven->random = one;
    ten->random = eleven;
    one->random = seven;


    solution->copyRandomList(seven);
}
