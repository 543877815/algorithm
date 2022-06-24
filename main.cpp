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
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        if (m == 0) return a;
        m = m % n;
        int tmp = -1;
        int last = n - 1;
        while (last >= n - m) {
            int idx = last - (n - m);
            if (tmp == -1) tmp = a[idx];
            a[idx] = a[last--];
            while(idx < n - m) {
                idx += m;
                swap(tmp, a[idx]);
            }
        }

        return a;
    }
};

int main() {
    vector<int> aa = {2, 3, 1, 1, 4};
    vector<int> bb = {1,2,3,4,5,6,7};
    vector<vector<int>> ss = {{5, 4},
                              {6, 4},
                              {6, 7},
                              {2, 3}};
    auto *a = new Solution();
    string stra = "dbbca";
    string strb = "aabcc";
    string strc = "aadbbcbcac";
    a->solve(7, 2, bb);

    ListNode *one = new ListNode(1);
    ListNode *one1 = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *four1 = new ListNode(4);
    ListNode *five = new ListNode(5);
    ListNode *six = new ListNode(6);
    ListNode *seven = new ListNode(7);

    one->next = four;
    four->next = five;
    one1->next = three;
    three->next = four1;
    two->next = six;
    vector<ListNode *> lists = {one, one1, two};

    vector<int> rotateArray = {1, 0, 1, 1, 1};

}

