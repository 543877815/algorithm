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

    int legal(string &s, int index) {
        int num = (s[index-1] - '0') * 10 + s[index] - '0';
        if (num / 10 >= 3 && num % 10 == 0) return 0;
        else return 1;
    }

    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int m = s.size();

        for (int i = 1; i < m; i++) {
            if (!legal(s, i)) return 0;
        }
        vector<int> dp(m+1, 2);

        dp[0] = 1;
        dp[1] = dp[0] + legal(s, 1);
        // for (int i = begin; i < m; i++) {
        //     dp[i] = dp[i - 1] + + legal(s, i);
        // }
        return dp[m - 1];
    }
};


int main() {
    Solution solution = Solution();
    string a = "226";
    solution.numDecodings(a);
}

//{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

//[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
//[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
