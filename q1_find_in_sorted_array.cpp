#include <bits/stdc++.h>
using namespace std;

int findKey(vector<int> &arr, int tar)
{

    int l = arr.size();
    int st = 0, ed = l - 1;

    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;

        // cout << st << " " << mid << " " << ed << endl;

        if (arr[mid] == tar)
            return mid;

        if (tar >= arr[st])
        {
            if (arr[mid] >= arr[st] && tar > arr[mid])
                st = mid + 1;
            else
                ed = mid - 1;
        }
        else
        {
            if (arr[mid] <= arr[ed] && tar < arr[mid])
                ed = mid - 1;
            else
                st = mid + 1;
        }
    }

    return -1;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = findKey(arr, x);
    cout << ans << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
