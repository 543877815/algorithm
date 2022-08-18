// ��ϣ��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < n; i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||   // �����ִ���
                      freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||  // �������ĳ��ִ������� maxFreq �� maxFreq?1�����������ִ�������ֻ��һ��
                      freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;  // ����һ�����������������ĳ��ִ������� maxFreqmaxFreq�����Ҹ����ĳ��ִ���Ϊ 11
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};