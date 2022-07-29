#include <iostream>
#include <vector>

using namespace std;

struct square {
    int x, y, width, height;

    square() : x(0), y(0), width(0), height(0) {}

    square(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
};

int main() {
    int n = 0;
    cin >> n;
    vector <square> squares;
    int x = 0, y = 0, width = 0, height = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> width >> height;
        squares.push_back(square(x, y, width, height));
    }
    int loc_x = -1, loc_y = -1;
    cin >> loc_x >> loc_y;
    for (int i = n - 1; i >= 0; i--) {
        if (loc_x >= squares[i].x && loc_y >= squares[i].y) {
            if (loc_x <= squares[i].x + squares[i].width && loc_y <= squares[i].y + squares[i].height) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}