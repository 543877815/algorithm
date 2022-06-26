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
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;


        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff[i] = nums1[i] - nums2[i];
        }


        int res = max(sum1, sum2);
        int accu = diff[0];
        for (int i = 1; i < n; i++) {
            if (accu > 0) {
                if (diff[i] > 0) accu += diff[i];
                else {
                    res = max(res, sum2 + abs(accu));
                    accu = diff[i];
                }
            } else {
                if (diff[i] < 0) accu += diff[i];
                else {
                    res = max(res, sum1 + abs(accu));
                    accu = diff[i];
                }
            }
        }



        return res;
    }
};


int main() {
    vector<int> aa = {60,60,60};
    vector<int> bb = {10,90,10};
//    vector<vector<int>> ss = {{0,1}, {0,2}, {1,2}};
    vector<vector<int>> ss = {{0, 2},
                              {0, 5},
                              {2, 4},
                              {1, 6},
                              {5, 4}};
    auto *a = new Solution();
    string stra = "dbbca";
    string strb = "aabcc";
    string strc = "aadbbcbcac";
    a->maximumsSplicedArray(aa, bb);

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

