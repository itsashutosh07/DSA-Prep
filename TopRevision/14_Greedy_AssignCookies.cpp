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

// Striver's Greedy Playlist #Assign Cookies
// https://takeuforward.org/plus/dsa/problems/assign-cookies?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie.
    Given two arrays, student and cookie, the ith value in the Student array describes the minimum size of cookie that the ith student can be assigned. The jth value in the Cookie array represents the size of the jth cookie. If Cookie[j] >= Student[i], the jth cookie can be assigned to the ith student.
    Maximize the number of students assigned with cookies and output the maximum number.

Example 1:
    Input : student = [1, 2, 3] , cookie = [1, 1]
    Output : 1
    Explanation : 
        You have 3 students and 2 cookies.
        The minimum size of cookies required for students are 1 , 2 ,3.
        You have 2 cookies both of size 1, So you can assign the cookie only to student having minimum cookie size 1.
        So your answer is 1.

Example 2:
    Input : student = [1, 2] , cookie = [1, 2, 3]
    Output : 2
    Explanation : 
        You have 2 students and 3 cookies.
        The minimum size of cookies required for students are 1 , 2.
        You have 3 cookies and their sizes are big enough to assign cookies to all students.
        So your answer is 2.

Constraints:
    1 <= student.length <= 10^4
    1 <= cookie.length <= 10^4
    1 <= student[i], cookie[j] <= 10^9

*/ 


class Solution {
private:

    int solve(vector<int>& student, vector<int>& cookie, int i, int j) {
        if (i == student.size() || j == cookie.size())
            return 0;
        if (cookie[j] < student[i])
            return solve(student, cookie, i, j + 1);
        return max(
            1 + solve(student, cookie, i + 1, j + 1),
            solve(student, cookie, i, j + 1)
        );
    }

public:

    int findMaximumCookieStudents1(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        return solve(student, cookie, 0, 0);
    }

    // int findMaximumCookieStudents2(vector<int>& Student, vector<int>& Cookie) {
    //     //your code goes here
    // }

    // int findMaximumCookieStudents3(vector<int>& Student, vector<int>& Cookie) {
    //     //your code goes here
        
    // }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> student1 = {1, 2, 3};
    vector<int> cookie1 = {1, 1};

    vector<int> student2 = {1, 2};
    vector<int> cookie2 = {1, 2, 3};

    vector<int> student2 = {1, 2};
    vector<int> cookie2 = {1, 2, 3};


    // Method Invocation & Result Visualization
    cout << sol.findMaximumCookieStudents1(student1, cookie1) << endl;
    cout << sol.findMaximumCookieStudents1(student2, cookie2) << endl;

    // cout << sol.findMaximumCookieStudents2(student1, cookie1) << endl;
    // cout << sol.findMaximumCookieStudents2(student2, cookie2) << endl;

    // cout << sol.findMaximumCookieStudents3(student1, cookie1) << endl;
    // cout << sol.findMaximumCookieStudents3(student2, cookie2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(n*m) + O(n+m) | Memoization
    # Recursion + DP

2. TC: O(n*m) | SC: O(n*m) | Tabulation
    # Bottom-up DP

3. TC: O(n*logn + m*logm) | SC: O(1) | OPTIMIZED
    # Greedy (sort + two pointer)

*/
