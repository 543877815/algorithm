


bool validPalindrome(char * s){
    int length = strlen(s);
    int left = 0;
    int right = length - 1;
    int flag = -1;
    int count = 1;
    while(left < right) {
        if (s[left] != s[right]) {
            // 尝试删除左字符
            if (flag == -1){
                flag = left;
                left ++;
                continue;
            }
            // 若删除左字符无效，则回退
            if (flag == left - count && flag != -3) {
                left -= count;
                right += count - 1;
                flag = -2;
                count = 0;
                continue;
            }
            // 尝试删除右字符
            if (flag == -2){
                right--;
                flag = -3;
                continue;
            }
            // 不是回文
            return false;
        }
        left ++;
        right --;
        if (flag > 0) {
            count ++;
        }
    }
    return true;
}
