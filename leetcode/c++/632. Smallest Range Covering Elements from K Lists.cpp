// 合并k个排序数组，n是平均长度
// 空间复杂度：O(nk)
// 时间复杂度：O(nk^2)

// 哈希表+滑动窗口，V是列表元素的值域
// 时间复杂度：O(nk+|V|)
// 空间复杂度：O(nk)
class Solution {
public:
    vector<int> smallestRange(vector <vector<int>> &nums) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> record;
        int min_num = INT_MAX, max_num = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                record[nums[i][j]].insert(i);
                min_num = min(min_num, nums[i][j]);
                max_num = max(max_num, nums[i][j]);
            }
        }
        vector<int> freq(n);
        int left = min_num, right = min_num;
        int res_left = min_num, res_right = max_num;
        int count = 0;
        while (right <= max_num) {
            if (record.count(right)) {
                for (auto i : record[right]) {
                    freq[i]++;
                    if (freq[i] == 1) count++;
                }
            }
            while (count == n) {
                if (right - left < res_right - res_left) {
                    res_right = right;
                    res_left = left;
                }
                if (record.count(left)) {
                    for (auto i: record[left]) {
                        freq[i]--;
                        if (freq[i] == 0) count--;
                    }
                }
                left++;
            }
            right++;
        }
        return {res_left, res_right};
    }
};

// 堆
// 时间复杂度：O(nklogk)
// 空间复杂度：O(k)
class Solution {
public:
    vector<int> smallestRange(vector <vector<int>> &nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        vector<int> next(size);

        auto cmp = [&](const int &u, const int &v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }

        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};
