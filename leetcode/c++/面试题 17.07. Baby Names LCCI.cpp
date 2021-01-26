// 并查集
// 时间复杂度：O(mlogm)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int>fa;
    vector<int>rank;

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n = names.size();
        int m = synonyms.size();
        unordered_map<string, int> record;
        int id = 0;

        // 遍历 names 和 synonyms 根据 name 构造hashmap
        for (int i = 0; i < m; i++) {
            int left_brackets = synonyms[i].find('('), right_brackets = synonyms[i].find(')'), comma = synonyms[i].find(',');
            string left_name = synonyms[i].substr(left_brackets+1, comma-left_brackets-1), right_name = synonyms[i].substr(comma+1, right_brackets-comma-1);
            if (record.count(left_name) == 0) record[left_name] = id++;
            if (record.count(right_name) == 0) record[right_name] = id++;
        }

        for (int i = 0; i < n; i++) {
            int left_brackets = names[i].find('('), right_brackets = names[i].find(')');
            string name = names[i].substr(0, left_brackets);
            if (record.count(name) == 0) record[name] = id++;
        }

        // 初始化并查集
        fa.resize(id);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(id, 1);

        // 初始化并查集
        for (int i = 0; i < m; i++) {
            int left_brackets = synonyms[i].find('('), right_brackets = synonyms[i].find(')'), comma = synonyms[i].find(',');
            string left_name = synonyms[i].substr(left_brackets+1, comma-left_brackets-1), right_name = synonyms[i].substr(comma+1, right_brackets-comma-1);
            merge(record[left_name], record[right_name]); // 字典序靠前的做父节点
        }

        // 合并频率
        unordered_map<int, int> calcFreq;
        unordered_map<int, string> id2Name;
        for (int i = 0; i < n; i++) {
            int left_brackets = names[i].find('('), right_brackets = names[i].find(')');
            string name = names[i].substr(0, left_brackets);
            int number = stoi(names[i].substr(left_brackets+1, right_brackets -left_brackets-1));
            int index = find(record[name]);
            if (calcFreq.count(index) == 0) {
                calcFreq[index] = number;
                id2Name[index] = name;
            } else {
                calcFreq[index] += number;
                if (id2Name[index] > name) id2Name[index] = name;
            }
        }

        vector<string> res;
        for (auto& [key, value] : calcFreq) {
            string tmp = id2Name[key] + "(" + to_string(value) + ")";
            res.push_back(tmp);
        }

        return res;
    }
};