##### Header
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast, unroll-loops")
#define int long long
using namespace std;
```
##### Helpful defines
```Cpp
#define logv(v) for(auto i:v) cout<<i<<' ';  
#define logv2D(v) for (auto i:v) {for(auto j:i)cout<<j<<' ';cout<<endl;}  
#define readv(v) for(auto &i : v) cin>>i;  
#define allv(v) v.begin(), v.end()  
#define rallv(v) v.rbegin(), v.rend()
```
##### File
```Cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```
##### Main
```cpp
signed main() {  
   ios::sync_with_stdio(0);cin.tie(0);  
   int t=1;  
//   cin>>t;  
   while(t--)  
      solve();  
   return 0;  
}
```
##### Get Char to the end of line
```Cpp
int c = 0;  
while((c=getchar()) != '\n' && c != EOF){}
```
##### Find with string
```Cpp
str.find('x') != variant_npos
```