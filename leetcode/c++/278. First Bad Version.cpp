// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        int middle = left + (right - left) / 2;
        while (left < right) {
            if (isBadVersion(middle)){
                if (!isBadVersion(middle-1)) return middle;
                else {
                    right = middle - 1;
                    middle = left + (right - left) / 2;
                }
            } else {
                left = middle + 1;
                middle = left + (right - left) / 2;
            }
        }

        return middle;
    }
};