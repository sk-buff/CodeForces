#include <cstdio>

int main() {
    char s[500005];
    int i, j, l, n, k, ed, flag;

    scanf("%d%d", &n, &k);
    scanf("%s", s);

    ed = n < k ? n : k;
    for (i = 0; i < ed; i++)
        if (s[0] < s[i])
            break;
        else if (s[0] == s[i]) {
            flag = 0;
            for (j = 0, l = i; j < i && l < k; j++, l++)
                if (s[j] < s[l % n]) {
                    flag = 1;
                    break;
                } else if (s[j] > s[l % n])
                    break;
            
            if (flag == 1)
                break;
        }

    for (j = 0; j < k; j++)
        printf("%c", s[j%i]);
    printf("\n");
}