

char * convert(char * s, int numRows){
    int length = strlen(s);
    char ** strings = (char **)malloc(sizeof(char*) * numRows);
    for (int i = 0; i < numRows; i++) {
        strings[i] = (char *)malloc(sizeof(char)*length);
    }
    int loc[numRows];
    for (int i = 0; i < numRows; i++) {
        loc[i] = 0;
    }
    int down = 1;
    int size = 0;
    for (int i = 0; i < length; i++) {
        int index = size % numRows;
        strings[index][loc[index]] = s[i];
        loc[index]++;
        if (down == 1) {
            size ++;
        } else {
            size --;
        }
        if (size == 0 || size == numRows - 1) {
            down = -down;
        }
    }
    size = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < loc[i]; j++) {
            s[size++] = strings[i][j];
        }
    }
    return s;
}

