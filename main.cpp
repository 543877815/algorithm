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
struct cmp {
    bool operator()(ListNode*a, ListNode*b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;

        ListNode *dummyHead = new ListNode(-1001);
        ListNode *curr = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode *node: lists) {
            if (node) {
                pq.push(node);
            }
        }


        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next) pq.push(curr->next);
        }

        return dummyHead->next;

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
    a->mergeKLists(lists);
}