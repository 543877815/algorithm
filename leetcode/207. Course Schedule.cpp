// 使用邻接矩阵，进行广度优先搜索
// 空间复杂度：O(n^2)
// 时间复杂度：O(n^2)
class Solution {
public:
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites) {
        if (prerequisites.size() == 0) return true;
        vector<int> in_degrees(numCourses, 0);
        // 构建邻接矩阵并且记录入度
        int index = 0;  // 记录图中线的数量
        vector <vector<int>> arr(numCourses, vector<int>(numCourses, 0));
        for (int i = 0; i < prerequisites.size(); i++) {
            arr[prerequisites[i][1]][prerequisites[i][0]] = 1;
            in_degrees[prerequisites[i][0]]++;
            index++;
        }

        // 检查回环
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                if (i != j && arr[i][j] == arr[j][i] && arr[i][j] != 0) return false;
            }
        }

        stack<int> s;
        for (int i = 0; i < in_degrees.size(); i++) {
            if (in_degrees[i] == 0) s.push(i);
        }

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            for (int i = 0; i < numCourses; i++) {
                // 两点存在连线
                if (arr[curr][i] != 0) {
                    in_degrees[i]--;
                    index--;
                    arr[curr][i] = 0;
                    if (in_degrees[i] == 0) s.push(i);
                }
            }
        }
        return index == 0;
    }
};


// 使用邻接表，进行广度优先搜索，n是课程数，m是先修课程的要求数
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites) {
        if (prerequisites.size() == 0) return true;
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
            s.pop();
            for (auto iter : pre2course[curr]) {
                in_degrees[iter]--;
                if (in_degrees[iter] == 0) s.push(iter);
                index--;
            }
        }
        return index == 0;
    }
};