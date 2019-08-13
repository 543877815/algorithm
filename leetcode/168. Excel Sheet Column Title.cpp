char * convertToTitle(int n){
    char *str = (char *)malloc(sizeof(char) * 100);
    int size = 0;
    while(n!=0){
        int carry = (n - 1)% 26 + 1;
        printf("%d %c\n", carry, 'A' - 1 + carry);
        str[size++] = 'A' - 1 + carry;
        n = (n-1) / 26;
    };
    
    for (int i = 0; i < size / 2; i++) {
        char tmp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = tmp;
    }
    str[size] = 0;
    return str;
}
