#include <bits/stdc++.h>

using namespace std;

int reversort(int len, int* arr)
{
    int cnt = 0;

    for (int i = 1; i < len; i++)
    {
        int min_idx = i;
        int min_val = arr[i];
        //printf("Now arr_val : %d\n", arr[i]);

        for (int j = i; j <= len; j++)
        {
            if (min_val > arr[j])
            {
                min_idx = j;
                min_val = arr[j];
            }
        }

        int mid = (i + min_idx) / 2;
        int diff = min_idx - i;
        //printf("Now mid : %d\n", mid);
        //printf("Now min : %d\n", min_idx);

        for (int j = 0; j <= diff / 2; j++)
        {
            int tmp = arr[min_idx - j];
            arr[min_idx - j] = arr[i + j];
            arr[i + j] = tmp;
        }

        cnt += min_idx - i + 1;

        //printf("Now cnt : %d\n", cnt);
        /*printf("Now arr\n");
        for(int j = 1; j <= len; j++)
            printf("%d ", arr[j]);
        printf("\n");*/
    }

    return cnt;
}

int main(void)
{
    int tcase;

    scanf("%d", &tcase);

    for (int i = 1; i <= tcase; i++)
    {
        int n, ans;
        int arr[105];

        scanf("%d", &n);

        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[j]);

        ans = reversort(n, arr);

        printf("Case #%d: %d\n", i, ans);
    }

    return 0;
}