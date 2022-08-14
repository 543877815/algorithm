class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> counter(n, 0);
        for (int i = 0; i < n; i++) {
            counter[edges[i]] += (long)i;
        }
        int idx = -1;
        long max_num = 0;
        for (int i = 0; i < n; i++) {
            if (max_num < counter[i]){
                max_num = counter[i];
                idx = i;
            }
        }

        return idx;
    }
};