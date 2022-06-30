// ʱ�临�Ӷȣ�O(logn)
// �ռ临�Ӷȣ�O(capacity)
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator<(const Node &rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
private:
    // ����������ʱ���
    int capacity, time;
    unordered_map<int, Node> key_table;  // <key, Node>
    set <Node> S;  // ����Ƶ�ʺ�ʱ��
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        // �ӹ�ϣ���еõ��ɵĻ���
        Node cache = it->second;
        // ɾ���ɵĻ���
        S.erase(cache);
        // ���¾ɵĻ���
        cache.cnt += 1;
        cache.time = ++time;
        // ���»������·������ϣ���ƽ���������
        S.insert(cache);
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // ������ﻺ������
            if (key_table.size() == capacity) {
                // �ӹ�ϣ���ƽ���������ɾ���������ʹ�õĻ���
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // �����µĻ��沢�����ϣ���ƽ���������
            Node cache = Node(1, ++time, key, value);
            // key_table[key] = cache;
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        } else {
            // ����� get() ��������
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */