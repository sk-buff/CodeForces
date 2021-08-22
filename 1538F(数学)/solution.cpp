#include <iostream>

using namespace std;

int main() {
    int caseNum;
    int num1, num2;
    int num1Bits[15], num2Bits[15];

    cin >> caseNum;

    while (caseNum--) {
        cin >> num1 >> num2;

        int len1 = 0, len2 = 0, divisor = 1, quotient1, quotient2;
        long long diff1 = 0, diff2 = 0;
        fill(num1Bits, num1Bits+15, 0);
        fill(num2Bits, num2Bits+15, 0);
        do {
            quotient1 = num1 / divisor;
            quotient2 = num2 / divisor;

            if (quotient1 != 0)
                num1Bits[len1++] = quotient1;

            if (quotient2 != 0)
                num2Bits[len2++] = quotient2;
            
            divisor *= 10;
        } while(quotient1 != 0 || quotient2 != 0);

        for (int i = 0; i < len1; i++) {
            num1Bits[i] -= num1Bits[i+1];
            diff1 += num1Bits[i] * (i + 1);
        }

        for (int i = 0; i < len2; i++) {
            num2Bits[i] -= num2Bits[i+1];
            diff2 += num2Bits[i] * (i + 1);
        }

        cout << diff2 - diff1 << endl;
    }
}