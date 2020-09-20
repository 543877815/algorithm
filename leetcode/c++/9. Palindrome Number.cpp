class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int array[20];
        int length  = 0; 
        do {
            array[length] = x % 10;
            x /= 10;
            length ++ ;
        } while(x != 0);
        for (int i = 0; i < length / 2; i++) {
                if (array[i] != array[length - i - 1]) return false;
        }
        return true;
    }
};