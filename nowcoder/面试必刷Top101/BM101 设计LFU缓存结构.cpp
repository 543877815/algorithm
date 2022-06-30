// 时间复杂度：O(logn)
// 空间复杂度：O(capacity)
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator<(const Node &rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};


class Solution {
private:
    int time;
    int capacity;
    set <Node> S;
    unordered_map<int, Node> cache;

public:
    /**
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LFU(vector <vector<int>> &operators, int k) {
        // write code here
        int n = operators.size();
        capacity = k;
        time = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int type = operators[i][0];
            if (type == 1) {
                int key = operators[i][1];
                int value = operators[i][2];
                put(key, value);
            } else if (type == 2) {
                int key = operators[i][1];
                res.push_back(get(key));
            }
        }
        return res;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = cache.find(key);
        if (it == cache.end()) {
            if (cache.size() == capacity) {
                cache.erase(S.begin()->key);
                S.erase(S.begin());
            }
            Node node = Node(1, ++time, key, value);
            cache.insert(make_pair(key, node));
            S.insert(node);
        } else {
            Node node = it->second;
            S.erase(node);
            node.cnt += 1;
            node.time = ++time;
            node.value = value;
            S.insert(node);
            it->second = node;
        }
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        Node node = it->second;
        S.erase(node);
        node.cnt += 1;
        node.time = ++time;
        S.insert(node);
        it->second = node;
        return node.value;
    }
};