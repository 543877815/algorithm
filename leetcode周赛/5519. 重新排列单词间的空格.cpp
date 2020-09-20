class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size();
        if (n == 0) return text;
        int space = 0;
        vector<int> space_record;
        int word = 0;
        // 统计空格个数
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') {
                space++;
                space_record.push_back(i);
            }
        }

        if (space == 0) return text;


        // 统计单词个数
        for (int i = 1; i < space_record.size(); i++) {
            if (space_record[i] - space_record[i - 1] != 1) {
                word++;
            }
        }
        if (text.front() != ' ') word++;
        if (text.back() != ' ') word++;

        if (word == 1) {
            string res;
            for (int i = 0; i < text.size(); i++) {
                if (text[i] != ' ') {
                    res += text[i];
                }
            }
            for (int i = 0; i < space; i++) {
                res += ' ';
            }
            return res;
        }


        int dis = space / (word - 1);     // 单词之间的空格数
        int remain = space % (word - 1);  // 放在结尾的空格数

        string res;

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (text[i] != ' ') {
                res.push_back(text[i]);
                if (i < n - 1 && text[i + 1] == ' ') {
                    for (int j = 0; j < dis && space > 0; j++) {
                        res.push_back(' ');
                        space--;
                    }
                }
            }
        }

        for (int j = 0; j < space; j++) {
            res.push_back(' ');
        }

        return res;
    }
};