class Solution {
public:
    int findNthDigit(int n) {
        vector<int> record;
        record.push_back(1);
        for (int i = 0; i < 8; i++) {
            int tmp = record[i]+9*((int)pow(10,i))*(i+1);
            record.push_back(tmp);
        }

        int index = -1;
        for (int i = 0; i < record.size(); i++) {
            if (n >= record[i] && n < record[i+1]) {
                index = i + 1;
                break;
            }
        }

        if (index == -1) index = record.size();
        if (index <= 1) return n;

        int remain = n - record[index - 1];
        int ith_num = remain / index;               // 该n位数的第几个数
        int ith_char = remain % index;              // 该数的第几个字符

        int num = (int) pow(10, index-1) + ith_num;
        int res = 0;
        while (index != ith_char) {
            index -- ;
            res = num % 10;
            num /= 10;
        }
        return res;
    }
};