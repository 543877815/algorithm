

bool isValid(char * s){
    int length = strlen(s);
    if (length == 1) return false;
    if (length == 0) return true;
    char stack[length];
    int size = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == '('){
            stack[size++] = s[i];
        } else if (s[i] == '[') {
            stack[size++] = s[i];
        } else if (s[i] == '{') {
            stack[size++] = s[i];
        } else if (s[i] == ']') {
            if (size == 0) return false;
            if (stack[size-1] == '['){
                size--;
            } else return false;
        } else if (s[i] == '}') {
            if (size == 0) return false;
            if (stack[size-1] == '{') {
                size--;
            } else return false;
        } else if (s[i] == ')') {
            if (size == 0) return false;
            if (stack[size-1] == '(') {
                size--;
            } else return false;
        } 
    }
    if (size != 0) return false;
    return true;
}

