// DFS
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
private:
    int res = 1;
    vector<bool> visited;

    void DFS(vector <vector<int>> &rooms, int roomId) {
        if (res == visited.size()) return;
        for (int i = 0; i < rooms[roomId].size(); i++) {
            if (!visited[rooms[roomId][i]]) {
                visited[rooms[roomId][i]] = true;
                res++;
                DFS(rooms, rooms[roomId][i]);
            }
        }
    }

public:
    bool canVisitAllRooms(vector <vector<int>> &rooms) {
        int n = rooms.size();
        visited = vector<bool>(n, false);
        visited[0] = true;
        DFS(rooms, 0);
        return res == visited.size();
    }
};

// BFS
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    bool canVisitAllRooms(vector <vector<int>> &rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        int res = 1;
        queue <vector<int>> q;
        q.push(rooms[0]);
        while (!q.empty()) {
            vector<int> curr_room = q.front();
            q.pop();
            if (res == n) return true;
            for (int i = 0; i < curr_room.size(); i++) {
                if (!visited[curr_room[i]]) {
                    visited[curr_room[i]] = true;
                    res++;
                    q.push(rooms[curr_room[i]]);
                }
            }
        }
        return false;
    }
};