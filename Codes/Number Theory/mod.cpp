int modInverse(int x) { return fastPower(x, MOD-2); }
int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub(int a, int b) { return (((a - b) % MOD) + MOD) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int div(int a, int b) {
   if (b == 0 || __gcd(b, MOD) != 1) return -1;
   a %= MOD;
   int inv = modInverse(b);  
   return (a * inv) % MOD;
}