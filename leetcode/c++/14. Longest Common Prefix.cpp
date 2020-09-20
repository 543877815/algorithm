char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    static char ans[1000];
    int index = 0;
    while(true) {
        for (int i = 0; i < strsSize; i++) {
            if(strs[i][index] == '\0') {
                ans[index] = 0;
                return ans;
            }
        }
        for (int i = 0; i < strsSize - 1; i++) {
            if (strs[i][index] != strs[i+1][index]) {
                ans[index] = 0;
                return ans;
            }
            if (i == strsSize - 2) {
                ans[index] = strs[i][index];
                index ++;
            }
        }
    }
}