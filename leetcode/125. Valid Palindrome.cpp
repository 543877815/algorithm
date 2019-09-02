

bool isPalindrome(char * s){
    int length = strlen(s);
    if(length == 0) return true;
    int left = 0;
    int right = length - 1;
    int num1, num2;
    while(left < right) {
        // 跳过空格
        while(left < length && 
              (s[left] - ' ' < '0' - ' ' ||
              s[left] - ' ' > '9' - ' ' && s[left] - ' ' < 'A' - ' ' ||
              s[left] - ' ' > 'Z' - ' ' && s[left] - ' ' < 'a' - ' ' ||
              s[left] - ' ' > 'z' - ' ')) left ++;
        while(right > 0 &&
              (s[right] - ' ' < '0' - ' ' ||
              s[right] - ' ' > '9' - ' ' && s[right] - ' ' < 'A' - ' ' ||
              s[right] - ' ' > 'Z' - ' ' && s[right] - ' ' < 'a' - ' ' ||
              s[right] - ' ' > 'z' - ' ')) right --;
        if (left > right) break;
        //取数
        if (s[left] - 'a' >= 0) num1 = (s[left] - ' ') - ('a' - 'A');
        else num1 = (s[left] - ' ');
        
        if (s[right] - 'a' >= 0) num2 = (s[right] - ' ') - ('a' - 'A');
        else num2 = (s[right] - ' ');
        // printf("%c %c %d %d\n", s[left], s[right], num1, num2);
        if (num1 != num2) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

