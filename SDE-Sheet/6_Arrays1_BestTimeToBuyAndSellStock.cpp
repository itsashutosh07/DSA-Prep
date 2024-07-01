
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 01:00:48

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #121. Best Time to Buy and Sell Stock

/*
DESCRIPTION :

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
    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^4

*/ 


class Solution {
    public:
    int maxProfit1(vector<int>& prices) {
        // TC: O(n^2) SC: O(1)
        int maxP = 0, currP = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                currP = prices[j] - prices[i];
                if (currP > maxP) maxP = currP;
            }
        }
        return maxP;

    }

    int maxProfit2(vector<int>& prices) {
        // TC: O(N) & SC: O(1)
        int maxP = 0, minPrice = 1e9, currP = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            currP = prices[i] - minPrice;
            if (currP > maxP) maxP = currP;
        }
        return maxP;
    }
    /*
        - If the interviewer twists the question slightly by giving the difference array of prices, 
            - Ex: for {1, 7, 4, 11}, if he gives {0, 6, -3, 7}.
        - The logic to solve this problem would be same as "max subarray problem" using KADANE's ALGORITHM.
        - Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.


        int maxProfit(vector<int>& prices) {
            int maxCur = 0, maxSoFar = 0;
            for(int i = 1; i < prices.size(); i++) {
                maxCur = max(0, maxCur += prices[i] - prices[i-1]);
                maxSoFar = max(maxCur, maxSoFar);
            }
            return maxSoFar;
        }
    
    */
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,5,5,4,3,2,1,0};

    // Method Invocation & Result Visualization
    cout << sol.maxProfit2(prices1) << endl;
    cout << sol.maxProfit2(prices2) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^2) TC | Brute Force
    - Find all possible profit numbers for each element in the prices array.
    - This is done using 2 nested loops where outer loop goes from i: 0->n & outer loop goes from j: i+1->n-1
    - now calulate curr_profit for each pair of prices
    - and at the end of each itearation, curr_profit challenges max_profit that if curr_profit exceeds max_profit then update max_profit

2.  O(1) extra space & O(n) TC | OPTIMIZED
    - maxProfit if stock is sold at the given day "i" is achieved if it was bought at min_so_far price.
    - Iterate over the prices array i: 0->n-1
    - maintain a min_so_far variable that stores the minimum price seen till now
    - so, curr_profit would be (prices[i] - min_so_far)
    - and at the end of each itearation, curr_profit challenges max_profit that if curr_profit exceeds max_profit then update max_profit

*/

