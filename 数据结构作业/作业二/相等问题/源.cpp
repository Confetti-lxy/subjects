#include <iostream>
#include <string>
using namespace std;

long count(string s);

int main()
{
    string s;
    cin >> s;
    long m = count(s);
    if (m == 0)
        cout << 0;
    else
        cout << m << endl;
}

long count(string s)
{
    long n = s.size();
    long count = 0;
    for (long i = 0; i < n; i++)
        if (s[i] == '1')
            count++;
    return count;
}