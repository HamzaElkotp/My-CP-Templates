int mx = 1e7+10;  
vector<bool> is_primes(mx, true);  
void Sieve(){  
   is_primes[0]=is_primes[1]=false;  
   for(int i=2; i*i<mx; i++)  
      if(is_primes[i]) for(int o=i*i; o<mx; o+=i) is_primes[o]=false;  
}