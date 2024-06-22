
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 10, 2024
// Creation TIME: 23:35:44

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #Question_Title

/*
DESCRIPTION :




Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]
*/ 


class Solution {
    public:
    int search1(string pat, string txt) {
	    int k = pat.size();
	    int i = 0, j = 0, n = txt.size(), windowSize = 0, ans = 0;
	    
	    unordered_map<char, int> freq;
	    for(char x: pat) freq[x]++;
	    
	    int cnt = freq.size();
	    
	    cout << txt << endl;
	    while (j < n) {
            cout << txt[i] << ":" << i << " | " << txt[j] << ":" << j << " | ";
	        windowSize = j - i + 1;
            if (windowSize < k)
                cout << "f=" << freq['f'] << ", o=" << freq['o'] << ", r=" << freq['r'] << ", cnt:" << cnt  << " || ANS:" << ans<< endl;
	        if (freq.find(txt[j]) != freq.end()) {
                freq[txt[j]]--;
	            if (freq[txt[j]] == 0) 
	                cnt--;
            }
	        if (windowSize == k) {
	            if (cnt == 0) ans++;
                
                cout << "f=" << freq['f'] << ", o=" << freq['o'] << ", r=" << freq['r'] << ", cnt:" << cnt  << " || ANS:" << ans<< endl;
	            
	            if (freq.find(txt[i]) != freq.end()) {
	                if (freq[txt[i]] == 0) 
	                    cnt++;
	                freq[txt[i]]++;
	            }
	            i++;
	        }
	        j++;
	    }
	    return ans;
	}

    int search2(string pat, string txt) {
        unordered_map <char, int> m;
        for(auto i: pat) m[i]++;

        int k = pat.size(), count = m.size();
        int ans = 0, i = 0, j = 0;

        while(j < txt.size()) {
            if(m.find(txt[j]) != m.end()) {
                m[txt[j]]--;
                if(m[txt[j]] == 0)
                    count--;
            }

            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                if(count == 0)
                    ans++;

                if(m.find(txt[i]) != m.end()) {
                    m[txt[i]]++;
                    if(m[txt[i]] == 1)
                        count++;
                }
                i++; j++;
            }
        }

        return ans;
    }

};


int main() 
{
    Solution sol;

    // Method Invocation
    cout << sol.search1("for", "forxrooooooofxorfxdofr");

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

