#include <iostream>

using namespace std;

int main()
{
    int len, i=0, j=0, iterMax=1, fullMax=1;
    string seq;
    cin >> seq;

    len = seq.size();

    // for (int i = 0; i < len-1; i++)
    while (i < len-1)
    {
        // for (int j = i+1; j < len; j++)
        j = i+1;
        while(j < len)
        {
            if (seq[j] == seq[j-1])
            {
                j++;
                iterMax++;
            }
            else
            {
                break;
            }
        }
        i += iterMax;

        if (fullMax < iterMax)
        {
            fullMax = iterMax;
        }
        iterMax = 1;
    }
    
    cout << fullMax;

    return 0;
}