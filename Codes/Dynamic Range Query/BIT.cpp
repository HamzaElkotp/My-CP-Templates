template <typename T>
struct FenwickTree{
   int n;
   vector<T> bit;
   FenwickTree(int n){
      this->n = n+1;
      bit.resize(n+1);
   }
   int getParent(int indx) { return indx - (indx & -indx);}
   int getNext(int indx){ return indx + (indx & -indx);}
   void update(int indx, int delta){
      while(indx<n){
         bit[indx] += delta;
         indx = getNext(indx);
      }
   }
   void updateRange(int L, int R, int delta){
      update(L, delta);
      update(R+1, -delta);
   }
   int query(int indx){
      int sum=0;
      while(indx > 0){
         sum += bit[indx];
         indx = getParent(indx);
      }
      return sum;
   }
   int queryRange(int L, int R){
      if(L>R) return 0;
      return query(R) - query(L-1);
   }
};