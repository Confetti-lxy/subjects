#include <stack>
#include <stdio.h>

using namespace std;

int nums[3000005] = {0}, ans[3000005] = {0};

int main()
{
    int n = 0;
    scanf("%d", &n);
    stack<int> my_stack;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        while (!my_stack.empty() && nums[my_stack.top()] <= nums[i])
        {
            my_stack.pop();
        }
        ans[i] = my_stack.empty() ? 0 : my_stack.top();
        my_stack.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
}