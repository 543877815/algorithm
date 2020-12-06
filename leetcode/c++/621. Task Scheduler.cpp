// 时间复杂度：O(|task|+26|
// 空间复杂度：O(26)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        if (m == 0) return 0;
        vector<int> vec(26,0);
        for (auto& x: tasks) vec[x-'A']++;
        sort(vec.begin(), vec.end(), greater<int>());
        int i;
        for (i = 1; i < 26; i++) {
            if (vec[i] != vec[0]) break;
        }
        // for (auto& x: vec) cout << x << ",";
        return max(m, (vec[0]-1)*(n+1)+i);
    }
};

// 模拟过程
// 时间复杂度：O(|tasks|*|26|)
// 空间复杂度：O(|26|)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto& x: tasks) freq[x]++;

        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto [k, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); i++) {
            time++;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (rest[j]) {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; j++) {
                if (rest[j] && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }

            nextValid[best] = time + n + 1;
            rest[best] --;
        }
        return time;
    }
};