#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long caseNum, x, y, a, b;
long long l, r, mid;

bool check(int mid) {
    int min, max;

    // min = ceil(mid / (1 - b / (double)a) - y / (double)(a - b));
    // max = floor(x / (double)(a - b) - mid / (a / (double)b - 1));
    min = ceil(1.0 * (a * mid - y) / (a - b));
    max = floor(1.0 * (x - b * mid) / (a - b));

    if (min <= max && max >= 0 && min <= mid)
        return true;
    else
        return false;
}

int main() {
    cin >> caseNum;
    while (caseNum--) {
        cin >> x >> y >> a >> b;
        
        if (a == b) {
            cout << min(x, y) / a << endl;
            continue;
        }

        if (a < b)
            swap(a, b);
        l = 0, r = max(x, y) / b;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (check(mid) == true)
                l = mid;
            else   
                r = mid - 1;
        }
        cout << l << endl;
    }

    return 0;
}