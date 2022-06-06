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



class TextEditor {
public:
    int curr = 0;
    string str;

    TextEditor() {

    }

    void addText(string text) {
        str.replace(str.begin() + curr, str.begin() + curr, text);
//        str = str.substr(0, curr) + text + str.substr(curr);
        curr = curr + text.size();
    }

    int deleteText(int k) {
        if (k > curr) {
            str = str.substr(curr);
            int res = min(curr, k);
            curr = 0;
            return res;
        } else {
            str.replace(str.begin() + curr - k, str.begin() + curr, "");
//            str = str.substr(0, curr - k) + str.substr(curr);
            curr -= k;
            return k;
        }
    }

    string cursorLeft(int k) {
        curr = max(curr - k, 0);
        if (curr > 10) {
            return str.substr(curr - 10, 10);
        } else {
            return str.substr(0, curr);
        }
    }

    string cursorRight(int k) {
        int n = str.size();
        curr = min(curr + k, n);
        if (curr > 10) {
            return str.substr(curr - 10, 10);
        } else {
            return str.substr(0, curr);
        }
    }
};

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector <vector<int>> &flowers, vector<int> &persons) {
        map<int, int> diff;
        for (auto &f :flowers) {
            ++diff[f[0]];
            --diff[f[1] + 1];
        }

        int n = persons.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) { return persons[i] < persons[j]; });  // 按到达时间排序，按persons升序返回索引

        vector<int> ans(n);
        auto it = diff.begin();
        int sum = 0;
        for (int i: id) {
            while (it != diff.end() && it->first <= persons[i]) sum += it++->second;
            ans[i] = sum;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> aa = {{1,6}, {3,7}, {9,12}, {4, 13}};
    vector<int> bb = {11,7,3,2};
    auto *a = new Solution();

    a->fullBloomFlowers(aa, bb);

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

