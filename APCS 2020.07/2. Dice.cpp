// v1.0 - Correct Answer
#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <cstring>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// const int MAXN = 25;
// const int Mod = 1e9 + 7;
int n, m, u[25], f[25], r[25], o[7] = {0, 6, 5, 4, 3, 2, 1};

signed main(){
    opt;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        u[i] = 1;
        f[i] = 4;
        r[i] = 2;
    }
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        if (b == -1){
            f[a] = o[f[a]];
            swap(u[a], f[a]);
        }
        else if (b == -2){
            r[a] = o[r[a]];
            swap(u[a], r[a]);
        }
        else{
            swap(u[a], u[b]);
            swap(f[a], f[b]);
            swap(r[a], r[b]);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << u[i] << " ";
    }
    cout << "\n";
}