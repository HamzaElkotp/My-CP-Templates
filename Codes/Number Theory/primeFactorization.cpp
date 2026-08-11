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