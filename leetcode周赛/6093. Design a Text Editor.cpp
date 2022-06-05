
class TextEditor {
public:
    int curr = 0;
    string str;

    TextEditor() {

    }

    void addText(string text) {
        str.replace(str.begin()+curr, str.begin()+curr, text);
        curr = curr + text.size();
    }

    int deleteText(int k) {
        if (k > curr) {
            str = str.substr(curr);
            int res = min(curr, k);
            curr = 0;
            return res;
        } else {
            str.replace(str.begin() + curr - k, str.begin() + curr, "");
            curr -= k;
            return k;
        }
    }

    string cursorLeft(int k) {
        curr = max(curr - k, 0);
        if (curr > 10) {
            return str.substr(curr - 10, 10);
        } else {
            return str.substr(0, curr);
        }
    }

    string cursorRight(int k) {
        int n = str.size();
        curr = min(curr + k, n);
        if (curr > 10) {
            return str.substr(curr - 10, 10);
        } else {
            return str.substr(0, curr);
        }
    }
};
