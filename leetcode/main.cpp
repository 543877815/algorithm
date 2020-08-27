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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int m;
    vector<string> res;
    unordered_map<string, int> ticketsId;
    vector<string> idTickets;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, vector<bool>> visited;

public:
    void DFS(int from) {
        if (res.size() == 0) res.push_back(idTickets[from]);
        for (int to = 0; to < graph[from].size(); to++) {
            if (!visited[from][to]) {
                visited[from][to] = true;
                res.push_back(idTickets[graph[from][to]]);
                DFS(graph[from][to]);
                if (res.size() == m) return;
                res.pop_back();
                visited[from][to] = false;
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        int n = tickets.size();
        if (n == 0) return res;

        // 去重
        unordered_set<string> ticketsSet;
        for (int i = 0; i < n; i++) {
            ticketsSet.insert(tickets[i][0]);
            ticketsSet.insert(tickets[i][1]);
        }

        // 排序
        for (auto &i : ticketsSet) {
            idTickets.push_back(i);
        }
        ticketsSet.clear();
        sort(idTickets.begin(), idTickets.end(), greater<string>());
        sort(tickets.begin(), tickets.end(),
             [](const vector<string> &a, const vector<string> &b) { return a[1] > b[1]; });

        // 编号
        for (int i = 0; i < idTickets.size(); i++) {
            ticketsId[idTickets[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            graph[ticketsId[tickets[i][1]]].push_back(ticketsId[tickets[i][0]]);
            visited[ticketsId[tickets[i][1]]].push_back(false);
        }
        m = n + 1; // 2 * n - (n - 1);

        for (auto &i : graph) {
            if (res.size() != m) {
                res.clear();
                DFS(i.first);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<string>> tickets = {{"JFK", "SFO"},
                                      {"JFK", "ATL"},
                                      {"SFO", "ATL"},
                                      {"ATL", "JFK"},
                                      {"ATL", "SFO"}};
//            {{"MUC", "LHR"},
//                                      {"JFK", "MUC"},
//                                      {"SFO", "SJC"},
//                                      {"LHR", "SFO"}};
    solution.findItinerary(tickets);
}
