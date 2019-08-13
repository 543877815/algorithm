int my_pow(int n, int k) {
    int num = 1;
    while(k!=0){
        num *= n;
        k -- ;
    }
    return num;
}

int titleToNumber(char * s){
    // printf("%d", my_pow(2,5));
    int length = strlen(s);
    int num = 0;
    for (int i = 0; i < length; i++) {
        num += (s[i] - 'A' + 1) * my_pow(26, length - 1 - i);
    }
    
    return num;
}

