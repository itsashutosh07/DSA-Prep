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

// Striver's Greedy Playlist #Job Sequencing Problem
// https://takeuforward.org/plus/dsa/problems/job-sequencing-problem?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    You are given a set of N jobs where each job comes with a deadline and profit.
    The profit can only be earned upon completing the job within its deadline.
    Find the number of jobs done and the maximum profit that can be obtained.
    Each job takes a single unit of time and only one job can be performed at a time.
    Jobs[i] = [id, deadline, profit]

Example 1:
    Input:
        N = 4, Jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}
    Output: [2, 60]
    Explanation:
        The 3rd job with a deadline of 1 is performed during the first unit of time.
        The 1st job is performed during the second unit of time as its deadline is 4.
        Profit = 40 + 20 = 60.
        So, the result is 2 jobs with a total profit of 60.

Example 2:
    Input:
        N = 5, Jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}}
    Output: [2, 127]
    Explanation:
        The first and third jobs, both having a deadline of 2, give the highest profit.
        Profit = 100 + 27 = 127.
        So, the result is 2 jobs with a total profit of 127.

Constraints:
    1 <= N <= 10^5
    1 <= deadline[i] <= 100
    1 <= profit[i] <= 500

*/ 


class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<vector<int>> jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};


    // Method Invocation & Result Visualization
    printVector(sol.JobScheduling(jobs1));
    printVector(sol.JobScheduling(jobs2));


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N log N + N*M) | SC: O(M) | Greedy
    # Sort by profit descending, place each job in latest free slot before deadline

*/
