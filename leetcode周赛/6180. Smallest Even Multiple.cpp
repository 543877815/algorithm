class Solution {
public:
    int gcb(int a, int b)
    {
        int c = 0;
        while(c = a % b)
        {
            a = b;
            b = c;
        }
        return b;
    }

    int smallestEvenMultiple(int n) {
        return n * 2 / gcb(n, 2);
    }
};