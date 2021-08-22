#include <iostream>
#include <algorithm>

using namespace std;

long long student[200005], diff[200005];

int main() {
    long long k, x;
    long long diffNum = 0, groupNum;
    int n;

    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> student[i];

    sort(student, student+n);

    for (int i = 0; i < n - 1; i++)
        if (student[i+1] - student[i] > x)
            diff[diffNum++] = (student[i+1] - student[i]) / x + (((student[i+1] - student[i]) % x) ? 1 : 0) - 1;
    groupNum = diffNum + 1;

    sort(diff, diff+diffNum);  

    for (int i = 0; i < diffNum; i++) {
        if (diff[i] <= k) {
            k -= diff[i];
            groupNum--;
        }
        else
            break;
    }

    cout << groupNum << endl;
}