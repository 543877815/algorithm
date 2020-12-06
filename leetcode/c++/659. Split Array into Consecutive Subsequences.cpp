// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto &x: nums) {
            countMap[x]++;
        }

        for (auto &x: nums) {
            if (countMap[x] > 0) {
                // 存在以x-1结尾的子序列，则将该元素加入该子序列中
                if (endMap[x - 1] > 0) {
                    countMap[x]--;
                    endMap[x - 1]--;
                    endMap[x]++;
                } else {
                    // 否则，x将作为子序列的第一个数
                    // 为了得到长度至少为3的子序列
                    // x+1和x+2都必须在子序列中
                    if (countMap[x + 1] > 0 && countMap[x + 2] > 0) {
                        countMap[x]--;
                        countMap[x + 1]--;
                        countMap[x + 2]--;
                        endMap[x + 2]++;
                        // 否则，无法得到长度为3的子序列，返回false
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};