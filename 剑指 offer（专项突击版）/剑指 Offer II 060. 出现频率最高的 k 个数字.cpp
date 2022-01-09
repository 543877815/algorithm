// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elem2freq;
        int n = nums.size();
        int id = 0;
        // O(n)
        for (int i = 0; i < n; i++) {
            elem2freq[nums[i]] ++;
        }

        // O(n)
        priority_queue<pair<int, int>> pq;
        for (auto &[key, value]: elem2freq) {
            pq.push(make_pair(value, key));
        }

        vector<int> res;
        while(k > 0) {
            auto freq2elem = pq.top();
            pq.pop();
            res.push_back(freq2elem.second);
            k--;
        }

        return res;
    }
};
