// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minOperations(vector <string> &logs) {
        int out = 0;
        int n = logs.size();
        for (int i = 0; i < n; i++) {
            if (logs[i] == "../") {
                if (out > 0) out--;
            } else if (logs[i] == "./");
            else out++;
        }

        return out < 0 ? 0 : out;
    }
};