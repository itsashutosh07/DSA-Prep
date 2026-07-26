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

// Striver's Greedy Playlist #Candy
// https://takeuforward.org/plus/dsa/problems/candy?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.
    These kids are receiving candy according to the following criteria:
        - There must be at least one candy for every child.
        - Kids whose scores are higher than their neighbours receive more candies than their neighbours.
    Return the minimum number of candies needed to distribute among children.

Example 1:
    Input: ratings = [1, 0, 2]
    Output: 5
    Explanation:
        You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
    Input: ratings = [1, 2, 2]
    Output: 4
    Explanation:
        You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
        The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
    1 <= ratings.length <= 2 * 10^4
    0 <= ratings[i] <= 2 * 10^4

*/ 


class Solution {
public:
    int candy1(vector<int>& ratings) {
        //your code goes here
    }

    int candy2(vector<int>& ratings) {
        //your code goes here
    }

    int candy3(vector<int>& ratings) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> ratings1 = {1, 0, 2};
    vector<int> ratings2 = {1, 2, 2};


    // Method Invocation & Result Visualization
    cout << sol.candy1(ratings1) << endl;
    cout << sol.candy1(ratings2) << endl;

    cout << sol.candy2(ratings1) << endl;
    cout << sol.candy2(ratings2) << endl;

    cout << sol.candy3(ratings1) << endl;
    cout << sol.candy3(ratings2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^2) | SC: O(N) | Brute Force
    # Repeatedly adjust candies until neighbour constraints satisfied

2. TC: O(n) | SC: O(n) | Better
    # Two-pass left-to-right and right-to-left with candy array

3. TC: O(n) | SC: O(1) | OPTIMIZED
    # Single-pass peak/valley slope counting

*/
