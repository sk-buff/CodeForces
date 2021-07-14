#include <iostream>

using namespace std;

int main() {
    int m, n;
    int max, min, tmp, team = 0;

    cin >> m >> n;
    max = (m >= n ? m : n);
    min = (m >= n ? n : m);
    while (max >= 2 && min >= 1) {
        max -= 2;
        min -= 1;
        if (min > max) {
            tmp = max;
            max = min;
            min = tmp;
        }
        team++;
    }
    cout << team << endl;

    return 0;
}