What this sheet has?
- Generate all Factorials to max
- nCr using preprocessed factorials
- nPr using preprocessed factorials
- fast Power
- Mod operations
- power inverse
- Catalan using preprocesses factorials
- Stars & Bars
- Properties of `binomial coefficients`
- Pascal's Triangle with pre-generated nCr
- Manhattan Tourist Problem
- generate all permutations of string / array

```Cpp
namespace combinatorics {
    ll MOD; vector<ll> fac,inv,finv;
    ll nCr(ll x,ll y){
        if(x < 0 || y > x || y < 0)return(0);
        return(fac[x] * finv[y] % MOD * finv[x-y] % MOD);
    }
    ll nPr(ll x,ll y){
        if(x < 0 || y>x || y < 0)return 0;
        return fac[x] * finv[x-y] % MOD;
    }
    ll power(ll b,ll n){
        b%=MOD;
        ll s=1;
        if(b==0) return 0;
        while(n){
            if(n%2 == 1) s = s*b%MOD;
            b = b*b%MOD;
            n /= 2;
        }
        return s;
    }
    void init(int n,ll mod){
        fac.resize(n+1); inv.resize(n+1); finv.resize(n+1); 
        MOD = mod;
        fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
        for(ll i=1; i<=n; ++i) fac[i] = fac[i-1] * i % MOD;
        for(ll i=2; i<=n; ++i) inv[i] = MOD - MOD / i * inv[MOD%i] % MOD;
        for(ll i=2; i<=n; ++i) finv[i] = finv[i-1] * inv[i] % MOD;
    }
    
    ll mul(ll a,ll b)
        return ((a%MOD) * (b%MOD)) % MOD;
    ll add(ll a,ll b)
        return ((a%MOD) + (b%MOD)) % MOD;
    ll sub(ll a,ll b)
        return (((a-b) % MOD ) + MOD) % MOD;
    ll divide(ll a,ll b)
       return mul(a, power(b, MOD-2));
    ll Inv(int x)
        return power(x, MOD-2);
    ll catalan(int n)
        return (nCr(2*n, n) * Inv(n+1)) % MOD;
    ll StarsAndPars(ll n, ll k)
        return nCr(n+k-1, k-1);
    ll ManhattanTourist(ll x,ll y)
		return nCr(x+y, x) || nCr(x+y, y);
};
using namespace combinatorics;
```

### Properties

![[Pasted image 20260614040254.png|249]]
![[Pasted image 20260614040137.png|355]]
![[Pasted image 20260614040148.png|491]]

### Preprocess: Generate all nCr | Pascal's Triangle
Can be used to solve **Binomial Coefficient**
![[Pasted image 20260618182736.png|609]]

```cpp
ll MOD;
const int N = 20;  
vector<vector<ll>> C(N, vector<ll>(N, 0));  
void preProcess_nCr() {  
    C[0][0] = 1; // 0!/0!*(0-0)! = 1  
    for (int n = 1; n < N; n++) {  
        C[n][0] = C[n][n] = 1; // i!/0!*(i-0)! = 1, i/i!*(i-i)! = 1  
        for (int r = 1; r < n; r++) {  
            C[n][r] = (C[n - 1][r] + C[n - 1][r - 1]) % MOD;  
        }  
    }
    logArr2D(C)  
}
ll nCr(ll x,ll y){
	return C[x][y];
}
ll ManhattanTourist(ll x,ll y){
	return C[x+y][x] || C[x+y][y];
}
```

### Generate all permutations of string / array

```cpp
string s;
sort(allArr(s));  
set<string> words;  
do {  
    words.insert(s);  
} while (next_permutation(s.begin(), s.end()));
```
OR
```Cpp
void generatePermutations(string& str, int left, int right) {
	if (left == right) {
		cout << str << "\n";
		return;
	}
	for (int i = left; i <= right; i++) {
		swap(str[left], str[i]);
		generatePermutations(str, left + 1, right);
		swap(str[left], str[i]);
	}
}

string str = "ABC";
int n = str.length();
generatePermutations(str, 0, n - 1);
```

> [!Danger] Complexity of generatePermutations()
> Time complexity = $O(n * n!)$
