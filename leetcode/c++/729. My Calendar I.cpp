// 插旗法
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n)
class MyCalendar {
public:
    map<int, int> recorder;

    MyCalendar() {

    }

    bool book(int start, int end) {
        recorder[start]++;
        recorder[end]--;

        int curr = 0;
        for (auto &[key, val]: recorder) {
            curr += val;
            if (curr > 1) {  // reset
                recorder[start]--;
                recorder[end]++;
                return false;
            }
        }

        return true;
    }
};

// 暴力法
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class MyCalendar {
public:
    vector <pair<int, int>> recorder;

    MyCalendar() {

    }

    bool book(int start, int end) {
        for (int i = 0; i < recorder.size(); i++) {
            if (recorder[i].second > start && recorder[i].first < end) return false;
        }

        recorder.push_back({start, end});
        return true;
    }
};

// 线段树
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Node {
public:
    int start;
    int end;
    Node *left;
    Node *right;

    Node(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
    }

    bool insert(Node *node) {
        if (node->start >= end) {
            if (!right) {
                right = node;
                return true;
            }
            return right->insert(node);
        } else if (node->end <= start) {
            if (!left) {
                left = node;
                return true;
            }
            return left->insert(node);
        } else {
            return false;
        }
    }
};

class MyCalendar {
public:
    Node *root = nullptr;

    MyCalendar() {

    }

    bool book(int start, int end) {
        if (!root) {
            root = new Node(start, end);
            return true;
        }
        return root->insert(new Node(start, end));
    }
};


// 线段树
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class MyCalendar {
public:
    set<pair<int, int>> v;
    MyCalendar() { }

    bool book(int _start, int _end) {
        auto p = v.lower_bound({_end, INT_MIN}); // 结束时间大于登入输入的最小时间
        if(!((p == end(v) || p->second >= _end) && (p == begin(v) || prev(p)->first <= _start))) return false;
        v.emplace(_end, _start);
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

