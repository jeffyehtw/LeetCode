class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        purchaseAmount += 5;
        purchaseAmount /= 10;
        purchaseAmount *= 10;
        
        return 100 - purchaseAmount;
    }
};
