#include <string>
#include <iostream>
using namespace std;

int num[26] = {0}, visited[26] = {0};
void init(string &my_string);
string getminstring(string &my_string);

int main()
{
    string my_string;
    cin >> my_string;
    init(my_string);
    string result = getminstring(my_string);
    cout << result << endl;
}

void init(string &my_string)
{
    int number = my_string.size();
    for (int i = 0; i < number; i++)
    {
        num[my_string[i] - 'a']++;
    }
}

string getminstring(string &my_string)
{
    string ans = "";
    ans.push_back(my_string[0]);
    visited[my_string[0] - 'a'] = 1;
    num[my_string[0] - 'a']--;
    int n = my_string.size();
    for (int i = 1; i < n; i++)
    {
        if (visited[my_string[i] - 'a'])
        {
            num[my_string[i] - 'a']--;
            continue;
        }
        while (ans.size() > 0 && my_string[i] < ans.back() && num[ans.back() - 'a'] != 0)
        {
            visited[ans.back() - 'a'] = 0;
            ans = ans.substr(0, ans.size() - 1);
        }
        ans.push_back(my_string[i]);
        visited[my_string[i] - 'a'] = 1;
        num[my_string[i] - 'a']--;
    }
    return ans;
}
