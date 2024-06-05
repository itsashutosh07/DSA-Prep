#include <bits/stdc++.h>

using namespace std;

int main()
{
    //       1 2 3 -----
    //                 |
    //  ---- 6 5 4 <--- 
    // |
    // ----> 7 8 9
    int n, curr = 1;
    cout << "Enter the no. of rows/collumns you want: ";
    cin >> n;

    cout << endl;
    for (int j = 0; j < n; j++) {
        cout << curr << "\t";
        curr++;
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)  {
            curr += n+1;
            for (int j = 0; j < n; j++) {
                cout << curr << "\t";
                curr++;
            }
            cout << endl;
        }
        else {
            curr += n-1;
            for (int k = 0; k < n; k++) {
                cout << curr << "\t";
                curr--;
            }
            cout << endl;            
        }
        
    }
    

    return 0;
}