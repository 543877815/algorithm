// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class StockPrice {
public:
    unordered_map<int, int> record;
    map<int, int> mymap;
    int latest_time = 1;

    StockPrice() {

    }

    void update(int timestamp, int price) {
        if (record.count(timestamp)) {
            mymap[record[timestamp]]--;
            if (mymap[record[timestamp]] == 0) mymap.erase(record[timestamp]);
        }
        mymap[price]++;
        record[timestamp] = price;
        latest_time = max(latest_time, timestamp);
    }

    int current() {
        return record[latest_time];
    }

    int maximum() {
        return mymap.rbegin()->first;
    }

    int minimum() {
        return mymap.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */