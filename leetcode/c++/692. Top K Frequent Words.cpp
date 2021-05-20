// 哈希表 + 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> topKFrequent(vector <string> &words, int k) {
        vector <string> res;
        int n = words.size();
        if (n == 0) return res;
        unordered_map<string, int> count;
        for (auto word: words) {
            count[word]++;
        }
        vector <pair<string, int>> arr;
        for (auto[key, value]: count) {
            arr.push_back(make_pair(key, value));
        }

        sort(arr.begin(), arr.end(), [&](pair<string, int> &a, pair<string, int> &b) {
            if (a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        });

        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].first);
        }

        return res;
    }
};

// 哈希表 + 排序 + 空间优化
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> topKFrequent(vector <string> &words, int k) {
        vector <string> res;
        int n = words.size();
        if (n == 0) return res;
        unordered_map<string, int> count;
        for (auto word: words) {
            count[word]++;
        }
        vector <string> arr;
        for (auto[key, value]: count) {
            arr.push_back(key);
        }

        sort(arr.begin(), arr.end(), [&](string &a, string &b) {
            if (count[a] != count[b]) return count[a] > count[b];
            else return a < b;
        });

        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
};

// 优先队列
// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> topKFrequent(vector <string> &words, int k) {
        vector <string> res;
        int n = words.size();
        if (n == 0) return res;
        unordered_map<string, int> count;
        for (auto word: words) {
            count[word]++;
        }

        auto cmp = [&](pair<string, int> &a, pair<string, int> &b) {
            if (a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        };

        priority_queue < pair < string, int >, vector < pair < string, int >>, decltype(cmp) > pq(cmp);

        for (auto &elem : count) {
            pq.push(elem);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        res.resize(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }

        return res;
    }
};