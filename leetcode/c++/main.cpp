
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
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int m = people.size();
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(2));
        sort(people.begin(), people.end(), [&](vector<int> &x, vector<int> &y) {
            if (x[0] != y[0]) return x[0] < y[0];
            else return x[1] > y[1];
        });

        /*for (int i = 0; i < m; i++) {
            cout << people[i][0] << " " << people[i][1] << endl;
        }*/

        vector<bool> used = vector<bool>(m, false);

        for (int i = 0; i < m; i++) {
            int idx = people[i][1];
            int j = 0;

            while ((idx > 0 && j < m) || used[j]) {
                if (!used[j]) {
                    idx--;
                }
                j++;
            }

            if (j < m) {
                used[j] = true;
                res[j] = people[i];
            }
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();
    vector<vector<int>> array = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    solution->reconstructQueue(array);
}

