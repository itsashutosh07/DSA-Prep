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

// Striver's Greedy Playlist #Shortest Job First
// https://takeuforward.org/plus/dsa/problems/shortest-job-first?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Given a list of job durations (burst times) representing the time it takes to complete each job.
    Implement the Shortest Job First algorithm to find the average waiting time for these jobs.
    (Return the floor of the average waiting time as a long long, as per TUF+.)

Example 1:
    Input: jobs = [3, 1, 4, 2, 5]
    Output: 4
    Explanation:
        Execute jobs in increasing order of duration: 1, 2, 3, 4, 5
        Waiting times: 0, 1, 3, 6, 10
        Average waiting time = (0 + 1 + 3 + 6 + 10) / 5 = 4

Example 2:
    Input: jobs = [4, 3, 7, 1, 2]
    Output: 4
    Explanation:
        Execute jobs in increasing order of duration: 1, 2, 3, 4, 7
        Waiting times: 0, 1, 3, 6, 10
        Average waiting time = (0 + 1 + 3 + 6 + 10) / 5 = 4

Constraints:
    1 <= bt.length <= 10^5
    1 <= bt[i] <= 10^5

*/ 


class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        // BT: 1 2 3 4 7
        // WT: 0 1 3 6 10 => 0+1+3+6+10 = 20/5 = 4
        long long totalTime = 0, waitTime = 0, processes = bt.size();
        sort(bt.begin(), bt.end());


        for (int i = 0; i < processes; i++) {
            waitTime += totalTime; // before execting each process, add up the curr total time to the total wait times, before execution of this process
            totalTime += bt[i]; // execute the process -> add up the bt[i]
        }

        return (long long) waitTime / (long long) processes;
    }
};

int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> jobs1 = {3, 1, 4, 2, 5};
    vector<int> jobs2 = {4, 3, 7, 1, 2};


    // Method Invocation & Result Visualization
    cout << sol.solve(jobs1) << endl;
    cout << sol.solve(jobs2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N log N + N) | SC: O(1) | Greedy
    # Sort burst times ascending, compute cumulative waiting time average

*/
