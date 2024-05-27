#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int max_sum = -1e9;
    int curr_sum = 0;
    int min_odd = 1e9;

    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];
        if (curr_sum % 2 == 0) {
            max_sum = curr_sum > max_sum ? curr_sum : max_sum;
        } else {
            min_odd = min_odd < arr[i] ? min_odd : arr[i];
        }
    }

    if (max_sum == -1e9) {
        printf("NOT_FOUND\n");
        return 0;
    }

    if (curr_sum % 2 != 0) {
        max_sum = curr_sum - min_odd > max_sum ? curr_sum - min_odd : max_sum;
    }

    printf("%d\n", max_sum);
    return 0;
}
