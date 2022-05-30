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
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

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

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    stack<int> sk;
    priority_queue<int, vector<int>, greater<> > pq1;
    priority_queue<int, vector<int>, greater<> > pq2;
    void push(int value) {
        sk.push(value);
        pq1.push(value);
    }
    void pop() {
        if (sk.top() == pq1.top()) {
            pq1.pop();
        } else {
            pq2.push(sk.top());
        }
        while (!pq1.empty() && !pq2.empty() && pq1.top() == pq2.top()) {
            pq1.pop();
            pq2.pop();
        }
        sk.pop();
    }
    int top() {
        return sk.top();
    }
    int min() {
        return pq1.top();
    }
};

int main() {
    auto *a = new Solution();
    vector<int> preorder = {4, 2};
    ListNode* one = new ListNode(1);
    ListNode* one1 = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* four1 = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* seven = new ListNode(7);

    one->next = four;
    four->next = five;
    one1->next = three;
    three->next = four1;
    two->next = six;
    vector<ListNode*> lists = {one, one1, two};

    vector<int> rotateArray = {1, 0, 1, 1, 1};
    a->push(9);
    a->push(6);
    a->push(1);
    cout << a->min() << endl;
    a->pop();
    cout << a->min() << endl;
}

