// ��ϣ��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        unordered_map<char, int> mymap;
        for (int i = 0; i < n; i++) {
            mymap[s[i]]++;
            if (mymap[s[i]] == 2) return s[i];
        }
        return -1;
    }
};