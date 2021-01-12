#include <bits/stdc++.h>
using namespace std;

int a[5050], N, K; 
bool chk(int x){
    bitset<5050> dp; dp[0] = 1;
    for (int i = 1; i <= N; i++)
        if (i != x) dp |= dp << a[i];
    for (int i = K - a[x]; i < K; i++)
        if (dp[i]) return 1;
    return 0;
}

signed main(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        if (a[i] > K) i --, N --;
    }
    sort(a + 1, a + N + 1);
    int l = 1, r = N, res = 0;
    // for (int i = 1; i <= N; i++){
    //     cout << chk(i) << endl;
    // }
    while(l <= r){
        int m = (l + r) >> 1;
        if (chk(m)){
            r = m - 1;
        }else{
            l = m + 1;
            res = m;
        }
    }
    cout << res;
    return 0;
}
