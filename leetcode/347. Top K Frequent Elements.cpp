// 使用优先队列
// 时间复杂度：O(nlogk)
// 空间复杂度：O(k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num] ++;
        }
        // pair(频率, 元素)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (pq.size() == k) {
                if (iter->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            } else {
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num] ++;
        }
        // pair(频率, 元素)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (auto &iter : freq) {
            if (pq.size() == k) {
                if (iter.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter.second, iter.first));
                }
            } else {
                pq.push(make_pair(iter.second, iter.first));
            }
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};