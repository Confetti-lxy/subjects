#include <iostream>
#include <string>

using namespace std;

string num1[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string num2[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string num3[4] = {"Hundred", "Thousand", "Million", "Billion"};
string num4[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                   "Nineteen"};
string string1 = "";
string ans[4] = {" ", " ", " ", " "};

int main() {
    long long num;
    cin >> num;
    int sac = 0;
    if (num == 0)
        cout << "Zero";
    while (num > 0) {
        string1.clear();
        int s = num % 1000;
        if (s > 0) {
            int n = s / 100;
            if (n != 0) {
                string1.append(num1[n]);
                string1.append(" ");
                string1.append(num3[0]);
                string1.append(" ");
            }
            n = (s / 10) % 10;
            if (n != 0) {
                if (n != 1) {
                    string1.append(num2[n]);
                    string1.append(" ");
                    n = s % 10;
                    if (n != 0) {
                        string1.append(num1[n]);
                        string1.append(" ");
                    }
                } else {
                    n = s % 10;
                    string1.append(num4[n]);
                    string1.append(" ");
                }
            } else {
                n = s % 10;
                if (n != 0) {
                    string1.append(num1[n]);
                    string1.append(" ");
                }
            }
        }
        if (sac > 0 && string1 != "") {
            string1.append(num3[sac]);
            string1.append(" ");
        }
        ans[sac] = string1;
        sac++;
        num /= 1000;
    }
    for (int i = 3; i >= 0; i--) {
        if (ans[i] != " ") {
            cout << ans[i];
        }
    }
    cout << endl;
}