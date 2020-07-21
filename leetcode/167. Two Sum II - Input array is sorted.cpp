// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = {0,0};
        int first = 0;
        int last = numbers.size() - 1;
        while(first < last && first < numbers.size() && last >= 0) {
            if (numbers[first] + numbers[last] == target) {
                ans[0] = first+1;
                ans[1] = last+1;
                break;
            }
            if (abs(numbers[first+1] + numbers[last] - target) < abs(numbers[first] + numbers[last-1] - target)) {
                first++;
            } else {
                last--;
            }
        }
        return ans;
    }
};