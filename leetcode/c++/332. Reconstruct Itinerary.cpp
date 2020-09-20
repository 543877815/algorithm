// 时间复杂度：O(mlogm)
// 空间复杂度：O(m)
class Solution {
public:
    unordered_map <string, priority_queue<string, vector < string>, std::greater<string>>>
    vec;
    vector <string> stk;

    void DFS(const string &curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            DFS(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector <string> findItinerary(vector <vector<string>> &tickets) {
        for (auto &it: tickets) {
            vec[it[0]].emplace(it[1]);
        }

        DFS("JFK");
        reverse(stk.begin(), stk.end());
        return stk;

    }
};


// DFS
// 时间复杂度：O(mlogm)
// 空间复杂度：O(m)
class Solution {
private:
    int m;
    vector <string> res;
    unordered_map<string, int> ticketsId;
    vector <string> idTickets;
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

    vector <string> findItinerary(vector <vector<string>> &tickets) {
        int n = tickets.size();
        if (n == 0) return res;

        // 去重
        unordered_set <string> ticketsSet;
        for (int i = 0; i < n; i++) {
            ticketsSet.insert(tickets[i][0]);
            ticketsSet.insert(tickets[i][1]);
        }

        // 排序
        for (auto &i : ticketsSet) {
            idTickets.push_back(i);
        }
        ticketsSet.clear();
        sort(tickets.begin(), tickets.end(),
             [](const vector <string> &a, const vector <string> &b) { return a[1] < b[1]; });

        // 编号
        for (int i = 0; i < idTickets.size(); i++) {
            ticketsId[idTickets[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            graph[ticketsId[tickets[i][0]]].push_back(ticketsId[tickets[i][1]]);
            visited[ticketsId[tickets[i][0]]].push_back(false);
        }

        m = n + 1; // 2 * n - (n - 1);
        DFS(ticketsId["JFK"]);

        return res;
    }
};