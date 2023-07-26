/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //must buy before you sell
        //brute force would be TC O(n^2), SC O(1)
        //the cost could be 0
        //edge case: prices.size()==1
        if(prices.size()==1)return 0;
        /*
        int max = 0;
        for(int j = prices.size()-1; j >= 0; j--){
            for(int i = j-1; i >= 0; i--){
                if((nums[j] - nums[i]) > max){
                    max = nums[j] - nums[i];
                }
            }
        }
        return max;
        */
        //credit to hi-malik
        //TC O(n), SC O(1)
        int cur_min = INT_MAX;
        int max = 0;
        int temp = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < cur_min){
                cur_min = prices[i];
            }
            temp = prices[i] - cur_min;
            if(temp > max){
                max = temp;
            }
        }
        return max;
    }
};