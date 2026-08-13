```cpp
int mx = 1e7+10;  
vector<bool> is_primes(mx, true);  
void Sieve(){  
   is_primes[0]=is_primes[1]=false;  
   for(int i=2; i*i<mx; i++)  
      if(is_primes[i]) for(int o=i*i; o<mx; o+=i) is_primes[o]=false;  
}
```

```cpp
int mx = 1e7+10;  
vector<bool> is_primes(mx, true);  
vector<int> primes;  
void linearSieve(){  
   is_primes[0]=is_primes[1]=false;  
   for(int i=2; i<=mx; i++){  
      if(is_primes[i]) primes.push_back(i);  
      for(auto prime : primes){  
         if(i*prime>mx) break;  
         is_primes[i*prime] = false;  
         if(i%prime==0) break;  
      }  
   }  
}
```

```cpp
vector<int> primeFactorization(int n) {  
   vector<int> v;  
   while(n%2==0){  
      n/=2;  
      v.push_back(2);  
   }  
   for (int i=3; i*i<=n; i+=2) {  
      while (n%i==0) {  
         n/=i;  
         v.push_back(i);  
      }  
   }  
   if(n>1) v.push_back(n);  
   return v;  
}
```

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