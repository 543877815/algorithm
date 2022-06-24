// ��������+��ϣ��+˫ָ��
// ʱ�临�Ӷȣ�O(sm)
// �ռ临�Ӷȣ�O(ml)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size();
        int l = words[0].size();
        int win_len = m * l;
        vector<int> res;

        for (int i = 0; i < l && i + win_len <= n; i++) {   // ���� s
            unordered_map<string, int> diff;

            for (int j = 0; j < m; j++) {                 // ���촰�ڹ�ϣ��
                diff[s.substr(i + j * l, l)]++;
            }

            for (auto &word: words) {                     // ���� words
                diff[word]--;
                if (diff[word] == 0) {
                    diff.erase(word);
                }
            }

            for (int start = i; start + win_len - 1 < n; start += l) {  // ����һ����֦�����൱��
                if (start != i) {
                    string word = s.substr(start - l, l);
                    diff[word]--;
                    if (diff[word] == 0) diff.erase(word);
                    word = s.substr(start + win_len - l, l);
                    diff[word]++;
                    if (diff[word] == 0) diff.erase(word);
                }
                if (diff.empty()) {
                    res.emplace_back(start);
                }
            }
        }

        return res;

    }
};