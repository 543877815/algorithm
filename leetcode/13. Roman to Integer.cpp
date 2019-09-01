int indexOf(char* str, char ch){
    int index = 0;
    char tmp=str[index];
    while( tmp != '\0'){
        if(tmp == ch){
            return index;
        }
        index++;
        tmp = str[index];
    }
    return -1;
}


int romanToInt(char * s){
    char romanChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int nums[7] = {1, 5, 10, 50, 100, 500, 1000};
    int length = strlen(s);
    int ans = 0;
    for (int i = 0; i < length - 1; i++) {
        if (indexOf(romanChar, s[i]) < indexOf(romanChar, s[i + 1])) {
            ans -= nums[indexOf(romanChar, s[i])];
        } else {
            ans += nums[indexOf(romanChar, s[i])];
        }
    }
    
    ans += nums[indexOf(romanChar, s[length - 1])];
    return ans;
}
