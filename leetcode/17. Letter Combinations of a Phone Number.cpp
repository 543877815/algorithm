
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void getLetterCom(char** res,char* digits,char* tmp,int index, int *size, char map[10][5]){
    int digit = digits[index] - '0';
    if (digits[index] == 0) {
        char* letters = (char*)malloc(sizeof(char)*(index + 1));
        tmp[index] = 0;
        strcpy(letters,tmp);
        res[(*size)++] = letters; 
        return;
    }
    for(int i = 0; map[digit][i]; i++) {
        tmp[index] = map[digit][i];
        getLetterCom(res, digits, tmp, index + 1, size, map);
    }
    return;
}

char ** letterCombinations(char * digits, int*returnSize){
    char map[10][5] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int size = 0;
    
    // compute malloc memory
    int loc = 0;
    int num = 1;
    while(digits[loc]) {
        if (digits[loc] == '0' || digits[loc] == '1') continue;
        else if (digits[loc] == '7' || digits[loc] == '9') num *= 4;
        else num *= 3;
        loc ++;
    }
    char **res = (char **) malloc(sizeof(char*)*num);
    int length = strlen(digits);
    for (int i = 0; i < num; i++) {
        res[i] = (char *)malloc(sizeof(char)*length);
    }

    if(loc == 0) {
        *returnSize = 0;
        return res;
    }
    
    char *tmp = (char *)malloc(sizeof(char) * num);
    getLetterCom(res, digits, tmp, 0, &size, map);
    *returnSize = size;
    return res;
}
