#include <iostream>
using namespace std;

int main()
{
    int number[101] = {0};
    int num[101] = {0};
    int n = 0;
    while (scanf("%d", &num[n]) != EOF)
        n++;
    for (int i = 0; i < n; i++)
    {
        number[num[i]]++;
    }
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (number[i] == 1)
            sum += i;
    }
    cout << sum;
}