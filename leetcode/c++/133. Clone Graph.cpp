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

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// BFS, n表示节点个数
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        unordered_map<Node *, Node *> visited;
        queue<Node *> q;
        visited[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            for (int i = 0; i < curr->neighbors.size(); i++) {
                if (!visited.count(curr->neighbors[i])) {

                    // 创建新的节点
                    Node *new_node = new Node(curr->neighbors[i]->val);

                    // 建立映射
                    visited[curr->neighbors[i]] = new_node;

                    // 放入队列
                    q.push(curr->neighbors[i]);
                }

                // 建立邻接关系
                visited[curr]->neighbors.push_back(visited[curr->neighbors[i]]);
            }
        }

        return visited[node];
    }
};

// DFS, n表示节点个数
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    unordered_map<Node *, Node *> visited;

    void DFS(Node *node) {
        if (!node) return;
        // 创建新节点
        Node *new_node = new Node(node->val);
        // 建立映射
        visited[node] = new_node;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (!visited[node->neighbors[i]]) {
                DFS(node->neighbors[i]);
            }
            // 建立连接
            visited[node]->neighbors.push_back(visited[node->neighbors[i]]);
        }
    }

public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        DFS(node);
        return visited[node];
    }
};


int main() {
    Solution solution = Solution();
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    a->neighbors.push_back(b);
    a->neighbors.push_back(d);
    b->neighbors.push_back(a);
    b->neighbors.push_back(c);
    c->neighbors.push_back(b);
    c->neighbors.push_back(d);
    d->neighbors.push_back(c);
    d->neighbors.push_back(a);
    solution.cloneGraph(a);
}
