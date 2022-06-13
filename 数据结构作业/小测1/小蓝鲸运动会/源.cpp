#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int cal(vector<int> &child);

int main()
{
    int n = 0;
    vector<int> child;
    while (scanf("%d", &n) != EOF)
    {
        child.push_back(n);
    }
    int ans = cal(child);
    cout << ans << endl;
}

int cal(vector<int> &child)
{
    int n = child.size();
    vector<int> sweet(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (child[i] < child[i + 1])
        {
            sweet[i + 1] = sweet[i] + 1;
        }
    }
    for (int j = n - 1; j > 0; j--)
    {
        if (child[j] < child[j - 1] && sweet[j - 1] <= sweet[j])
        {
            sweet[j - 1] = sweet[j] + 1;
        }
    }
    int num = 0;
    for (int i = 0; i < sweet.size(); i++)
    {
        num += sweet[i];
    }
    return num;
}