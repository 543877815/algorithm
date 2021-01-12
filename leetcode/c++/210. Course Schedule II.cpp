// 使用邻接表，进行广度优先搜索，n是课程数，m是先修课程的要求数
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>> &prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);

        unordered_map<int, vector<int>> pre2course;
        for (int i = 0; i < prerequisites.size(); i++) {
            pre2course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        stack<int> s;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) s.push(i);
        }

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            res.push_back(curr);
            for (auto a: pre2course[curr]) {
                if (--inDegree[a] == 0) s.push(a);
            }
        }

        return res.size() == numCourses ? res : vector < int > {};
    }
};

// queue
class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>> &prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);

        unordered_map<int, vector<int>> pre2course;
        for (int i = 0; i < prerequisites.size(); i++) {
            pre2course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> Q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) Q.push(i);
        }

        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            res.push_back(curr);
            for (auto a: pre2course[curr]) {
                if (--inDegree[a] == 0) Q.push(a);
            }
        }

        return res.size() == numCourses ? res : vector < int > {};
    }
};