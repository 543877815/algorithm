// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int max_time = releaseTimes[0];
        char res = keysPressed[0];
        for (int i = 1; i < n; i++) {
            if (max_time <= releaseTimes[i] - releaseTimes[i - 1]) {
                if (max_time == releaseTimes[i] - releaseTimes[i - 1] && res < keysPressed[i]) {
                    res = keysPressed[i];
                } else if (max_time < releaseTimes[i] - releaseTimes[i - 1]) {
                    res = keysPressed[i];
                    max_time = releaseTimes[i] - releaseTimes[i - 1];
                }
            }
        }
        return res;
    }
};