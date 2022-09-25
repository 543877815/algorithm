// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        /**
            ���Ϊ 6k+1���ܰ�ť 1,3,4 Ӱ�죻
            ���Ϊ 6k+2,6k+6���ܰ�ť 1,2 Ӱ�죻
            ���Ϊ 6k+3,6k+5���ܰ�ť 1,3 Ӱ�죻
            ���Ϊ 6k+4���ܰ�ť 1,2,4 Ӱ�졣
        **/

        for (int i = 0; i < 1 << 4; i++) {   // һ����2^4�����
            vector<int> pressArr(4);
            for (int j = 0; j < 4; j++) {   // �����Ƿ�ѹ
                pressArr[j] = (i >> j) & 1;
            }
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);  // ��ѹ�ܴ���
            if (sum % 2 == presses % 2 && sum <= presses) {
                int status = pressArr[0] ^ pressArr[1] ^ pressArr[3];
                if (n >= 2) {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3) {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4) {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return seen.size();
    }
};

