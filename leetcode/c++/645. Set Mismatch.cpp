// 使用Hashmap
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map <int, int> record;
        int repeat = 0, loss = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (!record[nums[i]]) {
                record[nums[i]]++;
            } else {
                repeat = nums[i];
            }
        }
        for (map<int, int>::iterator i = record.begin(); i != record.end(); i++) {
            if (i->first != loss) {
                break;
            }
            loss++;
        }
        vector<int> res = {repeat, loss};
        return res;
    }
};

// 使用排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int repeat = 0, loss = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if ( nums[i] == nums[i+1]) {
                repeat = nums[i];
            } else if (nums[i + 1] > nums[i] + 1) {
                loss = nums[i] + 1;
            }
        }

        loss = nums.back() != nums.size() ? nums.size() : loss;
        vector<int> res = {repeat, loss};
        return res;
    }
};