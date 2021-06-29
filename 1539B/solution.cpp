#include <iostream>

using namespace std;

int main() {
    int len, qNum, l, r;
    string song;
    int sum[100005];

    cin >> len >> qNum;
    cin >> song;
    
    for (int i = 0; i < len; i++) 
        sum[i+1] = song[i] - 'a' + 1;
    
    sum[0] = 0;
    for (int i = 1; i <= len; i++)
        sum[i] += sum[i-1];

    for (int i = 0; i < qNum; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << endl;
    }
}