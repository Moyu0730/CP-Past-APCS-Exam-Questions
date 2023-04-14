#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// const int MAXN = 1e8 + 50;
// const int Mod = 1e9 + 7;
int n;
vector<pair<int, string>> v;
string str;
pair<int, string> tmp;
set<char> s;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> str;
        
        s.clear();
        int len = str.size();
        for( int j = 0 ; j < len ; j++ ) s.insert(str[j]);

        tmp = make_pair(s.size(), str);

        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    // for( auto i : v ) cout << i.first << "\t" << i.second << "\n";
    cout << v[0].second;
}