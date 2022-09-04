// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    bool checkDistances(string s, vector<int> &distance) {
        int n = s.size();
        int m = distance.size();
        vector<int> last(m, -1);
        for (int i = 0; i < n; i++) {
            char c = s[i] - 'a';
            if (last[c] == -1) {
                last[c] = i;
            } else {
                int cnt = i - 1 - last[c];
                if (distance[c] != cnt) return false;
            }
        }

        return true;
    }
};