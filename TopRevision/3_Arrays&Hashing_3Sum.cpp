
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: May 26, 2026
// Creation TIME: 10:21:36

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver-79 #3 Sum

/*
DESCRIPTION :

    Given an integer array nums. Return all triplets such that:
        > i != j, i != k, and j != k
        > nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.


Example 1:
    Input: nums = [2, -2, 0, 3, -3, 5]
    Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]
    Explanation:
        nums[1] + nums[2] + nums[0] = 0
        nums[4] + nums[1] + nums[5] = 0
        nums[4] + nums[2] + nums[3] = 0

Example 2:
    Input: nums = [2, -1, -1, 3, -1]
    Output: [[-1, -1, 2]]
    Explanation:
        nums[1] + nums[2] + nums[0] = 0
        Note that we have used two -1s as they are separate elements with different indexes
        But we have not used the -1 at index 4 as that would create a duplicate triplet


Constraints:
    1 <= nums.length <= 3000
    -104 <= nums[i] <= 104

*/ 


class Solution {
public:
    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // Found a triplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        
                        /* Sort the triplet to ensure
                         uniqueness when storing in set*/
                        sort(temp.begin(), temp.end());
                        tripletSet.insert(temp);
                        
                    }
                }
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

       //Return the ans
        return ans;
    }

    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n; i++) {
            // Set to store elements seen so far in the loop
            set<int> hashset;

            for (int j = i + 1; j < n; j++) {
                // Calculate the 3rd element needed to reach target
                int third = - (nums[i] + nums[j]);

                /* Find if third element exists in
                hashset (complements seen so far)*/
                if (hashset.find(third) != hashset.end()) {
                    // Found a triplet that sums up to target
                    vector<int> temp = {nums[i], nums[j], third};
                    
                    /* Sort the triplet to ensure 
                    uniqueness when storing in set*/
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }
                
                /* Insert the current element
                into hashset for future checks*/
                hashset.insert(nums[j]);
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        //Return the ans
        return ans;
    }


    vector<vector<int>> threeSumOptimised(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
         
        for (int i = 0; i <= sz - 3; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = sz - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++; k--;
                }
                else if (total > 0)
                    k--;
                else 
                    j++;
            }
        }
        return ans;
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> inp1 = {2, -2, 0, 3, -3, 5};
    vector<int> inp2 = {2, -1,  -1, 3, -1};

    // Method Invocation
    vector<vector<int>> res1 = sol.threeSumOptimised(inp1);
    vector<vector<int>> res2 = sol.threeSumOptimised(inp2);

    // Result Visualization

    for(auto x : res1)
        printVector(x);
    cout << endl;
    for(auto x : res2)
        printVector(x);

    return 0;
}

/*
SOLUTIONS:-

1. TC: O(N^3 x log(no. of unique triplets)) | SC: O(2 x no. of the unique triplets) | Brute Force
    - O(N^3 x log(no. of unique triplets)), where N is size of the array. Using 3 nested loops & inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
    - O(2 x no. of the unique triplets) for using a set data structure and a list to store the triplets.

2. TC:  O(N^2 x log(no. of unique triplets)) | SC: O(2 x no. of the unique triplets) + O(N) | Better
    - O(N^2 x log(no. of unique triplets)), where N is size of the array.
        Inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. However, we are not considering the time complexity of sorting, as we are only sorting 3 elements each time.
        Note: For Java (HashSet), insertion operation takes O(1) time. Thus, the overall time complexity for Java code will be O(N^2)
    - O(2 x no. of the unique triplets) + O(N) for using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

3.  TC: O(NlogN)+O(N^2) | SC: O(1) | OPTIMIZED
    - O(NlogN)+O(N2), where N is size of the array. As the pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2).
    - O(1), no extra space is used.

*/

