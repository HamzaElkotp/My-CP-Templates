```Cpp
bool Knowbit(ll n,int i){
    return (n>>i)&1;
}

ll Setbit(ll n,int i){
    return n|(1<<i);
}

ll Resetbit(ll n,int i){
    return n&(~(1<<i)); // n&(-1^(1<<i))
}

ll flip(ll n,int i){
    return n^(1<<i);
}

bool isDivisibleByPowerOf2(ll n, int k){ 
	ll powerOf2 = 1 << k;
	return (n & (powerOf2 - 1)) == 0; 
}

bool isPowerOfTwo(int n){ // or use builtin has_single_bit
    if(n==0)return 0;
    return !(n&(n-1));
}
```

```cpp
ll twosComplement(ll num){  
    return (~num) + 1;  
}

ll clearTrailingOnes(ll num){
	return n&(n+1); // 00110111 -> 00110000
}

ll setsLastZero(ll num){ // sets the last cleared bit
	return n|(n+1); // 001101001 -> 001101011
}

ll extractsLastOne(ll num){ // extracts the last set bit
	return n&(-n); // 00110100 -> 00000100
}
```

---
#### Complete Search
```Cpp
vector<vector<int>> generateSubsets(vector<int>& arr) {  
    int n = arr.size();  
    vector<vector<int>> subsets;  
  
    for(int mask = 0; mask < (1 << n); mask++) {  
        vector<int> subset;
        for(int i = 0; i < n; i++) {  
            if(knowBit(mask, i)) {  
                subset.push_back(arr[i]);  
            }  
        }  
        subsets.push_back(subset);  
    }  
  
    sort(subsets.begin(), subsets.end());  
    return subsets;  
}
```
#### Built-in functions
```cpp
ll x = 5328; // 00000000000000000001010011010000 
__builtin_clzll(x); // 19 => number of zeros at the beginning of the number 
__builtin_ctzll(x); // 4 => number of zeros at the end of the number 
__builtin_popcountll(x); // 5 => number of ones in the number 
__builtin_parityll(x); // 1 => parity (even or odd) of the number of ones
__builtin_ffsll(x) // 4 => finds the index of the first (most right) set bit
```

**for c++20 only**
```cpp
bit_width(n) - 1; // highest bit position (x) such that 2^x <= n
has_single_bit((unsigned ll) n); // checks if the number is a power of two
bit_ceil((unsigned ll) n); // round up to the next power of two
bit_floor((unsigned ll) n); // round down to the next power of two
rotl((unsigned ll) n, k); // shift to left by k bits
rotr((unsigned ll) n, k); // shift to right by k bits

countl_zero/countr_zero/countl_one/countr_one// count the leading/trailing zeros/ones
```

#### Count ones
```cpp
ll countOnes(ll n){  
    ll count = 0;  
    while (n) {  
        count += (n & (ll)1);  
        n >>= 1;  
    }
    return count;  
}
```
#### Count set bits of n
```cpp
int countSetBits(ll n) {  
    int count = 0;  
    while (n){  
        n = n & (n - 1);  
        count++;  
    }  
    return count;  
}
```
#### Count all set bits up-to n
```cpp
ll countSetBits(ll n){ 
	ll count = 0; 
	while (n > 0){ 
		ll x = std::bit_width(n) - 1;
		count += x << (x - 1);
		n -= 1 << x;
		count += n + 1;
	}
	return count;
}
```