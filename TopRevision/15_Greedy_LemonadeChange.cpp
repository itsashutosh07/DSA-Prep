#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 07:40:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Greedy Playlist #Lemonade Change
// https://takeuforward.org/plus/dsa/problems/lemonade-change?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change to each customer.
    Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand.
    Return true, if it is possible to provide correct change for each customer otherwise return false.
    Each lemonade costs 5$.

Example 1:
    Input: bills = [5, 5, 5, 10, 20]
    Output: true
    Explanation:
        Initially we have 0 change and the queue of customers is [5, 5, 5, 10, 20].
        First Customer pays 5$, no change required.
        Second Customer pays 5$, no change required.
        Third Customer pays 5$, no change required.
        The Fourth Customer pays 10$, out of the three 5$ bills we have, we pay a 5$ bill and accept the 10$ bill.
        Fifth Customer pays 20$, out of the two 5$ bills and one 10$ bill we have, we pay 15$ in change and have one 5$ bill left.
        Hence, it is possible to provide change to all customers.

Example 2:
    Input: bills = [5, 5, 10, 10, 20]
    Output: false
    Explanation:
        Initially, we have 0 change and the queue of customers is [5, 5, 10, 10, 20].
        The first customer pays 5$, no change required.
        The second customer pays 5$, no change required.
        The third customer pays 10$, we collect a 5$ bill and give back a 5$ bill.
        The fourth customer pays 10$, we collect a 5$ bill and give back a 5$ bill.
        The fifth customer pays 20$, we cannot give the change of $15 back because we only have two $10 bills.
        Since not every customer received the correct change, the answer is false.

Constraints:
    1 <= bills.length <= 10^5
    bills[i] is either 5, 10, or 20

*/ 


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> bills1 = {5, 5, 5, 10, 20};
    vector<int> bills2 = {5, 5, 10, 10, 20};


    // Method Invocation & Result Visualization
    cout << boolalpha << sol.lemonadeChange(bills1) << endl;
    cout << sol.lemonadeChange(bills2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N) | SC: O(1) | Greedy
    # Track count of 5$ and 10$ bills while serving customers

*/
