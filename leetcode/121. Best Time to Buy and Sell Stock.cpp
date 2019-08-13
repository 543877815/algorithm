#define INF 0x7fffffff

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0 || pricesSize == 1) return 0;
    int ans = prices[1] - prices[0];
    int minPrice = INF; 
    for (int i = 0 ; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        ans = max(ans, prices[i] - minPrice);
    }
    return ans > 0 ? ans : 0;
}
