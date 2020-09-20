int min(int a, int b) {
    return a > b ? b : a;
}

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    while(left != right) {
        if (min(height[left], height[right]) * (right - left) > max) {
            max = min(height[left], height[right]) * (right - left);
        }
        if (height[left] > height[right]) {
            right --;
        } else {
            left ++;
        }
    }
    return max;
}