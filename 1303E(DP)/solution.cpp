#include <cstdio>
#include <cstring>

#define INF 1000

short dp[405][405];

int main() {
    int n, i, j, k, l;
    int len1, len2, len21, len22;
    int end1, end2;
    int res;
    char s1[405], s2[405];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", s1);
        scanf("%s", s2);

        len1 = strlen(s1);
        len2 = strlen(s2);

        res = 0;
        for (i = 0; i <= len1 - 1; i++) {
            len21 = i + 1;
            len22 = len2 - len21;

            j = k = 1;
            for (l = 0; l < len1; l++) {
                if (s1[l] == s2[j-1] && j <= len21) {
                    dp[j][0] = l;
                    j++;
                }

                if (s1[l] == s2[len21-1+k] && k <= len22) {
                    dp[0][k] = l;
                    k++;
                }
            }

            if (j != len21 + 1 || k != len22 + 1)
                continue;

            for (j = 1; j <= len21; j++) {
                for (k = 1; k <= len22; k++) {
                    end1 = end2 = INF;

                    for (l = dp[j-1][k] + 1; l < len1; l++) {
                        if (s1[l] == s2[j-1]) {
                            end1 = l;
                            break;
                        }
                    }

                    for (l = dp[j][k-1] + 1; l < len1; l++) {
                        if (s1[l] == s2[len21-1+k]) {
                            end2 = l;
                            break;
                        }
                    }

                    if ((dp[j][k] = (end1 < end2 ? end1 : end2)) == INF)
                        goto out;
                }
            }
            res = 1;
out:
            if (res == 1)
                break;
        }
        printf(res == 1 ? "YES\n" : "NO\n");
    }

    return 0;
}