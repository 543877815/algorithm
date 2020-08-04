// 使用邻接表，进行广度优先搜索，n是课程数，m是先修课程的要求数
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>> &prerequisites) {
        vector<int> res;
        vector<int> in_degrees(numCourses, 0);

        // 构建邻接表并且记录入度
        int index = 0;  // 记录图中线的数量
        unordered_map<int, vector<int>> pre2course;
        for (int i = 0; i < prerequisites.size(); i++) {
            pre2course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degrees[prerequisites[i][0]]++;
            index++;
        }

        stack<int> s;
        for (int i = 0; i < in_degrees.size(); i++) {
            if (in_degrees[i] == 0) s.push(i);
        }

        while (!s.empty()) {
            int curr = s.top();
            res.push_back(curr);
            s.pop();
            for (auto iter : pre2course[curr]) {
                in_degrees[iter]--;
                if (in_degrees[iter] == 0) s.push(iter);
                index--;
            }
        }
        return index == 0 ? res : vector<int>(0);
    }
};