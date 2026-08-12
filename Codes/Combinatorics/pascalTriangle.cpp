int MOD;
const int MAX = 20;
vector<vector<ll>> C(MAX, vector<ll>(MAX, 0));  
void preProcess_nCr() {
   C[0][0] = 1;
   for (int n=1; n<MAX; n++) {  
      C[n][0] = C[n][n] = 1; 
      for (int r=1; r<n; r++) {  
         C[n][r]=(C[n-1][r]+C[n-1][r-1])%MOD;  
      }
   }
   logArr2D(C)  
}
int nCr(int x,int y){
	return C[x][y];
}
int ManhattanTourist(int x,int y){
	return C[x+y][x] || C[x+y][y];
}