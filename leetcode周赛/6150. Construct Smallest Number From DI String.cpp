
// ̰��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int upper = n + 1;  // ������
        string tmp = "";
        for (int i = 1; i <= upper; i++) {
            tmp += to_string(i);
        }
        char last = pattern[0];
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (last != pattern[i]) {
                if (last == 'D') {
                    reverse(tmp.begin() + start, tmp.begin() + i + 1);
                }
                start = i;
                last = pattern[i];
            }
        }
        if (last == 'D') {
            reverse(tmp.begin() + start, tmp.end());
        }
        return tmp;
    }
};