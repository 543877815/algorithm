

char findTheDifference(char * s, char * t){
    int length1 = strlen(s);
    int length2 = strlen(t);
    int sum = 0;
    for (int i = 0; i < length1; i++) {
        sum ^= s[i] - 'a';
    }
    for (int i = 0; i < length2; i++) {
        sum ^= t[i] - 'a';
    }
    return 'a' + sum;
}

