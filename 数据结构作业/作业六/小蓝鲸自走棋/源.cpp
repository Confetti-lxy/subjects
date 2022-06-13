#include <vector>
#include <iostream>
using namespace std;

vector<int> book;

vector<int> input(int n);
vector<int> output(vector<int> &input);
void print(vector<int> &input);

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums = input(n);
    vector<int> res = output(nums);
    print(res);
}

vector<int> input(int n)
{
    vector<int> res(n);
    book.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    return res;
}

vector<int> output(vector<int> &input)
{
    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] < 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (input[j] > 0 && book[j] == 1)
                {
                    if (input[i] + input[j] < 0)
                    {
                        book[j] = 0;
                    }
                    else if (input[i] + input[j] == 0)
                    {
                        book[j] = 0;
                        book[i] = 0;
                        break;
                    }
                    else
                    {
                        book[i] = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (book[i] == 1)
        {
            res.push_back(input[i]);
        }
    }
    return res;
}

void print(vector<int> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
}