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


//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//        int index1 = 0, index2 = 0, count = 0;
//        string res;
//        while (index1 < num1.size() && index2 < num2.size()) {
//            int next = (num1[index1++] - '0') * (num2[index2++] - '0') + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        while (index1 < num1.size()) {
//            int next = num1[index1++] - '0' + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        while (index2 < num2.size()) {
//            int next = num2[index2++] - '0' + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        reverse(res.begin(), res.end());
//
//        return res;
//    }
//};


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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        vector<TreeNode*> p_r;
        vector<TreeNode*> q_r;
        TreeNode *curr = root;
        while(curr->val != p->val) {
            p_r.push_back(curr);
            if (curr->val > p->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        *curr = root;
        while(curr->val != q->val) {
            q_r.push_back(curr);
            if (curr->val > q->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        unordered_map<int, int> record;
        for (int i = p_r.size() - 1; i >= 0; i--) {
            record[p_r[i]->val]++;
        }

        for (int i = q_r.size() - 1; i >= 0; i--) {
            record[q_r[i]->val]--;
            if(record[q_r[i]->val] == 0) return q_r[i];
        }

        return NULL;
    }
};

int main() {
    int a[3] = {1, 4, 5};
    int b[3] = {1, 3, 4};
    int c[2] = {2, 6};

    ListNode *aa = createLinkedList(a, 3);
    ListNode *bb = createLinkedList(b, 3);
    ListNode *cc = createLinkedList(c, 2);

    vector<ListNode *> lists = {aa, bb, cc};
    cout << (1&4) << (1 & 1) << (1 & 6) ;
    Solution solution = Solution();
    vector <int> d = {4,1,4,6};
    solution.lowestCommonAncestor(d);


}

