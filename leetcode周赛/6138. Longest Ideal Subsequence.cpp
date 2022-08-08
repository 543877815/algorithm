// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> hashmap; // ����ĸ i ��β�������������
        int res = 1;
        for (int i = 0; i < n; i++) {
            int max_num = 1;
            for (int j = 0; j < 26; j++) {
                char c = j + 'a';
                if (hashmap.count(c) && abs(s[i] - c) <= k) {
                    max_num = max(max_num, hashmap[c] + 1);
                }
            }

            hashmap[s[i]] = max_num;
            res = max(res, max_num);
        }

        return res;
    }
};