// 遍历
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class MyCalendarTwo {
public:
    vector <pair<int, int>> booked;
    vector <pair<int, int>> overlaps;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        for (auto &[l, r]: overlaps) {
            if (!(l >= end) && !(start >= r)) return false;
        }

        for (auto &[l, r]: booked) {
            if (!(l >= end) && !(start >= r)) {
                overlaps.emplace_back(max(l, start), min(r, end));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};

// 差分法
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    map<int, int> booked;

    bool book(int start, int end) {
        int presum = 0;
        booked[start]++;
        booked[end]--;
        for (auto &[key, value]: booked) {
            presum += value;
            if (presum > 2) {
                booked[start]--;
                booked[end]++;
                return false;
            }
        }

        return true;
    }
};
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// 插旗法
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n)
class MyCalendarTwo {
public:
    map<int, int> recorder;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        recorder[start]++;
        recorder[end]--;
        int curr = 0;
        for (auto &[key, value]: recorder) {
            curr += value;
            if (curr > 2) {
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
// 空间复杂度：O(n)
class MyCalendarTwo {
public:
    vector <pair<int, int>> calendar;
    vector <pair<int, int>> overlaps;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        int n = overlaps.size(), m = calendar.size();
        for (int i = 0; i < n; i++) {
            if (start < overlaps[i].second && end > overlaps[i].first) return false;
        }

        for (int i = 0; i < m; i++) {
            if (start < calendar[i].second && end > calendar[i].first) {
                overlaps.emplace_back(max(start, calendar[i].first), min(end, calendar[i].second));
            }
        }
        calendar.emplace_back(start, end);

        return true;
    }
};




/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */