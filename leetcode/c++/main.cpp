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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int gasRemain = 0;
        for (int i = 0; i < m; i++) {
            int tmp = i;
            bool init = true;
            gasRemain = gas[tmp];
            int count = 0;
            while (gasRemain >= cost[tmp] && count != m) {
                init = false;
                gasRemain -= cost[tmp];
                if (tmp + 1 == m) tmp = 0;
                else tmp++;
                gasRemain += gas[tmp];
                count++;
            }
            if (!init && tmp == i) {
                return tmp;
            }
        }
        return -1;
    }
};

int main() {
    auto *solution = new Solution();
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    solution->canCompleteCircuit(gas, cost);

}

