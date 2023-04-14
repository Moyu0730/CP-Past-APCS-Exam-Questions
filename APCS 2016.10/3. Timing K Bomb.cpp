// v1.0 - TLE Version - Solved Thought Simulation

// #include<iostream>
// #include<iomanip>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<algorithm>
// using namespace std;
// #define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// const int MAXN = 1e8 + 50;
// const int Mod = 1e9 + 7;
// vector<int> vec;
// int n, m, k;

// signed main(){
//     opt;
//     cin >> n >> m >> k;
//     for( int i = 0 ; i < n ; i++ ) vec.emplace_back(i+1);

//     // 1 2 3 4 5 
//     // 1 3 4 5
//     int ind = 0;
//     while( k-- ){
//         ind = ( ind + m - 1 ) % vec.size();
//         vec.erase(vec.begin() + ind);
//         ind %= vec.size();
//     }
//     cout << vec[ind];
// }

// v2.0 - O(K) Answer - Solved Thought Backtracking

#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// const int MAXN = 1e8 + 50;
// const int Mod = 1e9 + 7;
int n, m, k, lucky;

signed main(){
    opt;
    cin >> n >> m >> k;
    
    lucky = 0;
    for( int i = n-k+1 ; i <= n ; i++ )
        lucky = ( lucky+ m ) % i;        

    cout << lucky+1 << '\n';
}