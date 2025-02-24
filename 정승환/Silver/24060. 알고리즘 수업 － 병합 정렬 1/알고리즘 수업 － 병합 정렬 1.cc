#include <iostream>
using namespace std;

const int MAX_N = 500005;
int arr[MAX_N], temp[MAX_N];
int n, k, cnt, result = -1;

void merge(int start, int mid, int end) {
    int i = start, j = mid + 1, t = start;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) temp[t++] = arr[i++];
        else temp[t++] = arr[j++];
    }
    while (i <= mid) temp[t++] = arr[i++];
    while (j <= end) temp[t++] = arr[j++];
    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
        if (++cnt == k) result = arr[i];
    }
}

void merge_sort(int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(0, n - 1);
    cout << result;
    return 0;
}