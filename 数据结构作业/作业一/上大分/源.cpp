#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *score = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    int sum = score[0], max_sum = score[0];
    for (int i = 1; i < n; i++)
    {
        if (sum < 0)
        {
            sum = score[i];
        }
        else
        {
            sum += score[i];
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    cout << max_sum << endl;
}