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
private:
    vector<vector<string>> res;
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while(left < right && !isalnum(s[left])) {
                left ++;
            }
            while(left < right && !isalnum(s[right])) {
                right --;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left ++;
                right --;
            }
        }
        return true;
    }

    void DFS(const string &s, int begin, vector<string> &tmp) {
        if (s.size() == begin) {
            res.push_back(tmp);
            return;
        }

        for (int i = 1; i + begin <= s.size(); i++) {
            string substring = s.substr(begin, i);
            if (!substring.empty() && isPalindrome(substring)) {
                tmp.push_back(substring);
                DFS(s, i + begin, tmp);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        if (s.empty()) return res;
        vector<string> tmp;
        DFS(s, 0, tmp);
        return res;
    }
};

int main() {
    Solution solution = Solution();
    string a = "aab";
    vector<int> d = {-1, 4, 2, 1, 9, 10};
    solution.partition(a);
}

