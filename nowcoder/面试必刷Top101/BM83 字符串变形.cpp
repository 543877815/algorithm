class Solution {
public:
    string trans(string s, int n) {
        stack<string> sk;
        string str;
        s.push_back(' ');//避免特判
        for(int i = 0; i <= n; ++i) {//注意此时单词长度为n+1
            if(s[i] == ' ') {
                sk.push(str);//以空格为界进行压栈
                str = "";
            } else {
                str += s[i] ^ 32;
            }
        }
        string ans;
        while(!sk.empty()) {
            //从栈中逐个弹出单词
            ans += sk.top(); sk.pop();
            ans.push_back(' ');
        }
        ans.pop_back();//去除最后一个单词后的空格
        return ans;
    }
};
