> NOTE: 1-Indexed

```cpp
struct FenwickTree{  
   int n;  
   vector<int> bit;  
   FenwickTree(int n){  
     this->n = n;  
     bit.resize(n+1, 0);  
   }  
   int getParent(int indx) { return indx - (indx & -indx);}  
   int getNext(int indx){ return indx + (indx & -indx);}  
   void update(int indx, int delta){  
      while(indx<=n){  
         bit[indx] += delta;  
         indx= getNext(indx);  
      }  
   }
   void construct(vector<int> &vct){ // O(N logN)
      for(int i=0; i<vct.size(); i++)  
         update(i+1, vct[i]);  
   }  
   void constructFast(vector<int> &vct){ // O(N) 
      for(int i=0; i<vct.size(); i++)  
         bit[i+1] = vct[i];  
      for(int i=1; i<=n; i++){  
         int nextIndx = getNext(i);  
         if(nextIndx <= n)  
            bit[nextIndx] += bit[i];  
      }  
   }  
   int query(int indx){ // O(logN)  
      int sum=0;  
      while(indx > 0){  
         sum += bit[indx];  
         indx = getParent(indx);  
      }  
      return sum;  
   }  
   int rangeQuery(int L, int R){  
      if(L>R) return 0;  
      return query(R) - query(L-1);  
   }  
};
```

>- Based on problem needs, edit may be required for `update()` 
>- `construct()`, `constructFast()` by default do prefix sum on given array. changing update() will change their job.