#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <queue>
#include <assert.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

class StackOfPlates {
private:
    int maxSize;
    vector<stack<int>> stacks;

public:
    StackOfPlates(int cap) {

        maxSize = cap;
    }

    void push(int val) {
        if (stacks.size() == 0) {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
        } else {
            stack<int> *s = &stacks.back();
            if (s->size() >= maxSize) {
                stack<int> tmp;
                tmp.push(val);
                stacks.push_back(tmp);
            } else {
                stacks.back().push(val);
            }
        }
    }

    int pop() {
        if (stacks.empty()) return -1;
        stack<int> *s = &stacks.back();
        int num = s->top();
        s->pop();
        if (s->empty()) stacks.pop_back();
        return num;
    }

    int popAt(int index) {
        if (stacks.empty() || stacks.size() <= index) return -1;
        stack<int> *s = &stacks[index];
        if (s->empty()) return -1;
        int num = s->top();
        s->pop();
        if (s->size() == 0) stacks.erase(remove(stacks.begin(), stacks.end(), *s), stacks.end());
        return num;
    }
};

int main() {
    StackOfPlates *solution = new StackOfPlates(2);
    solution->push(1);
    solution->push(2);
    solution->push(3);
    solution->popAt(0);
    solution->popAt(0);
    solution->popAt(0);
//    solution->push(1);
//    solution->push(2);
//    solution->popAt(1);
//    solution->pop();
//    solution->pop();
}
