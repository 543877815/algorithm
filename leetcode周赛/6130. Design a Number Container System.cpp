// ��ϣ��������
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class NumberContainers {
public:
    unordered_map<int, int> hashmap;
    unordered_map<int, set<int>> mapping;

    NumberContainers() {

    }

    void change(int index, int number) {
        if (hashmap.count(index)) {
            int old = hashmap[index];
            mapping[old].erase(index);
            if (mapping[old].size() == 0) mapping.erase(old);
        }
        hashmap[index] = number;
        mapping[number].insert(index);
    }

    int find(int number) {
        if (mapping.find(number) != mapping.end()) {
            return *mapping[number].begin();
        } else {
            return -1;
        }
    }
};
