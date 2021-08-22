#include <iostream>
#include <algorithm>

using namespace std;

struct item {
    long long demand, countNum;
} item[100005];

long long suffixSum[100005];

int cmp(struct item a, struct item b) {
    return a.countNum < b.countNum;
}

int main() {
    int itemNum;
    long long cost = 0, totalNum = 0;

    cin >> itemNum;
    for (int i = 0; i < itemNum; i++) {
        cin >> item[i].demand >> item[i].countNum;
        totalNum += item[i].demand;
    }

    sort(item, item+itemNum, cmp);
    suffixSum[itemNum-1] = item[itemNum-1].demand;
    for (int i = itemNum - 2; i >= 0; i--)
        suffixSum[i] = suffixSum[i+1] + item[i].demand;

    int st = 0, ed = itemNum - 1;
    long long purchsedItem = 0, purchsedTailItem = 0;
    for (int i = itemNum - 1; i >= 0; i--) 
        if (totalNum < item[i].countNum) {
            cost += 2 * item[i].demand;
            purchsedItem += item[i].demand;
            purchsedTailItem += item[i].demand;
            ed--;
        }

    while(purchsedItem != totalNum) {
        if (purchsedItem >= item[st].countNum) {
            cost += item[st].demand;
            purchsedItem += item[st].demand;
            st++;
        }
        else {
            int l = st, r = ed, mid;
            while (l < r) {                
                mid = (l + r + 1) >> 1;
                if (suffixSum[mid] - purchsedTailItem >= item[st].countNum - purchsedItem)
                    l = mid;
                else
                    r = mid - 1;
            }
            
            if (suffixSum[l] - purchsedTailItem >= item[st].countNum - purchsedItem) {
                cost += 2 * (item[st].countNum - purchsedItem);
                ed = r;
                purchsedTailItem += item[st].countNum - purchsedItem;
                purchsedItem += item[st].countNum - purchsedItem;
                item[ed].demand = suffixSum[ed] - purchsedTailItem;
            }
            else {
                cost += 2 * (item[ed].demand);
                purchsedItem += item[ed].demand;
            }
        }
    }

    // Version 1, timeout
    /* for (long long i = 0; i < totalNum; i++) {
        if (i < item[st].countNum) {
            item[ed].demand--;
            cost += 2;

            if (item[ed].demand == 0)
                ed--;
        }
        else {
            item[st].demand--;
            cost += 1;

            if (item[st].demand == 0)
                st++;
        }
    } */

    cout << cost << endl;

    return 0; 
}