// 空间复杂度：O(min(n, k))
// 时间复杂度：O(nlog(min(n, k)))
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for (int i = 0; i < nums.size(); i++) {
            // lower_bound(v-t) <= v+t
            if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() &&
                *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t) return true;
            record.insert(nums[i]);

            if (record.size() == k + 1) record.erase(nums[i-k]);
        }
        return false;
    }
};