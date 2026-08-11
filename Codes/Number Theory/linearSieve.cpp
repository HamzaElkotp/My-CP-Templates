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