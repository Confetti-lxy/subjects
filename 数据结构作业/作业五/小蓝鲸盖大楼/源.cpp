#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0, sum = 0;
    cin >> n;
    vector <vector<int>> city(n, vector<int>(n));
    vector<int> height1, height2;
    for (int i = 0; i < n; i++) {
        int max_tall = 0;
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            max_tall = max(max_tall, city[i][j]);
        }
        height1.push_back(max_tall);
    }
    for (int j = 0; j < n; j++) {
        int max_tall = 0;
        for (int i = 0; i < n; i++) {
            max_tall = max(max_tall, city[i][j]);
        }
        height2.push_back(max_tall);
    }
    vector <vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = min(height1[i], height2[j]);
            sum += (0, ans[i][j] - city[i][j]);
        }
    }
    cout << sum << endl;
}