int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    int maxLength = 0;
    if(length == 0)return maxLength;
    int CurrentLength = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < length; i++) {
        printf("%c %d %d %d\n", s[i], start, end, maxLength);
        int flag = 0;
        for (int j = start; j < end; j++) {
            if (s[i] == s[j] && start != end){
                start = j + 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            CurrentLength ++;
        }  else { 
            CurrentLength = end - start + 1;
        }
        
        end++;
        
        if (CurrentLength > maxLength){
            maxLength = CurrentLength;
        }
        
    }
    return maxLength;
}

