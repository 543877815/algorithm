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
    vector<string> reverseWord;
    unordered_map<string, int> wordId;

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> res;
        if (words.size() <= 1) return res;
        for (string word: words) {
            reverseWord.push_back(word);
            reverse(reverseWord.back().begin(), reverseWord.back().end());
        }

        int id = 0;
        for (string word: reverseWord) {
            wordId[word] = id++;
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int long_index = words[i].size() >= words[j].size() ? i : j;
                int short_index = words[i].size() < words[j].size() ? i : j;
                string long_words = words[long_index];
                string short_words = words[short_index];

                // 截取前缀
                int dis = long_words.size() - short_words.size();
                string left = long_words.substr(0, dis);
                string right = long_words.substr(dis);
                if (isPalindrome(left)) {
                    auto iter = wordId.find(right);
                    if (iter != wordId.end()) {
                        res.push_back({short_index, long_index});
                    }
                }

                // 截取后缀
                left = long_words.substr(0, short_words.size());
                right = long_words.substr(short_words.size());
                if (isPalindrome(right)) {
                    auto iter = wordId.find(left);
                    if (iter != wordId.end()) {
                        res.push_back({long_index, short_index});
                    }
                }


            }
        }

        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<string> a = {"bat", "tab", "cat"};
//    vector<string> a = {"abcd","dcba","lls","s","sssll"};
    solution.palindromePairs(a);
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
