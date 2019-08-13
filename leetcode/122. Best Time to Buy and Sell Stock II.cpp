int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    if(pricesSize == 0 || pricesSize == 1) return ans;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i-1]) {
            ans += prices[i] - prices[i-1];
        }
    }
    return ans;
}

