> NOTE: 1-Indexed

```cpp
struct FenwickTree{  
   int n;  
   vector<int> bit;  
   FenwickTree(int n){  
     this->n = n;  
     bit.resize(n+1, 0); // NOTE 0
   }  
   int getParent(int indx) { return indx - (indx & -indx);}  
   int getNext(int indx){ return indx + (indx & -indx);}  
   void update(int indx, int delta){  
      while(indx<=n){  
         bit[indx] += delta; // NOTE 1
         indx = getNext(indx);  
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
            bit[nextIndx] += bit[i]; // NOTE 2
      }  
   }  
   int query(int indx){ // O(logN)  
      int sum=0; // NOTE 3
      while(indx > 0){  
         sum += bit[indx]; // NOTE 4
         indx = getParent(indx);  
      }  
      return sum;  
   }  
   int queryRange(int L, int R){  
      if(L>R) return 0;  
      return query(R) - query(L-1); // NOTE 5
   }  
   void updateRange(int L, int R, int delta){ // O(logN)  
      update(L, delta);
      update(R+1, -delta); // NOTE 6
   }
};
```

> Works only with XOR, Summation, Multiplication

| NOTE   | XOR                           | Multiplication                                    |
| ------ | ----------------------------- | ------------------------------------------------- |
| NOTE 0 |                               | bit.resize(n+1, 1);                               |
| NOTE 1 | bit[indx] ^= delta;           | bit[indx] = (bit[indx] * val) % MOD;              |
| NOTE 2 | bit[nextIndx] ^= bit[i];      | bit[nextIndx] = (bit[nextIndx] * bit[i]) % MOD;   |
| NOTE 3 | int sum=0;                    | int sum=1;                                        |
| NOTE 4 | sum ^= bit[indx];             | sum = (sum * bit[indx]) % MOD;                    |
| NOTE 5 | return query(R) ^ query(L-1); | return (query(R) * modInverse(query(L-1))) % MOD; |
| NOTE 6 | update(R+1, delta);           | update(R+1, modInverse(delta));                   |

