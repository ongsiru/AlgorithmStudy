#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string S, temp;
    int len, i;

    cin >> S;
    len = S.length();

    temp.push_back(S[0]);
    for (i = 1; i < len; i++)
    {
        if (temp[0] >= S[i])
        {
            reverse(temp.begin(), temp.end());
            temp.push_back(S[i]);
            reverse(temp.begin(), temp.end());
        }
        else
        {
            temp.push_back(S[i]);
        }
    }

    cout << temp;

    return 0;
}