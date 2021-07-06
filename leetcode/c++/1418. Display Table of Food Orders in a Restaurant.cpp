// 哈希表
// 时间复杂度：O(n+k+m)
// 空间复杂度：O(k+m)
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        int n = orders.size();
        unordered_map<string, int> foodMap;
        unordered_map<string, int> tableMap;
        for (int i = 0; i < n; i++) {
            string customerName = orders[i][0];
            string tableNum = orders[i][1];
            string foodItem = orders[i][2];
            // cout << customerName << " " << tableNum << " " << foodItem << endl;
            tableMap[tableNum] = 0;
            foodMap[foodItem] = 0;
        }
        // 构造食物的映射
        vector<string>  columnHead = {"Table"};
        for (auto & [food, id] : foodMap) {
            columnHead.push_back(food);
        }
        sort(columnHead.begin() + 1, columnHead.end());
        for (int i = 1; i < columnHead.size(); i++) {
            foodMap[columnHead[i]] = i;
        }

        // 构造桌号的映射
        vector<string> rowHead;
        for (auto & [table, id]: tableMap) {
            rowHead.push_back(table);
        }
        sort(rowHead.begin(), rowHead.end(), [&] (string x, string y) {
            int a = atoi(x.c_str());
            int b = atoi(y.c_str());
            return a < b;
        });

        for (int i = 0; i < rowHead.size(); i++) {
            tableMap[rowHead[i]] = i + 1;
        }

        vector<vector<string>> res(rowHead.size() + 1, vector<string>(columnHead.size(), "0"));
        for (int i = 0; i < columnHead.size(); i++) {
            res[0][i] = columnHead[i];
        }

        for (int i = 0; i < rowHead.size(); i++) {
            res[i + 1][0] = rowHead[i];
        }

        for (int i = 0; i < n; i++) {
            string tableNum = orders[i][1];
            string foodItem = orders[i][2];
            int row = tableMap[tableNum], column = foodMap[foodItem];
            int a = atoi(res[row][column].c_str()) + 1;
            res[row][column] = to_string(a);
        }

        return res;

    }
};