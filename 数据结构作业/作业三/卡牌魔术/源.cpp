#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int *ans = new int[n];
    bool *book = new bool[n];
    for (int i = 0; i < n; i++)
    {
        book[i] = true;
    }
    ans[0] = num[0];
    book[0] = false;
    int location = 0;
    for (int i = 1; i < n; i++)
    {
        int number = num[i];
        while (book[location] == false)
            location = (location + 1) % n;
        location = (location + 1) % n;
        while (book[location] == false)
            location = (location + 1) % n;
        ans[location] = number;
        book[location] = false;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}