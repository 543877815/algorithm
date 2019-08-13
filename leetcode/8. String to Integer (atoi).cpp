int myAtoi(char * str){
    int length = strlen(str);
    int numsSize = 0;
    int num = 0;
    int positive = 1;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' && numsSize == 0){
            if (i > 0 && str[i-1] == '0' || flag == 1) return 0;
            continue;
        } else if (str[i] == '-' && numsSize == 0 && flag != 1 ) {
            positive = -positive;
            flag = 1;
            if (i > 0 && str[i-1] == '0') return 0;
        } else if (str[i] == '+' && numsSize == 0 && flag != 1) {
            positive = positive;
            flag = 1;
            if (i > 0 && str[i-1] == '0') return 0;
        } else if (str[i] == '0' && num == 0) {
            continue;
        } else if (str[i] <= '9' && str[i] >= '0') {
            numsSize ++;
            if (numsSize > 10) {
                return positive == 1 ? 2147483647 : -2147483648; 
            } 
            if (numsSize == 10) {
                if (positive == 1) {
                    char check[] = "2147483647";
                    int tmp = num;
                    int j;
                    for (j = 1; j < numsSize; j++) {
                        if (check[j - 1] - '0' < num / (int)pow(10,(numsSize - j - 1)) % 10) {
                            return  2147483647;
                        } else if (check[j - 1] - '0' > num / (int)pow(10,(numsSize - j - 1)) % 10) {
                            break;
                        } 
                    }
                    if (check[numsSize-1] < str[i] && j == numsSize) return 2147483647;
                } else {
                    char check[] = "2147483648";
                    int tmp = num;
                    int j;
                    for (j = 1; j < numsSize; j++) {
                        printf("%d %d\n", check[j - 1] - '0', num / (int)pow(10,(numsSize - j - 1)) % 10);
                        if (check[j - 1] - '0' < num / (int)pow(10,(numsSize - j - 1)) % 10) {
                            return -2147483648;
                        } else if (check[j - 1] - '0' > num / (int)pow(10,(numsSize - j - 1)) % 10) {
                            break;
                        } 
                    }
                    if (check[numsSize-1] <= str[i] && j == numsSize) return -2147483648;
                }
            }
            num = num * 10 + (str[i] - '0');
        } else {
            break;
        } 
    }
    return positive == 1 ? num : -num;
}