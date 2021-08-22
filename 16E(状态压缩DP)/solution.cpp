#include <cstdio>

double p[20][20];
double dp[0x3ffff + 5];
int n;

double transp(int state, int dieFishIndex) {
    int i, aliveFishNum = 0;
    double totalP = 0.0;

    for (i = 0; i < n; i++) {
        if (!(state & 1 << i)) {
            aliveFishNum++;
            totalP += p[i][dieFishIndex];
        }
    }

    return 2 * totalP / (aliveFishNum * (aliveFishNum - 1));
}

int main() {
    int i, j, state;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &p[i][j]);

    dp[0] = 1.0;
    for (i = 1; i < ((1 << n) - 1); i++) {
        for (j = 0; j < n; j++) {
            state = i & ~(0xffffffff & 1 << j);
            if (state != i) {
                dp[i] += dp[state] * transp(state, j);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf(i == (n - 1) ? "%.6lf\n" : "%.6lf ", dp[(~(1 << i)) & ((1 << n) - 1)]);
    }
}