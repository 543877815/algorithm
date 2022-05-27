class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if (n == 1) return rotateArray[0];
        if (n == 2) return min(rotateArray[0], rotateArray[1]);
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (rotateArray[right] > rotateArray[mid]) {
                right = mid;
            } else if (rotateArray[right] < rotateArray[mid]) {
                left = mid + 1;
            } else {
                right -= 1;
            }
        }
        return rotateArray[left];
    }
};
