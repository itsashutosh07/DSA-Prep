
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long int> vect;

void wierdAlgo(long long int n);
void display();

int main()
{
    long long int n;
    cin >> n;

    wierdAlgo(n);
    display();

    return 0;
}

void wierdAlgo(long long int n) {
    vect.push_back(n);
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
            vect.push_back(n);
        }
        else {
            n = (n * 3) + 1;
            vect.push_back(n);
        }
    }
}

void display() {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
}