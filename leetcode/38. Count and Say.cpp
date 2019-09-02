

char * countAndSay(int n){
    char **ans = (char **)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = (char *)malloc(sizeof(char) *4500);
    }
    ans[0][0] = '1';
    ans[0][1] = 0;
    int size = 0;
    for (int i = 1; i < n; i++) {
        int j = 0;
        int num=0;
        int pos=0;
        char character = '0';
        while(ans[size][j]) {
            character = ans[size][j];
            int tmp = j;
            while(ans[size][j] == ans[size][tmp]) {
                num++;
                tmp++;
            }
            ans[size+1][pos]=num + '0'; pos++;
            ans[size+1][pos]=character; pos++;
            j+=num;
            num=0;
        }
        ans[size+1][pos] = 0;
        size++;
    }
    return ans[size];
}

