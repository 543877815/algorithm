// �����
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class FoodRatings {
    typedef pair<int, string> pis;
    map<string, pis> mp1;
    map<string, set<pis>> mp2;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mp1[foods[i]] = pis(ratings[i], cuisines[i]);
            // ÿ��һ��͵��С����
            // ������롰�������֡����ַ������������������֡�С�ģ�Ҳ�������ִ��ʳ�������ǰ��
            mp2[cuisines[i]].insert(pis(-ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        pis &p = mp1[food];
        mp2[p.second].erase(pis(-p.first, food));
        p.first = newRating;
        mp2[p.second].insert(pis(-p.first, food));
    }

    string highestRated(string cuisine) {
        return mp2[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

