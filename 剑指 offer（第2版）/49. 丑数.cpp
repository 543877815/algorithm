class Solution {
public:
    int min(int a, int b, int c) {
        if (a <= b && a <= c) return a;
        if (b <= c && b <= a) return b;
        if (c <= a && c <= b) return c;
        return 0;
    }

    int nthUglyNumber(int n) {
        vector<int> record = {0, 1};
        int i2 = 1, i3 = 1, i5 = 1, i = 2;
        int num = 1;
        while(i <= n) {
            int minN = min(record[i2]*2, record[i3]*3, record[i5]*5);
            record.push_back(minN);
            if(minN == record[i2] * 2)i2++;
            if(minN == record[i3] * 3)i3++;
            if(minN == record[i5] * 5)i5++;
            i++;
        }
        return record[n];
    }
};