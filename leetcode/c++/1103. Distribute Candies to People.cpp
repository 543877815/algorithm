// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int curr = 0;
        int num = 1;
        while (candies > 0) {
            res[curr] += min(num, candies);
            candies -= num;
            num++;
            curr = (curr + 1) % num_people;
        }

        return res;
    }
};