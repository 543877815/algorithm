// 博弈
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool stoneGameIX(vector<int> &stones) {
        int n = stones.size();
        int sum = 0;
        int remain_0 = 0, remain_1 = 0, remain_2 = 0;
        int curr_remain = 0;
        for (int i = 0; i < n; i++) {
            if (stones[i] % 3 == 0) remain_0++;
            else if (stones[i] % 3 == 1) remain_1++;
            else remain_2++;
        }

        if (remain_0 % 2 == 0) return remain_1 >= 1 && remain_2 >= 1;
        return remain_1 - remain_2 > 2 || remain_2 - remain_1 > 2;
    }
};