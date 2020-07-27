

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


// c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                record.push(s[i]);
            } else {
                if (record.size() == 0) {
                    return false;
                } else {
                    char c = record.top();
                    record.pop();

                    char match;
                    if (s[i] == ')') {
                        match = '(';
                    } else if (s[i] == ']') {
                        match = '[';
                    } else {
                        assert(s[i] == '}');
                        match = '{';
                    }

                    if (c != match) return false;
                }
            }
        }
        if (record.size() != 0) return false;
        return true;
    }
};