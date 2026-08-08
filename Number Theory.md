```cpp
vector<int> getDivisors(int n) {  
   vector<int>v;
   for(int i=1;i*i<=n;i++) {  
      if(n%i==0) {  
         v.push_back(i);  
         if (n/i != i) v.push_back(n/i);  
      }
   }
   return v;
}
```

```cpp
int fastPower(int base, int exp) {  
   int res = 1;  
   base = base % MOD;  
   while (exp) {  
      if (exp & 1) res = (res * base) % MOD;  
      base = (base * base) % MOD;  
      exp >>= 1;
   }  
   return res;  
}
```

```cpp
int modInverse(int x) { return fastPower(x, MOD-2); }
```

```cpp
int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub(int a, int b) { return (((a - b) % MOD) + MOD) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int div(int a, int b) {
   if (b == 0 || __gcd(b, MOD) != 1) return -1;
   a %= MOD;
   int inv = modInverse(b);  
   return (a * inv) % MOD;
}
```

```cpp
int mx = 1e6+10;  
vector<bool> prims(mx, true);  
void Sieve(){  
   prims[0]=prims[1]=false;  
   for(int i=2; i*i<mx; i++)
      if(prims[i]) for(int o=i*i; o<mx; o+=i) prims[o]=false;
}
```


