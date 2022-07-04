// ��ϣ��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    string decodeMessage(string key, string message) {
        int n = key.size();
        unordered_map<char, char> mymap;
        mymap[' '] = ' ';
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (mymap.find(key[i]) == mymap.end()) {
                mymap[key[i]] = 'a' + idx;
                idx++;
            }

        }

        string res;
        int m = message.size();
        for (int i = 0; i < m; i++) {
            res.push_back(mymap[message[i]]);
        }

        return res;
    }
};