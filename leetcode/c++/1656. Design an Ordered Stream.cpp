// 时间复杂度：O(n)
// 空间复杂度：O(n)
class OrderedStream {
public:
    int n;
    vector <string> arr;

    OrderedStream(int n) {
        this->n = n;
        arr = vector<string>(n, "");
    }

    int idx = 0;

    vector <string> insert(int idKey, string value) {
        arr[idKey - 1] = value;
        vector <string> res;
        while (idx < n && arr[idx] != "") {
            res.push_back(arr[idx]);
            idx++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */