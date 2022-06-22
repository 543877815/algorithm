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





//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * s1和s2最长公共子序列的长度
//     * @param s1 string字符串
//     * @param s2 string字符串
//     * @return int整型
//     */
//
//    vector<vector<int>> dp;
//
//    int search(string &s1, string &s2, int i, int j) {
//        if (i == 0 || j == 0) {
//            if (s1[i] == s2[j]) {
//                return 1;
//            } else return 0;
//        }
//        if (s1[i] == s2[j]) dp[i][j] = search(s1, s2, i - 1, j - 1) + 1;
//        else dp[i][j] = max(search(s1, s2, i - 1, j), search(s1, s2, i, j - 1));
//
//        return 0;
//    }
//
//    int LCS(string s1, string s2) {
//        // write code here
//        int n = s1.size(), m = s2.size();
//        string res = "";
//        if (n == 0 || m == 0) return 0;
//        // dp[i][j] 表示 s1 前 i 个字符和 s2 前 j 个字符的最长公共子序列
//        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
//        dp[n - 1][m - 1] = search(s1, s2, n - 1, m - 1);
//
//        return dp[n - 1][m - 1];
//    }
//};


class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> res;

    bool isValid(string &s) {
        if ((s.size() > 1 && s[0] == '0') || s.size() > 3)
            return false;
        return stoi(s) < 256;
    }

    void backtrack(string &s, vector<string> curr, int idx) {
        int n = s.size();
        if (curr.size() == 4) {
            if (n == idx) res.push_back(curr[0] + "." + curr[1] + "." + curr[2] + "." + curr[3]);
            return;
        }

        int i = 1;
        while (i <= 3 && idx + i < n) {
            string temp = s.substr(idx, i);
            if (isValid(temp)) {
                curr.push_back(temp);
                backtrack(s, curr, idx + i);
                curr.pop_back();

                i++;
            } else break;
        }

    }

    vector<string> restoreIpAddresses(string s) {
        // write code here
        vector<string> curr;
        backtrack(s, curr, 0);
        return res;
    }
};

int main() {
    vector<int> aa = {8, 4, 5, 0, 0, 0, 0, 7};
    vector<int> bb = {-2, -8, -1, -5, -9};
    auto *a = new Solution();
    string s = "1111";
    a->restoreIpAddresses(s);

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

