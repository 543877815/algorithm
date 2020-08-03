// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int upper_bound = target / 2 + 1;
        int lower_bound = 1;
        int left = 1, right = 1, sum = 0;
        vector<vector<int>> res;
        vector<int> list;
        while (left <= right && left <= upper_bound) {
            while(sum<target) {
                sum+=right;
                list.push_back(right);
                right++;
            }
            if (sum == target) res.push_back(list);
            sum-=left;
            list.erase(list.begin(), list.begin()+1);
            left++;
        }
        return res;
    }

};