// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
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
                tmp = (tmp + 1) % m;
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


// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int i = 0;
        while (i < m) {
            int tmp = i;
            int gasRemain = gas[tmp];
            int count = 0;
            while (gasRemain >= cost[tmp] && count != m) {
                gasRemain -= cost[tmp];
                tmp = (tmp + 1) % m;
                gasRemain += gas[tmp];
                count++;
            }
            if (count == m) {
                return tmp;
            } else {
                i += count + 1;
            }
        }
        return -1;
    }
};