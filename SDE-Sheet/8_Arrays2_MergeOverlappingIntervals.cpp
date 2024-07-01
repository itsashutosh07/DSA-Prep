
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 13:20:49

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #56. Merge Intervals

/*
DESCRIPTION :
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
    and return an array of the non-overlapping intervals that cover all the intervals in the input.
 

Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:
    1 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= start-i <= end-i <= 10^4


*/ 


class Solution {
    public:
    vector<vector<int>> merge1(vector<vector<int>> &arr) {
        int n = arr.size(); // size of the array
        
        sort(arr.begin(), arr.end()); //sort the given intervals

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) { // select an interval:
            int start = arr[i][0];
            int end = arr[i][1];

            if (!ans.empty() && end <= ans.back()[1]) { //Skip all the already merged intervals
                continue;
            }

            //check the rest of the intervals
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }

    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int start = intervals[0][0], end = intervals[0][1], s, e;
        for (int i = 1; i < intervals.size(); i++) {
            s = intervals[i][0];
            e = intervals[i][1];
            if (s <= end) {
                end = e > end ? e : end;
            }
            else {
                vector<int> temp {start, end};
                ans.push_back(temp);
                start = s;
                end = e;
            }
        }
        // both cases of last merging-interval & last individual interval need to be explictally added to answer vector
        vector<int> temp {start, end};
        ans.push_back(temp);

        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {16, 19}};
    vector<vector<int>> intervals2 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals3 = {{1, 4}, {4, 5}};
    vector<vector<int>> intervals4 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {4, 6}, {4, 4}, {4, 10}, {10, 10}, {10, 11}, {3, 4}, {4, 5}};
    vector<vector<int>> intervals5 = {{1, 4}, {2, 3}};


    // Method Invocation & Result Visualization
    printFormattedMatrix(sol.merge1(intervals1));
    printFormattedMatrix(sol.merge1(intervals2), "{", "}", "_", "\n");
    printFormattedMatrix(sol.merge1(intervals3), "(", ")", " ", "");
    printFormattedMatrix(sol.merge1(intervals4), "'", "'", ",", "");
    printFormattedMatrix(sol.merge1(intervals5), "|", "|", ",", "");

    return 0;
}

/*
SOLUTIONS:-

1. O(n) Space & O(n^2) TC | Brute Force | strivers
    - We are just grouping close intervals by sorting the given array. 
    - After that, we merge an interval with the other by checking if one can be a part of the other interval. 
        - For this checking, we are first selecting a particular interval using a loop 
        - and then we are comparing the rest of the intervals using another loop.
        - We will compare the current interval’s start with the end of the selected interval. 
        - If the start is greater than the end, we can conclude the current interval cannot be a part of the selected interval.

2. O(n) Space & O(n^2) TC | Optimized | self
    - since there is one interval present in intervals array given by constrains we initialize :
        - start = intervals[0][0] -and- end = intervals[0][1] 
    - now start a loop i : 1->n-1 inclusive, 
        - for each encountered interval we see whats the begganing and last of this interval :
            - s = intervals[i][0] -&- e = intervals[i][1]
        - if (s ≤ end)
            - then update the end to be: max(end, e), 
            - max b'coz this encountered interval could be entirely inside our start,end 's interval
        - else our s > end
            - this means that we have found a new interval
            - now make a temp vector and add start, end to it and put it to answer vector
    - last interval would be left out and was not added to answer vector, values of it are present in our start,end variables
    - there can be 2 cases for the last interval:
        1. last interval was pa part of a cointinued interval from before
        2. last interval was an individual n seperate interval. 
    - both cases will be handelled if a extra temp vector containing {start,end} was explictally added to answer vector
    - return answer vector

*/

