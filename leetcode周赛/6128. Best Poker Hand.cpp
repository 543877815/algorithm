class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> suits_count;
        int n = ranks.size();
        for (int i = 0; i < n; i++) {
            suits_count[suits[i]]++;
            if (suits_count[suits[i]] == 5) {
                return "Flush";
            }
        }

        unordered_map<int, int> ranks_count;
        for (int i = 0; i < n; i++) {
            ranks_count[ranks[i]]++;
        }

        bool hasPair = false;
        for (int i = 0; i < n; i++) {
            if (ranks_count[ranks[i]] >= 3) {
                return "Three of a Kind";
            } else if (ranks_count[ranks[i]] == 2){
                hasPair = true;
            }
        }

        return hasPair ? "Pair" : "High Card";
    }
};