/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
// 深度优先搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)s
class Solution {
public:
    int sum = 0;
    int n;
    unordered_map<int, int> id2index;

    void dfs(vector<Employee *> &employees, int id) {
        Employee *boss = employees[id2index[id]];
        sum += boss->importance;
        for (int i = 0; i < boss->subordinates.size(); i++) {
            int index = boss->subordinates[i];
            dfs(employees, index);
        }
    }

    int getImportance(vector<Employee *> employees, int id) {
        n = employees.size();
        for (int i = 0; i < n; i++) {
            id2index[employees[i]->id] = i;
        }
        dfs(employees, id);
        return sum;
    }
};