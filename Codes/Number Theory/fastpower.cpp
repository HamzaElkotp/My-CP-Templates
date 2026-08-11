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