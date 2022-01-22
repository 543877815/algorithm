// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    unordered_map<int, vector<int>> recorder;

    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            recorder[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int res;
        for (int i = 1; i <= recorder[target].size(); i++) {
            int random = rand() % i;
            if (random < 1) res = recorder[target][i - 1];
        }
        return res;
    }
};

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
private:
    vector<int>::iterator begin;
    vector<int>::iterator end;

public:
    Solution(vector<int>& nums) {
        begin = nums.begin();
        end = nums.end();
    }

    int pick(int target) {
        int res = -1;
        int cnt = 0;
        int i = 0;
        for (auto iter = begin; iter != end; iter++) {
            if (*iter == target) {
                cnt++;
                if (rand() % cnt == 0) res = i;
            }
            i++;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */