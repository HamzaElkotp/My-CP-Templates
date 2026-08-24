bool Knowbit(int n,int i){
   return (n>>i)&1;
}
int Setbit(int n,int i){
   return n|(1<<i);
}
int Resetbit(int n,int i){
   return n&(~(1<<i)); // n&(-1^(1<<i))
}
int flip(int n,int i){
   return n^(1<<i);
}
bool isDivisibleByPowerOf2(int n, int k){ 
	int powerOf2 = 1 << k;
	return (n & (powerOf2 - 1)) == 0; 
}
bool isPowerOfTwo(int n){
   // or use builtin has_single_bit
   if(n==0)return 0;
   return !(n&(n-1));
}
int twosComplement(int n){  
   return (~n) + 1;  
}
int clearTrailingOnes(int n){
	return n&(n+1); 
   // 00110111 -> 00110000
}
int setsLastZero(int n){
   // sets the last cleared bit
	return n|(n+1);
   // 001101001 -> 001101011
}
int extractsLastOne(int n){
   // extracts the last set bit
	return n&(-n); // 00110100 -> 00000100
}
int countOnes(int n){  
   int count = 0;  
   while (n) {  
      count += (n & 1LL);  
      n >>= 1;  
   }
   return count;  
}
int countSetBits(int n) {  
   int count = 0;  
   while (n){  
      n = n & (n - 1LL);  
      count++;  
   }  
   return count;  
}
int countSetBits(int n){ 
	int count = 0; 
	while (n > 0){ 
		int x = bit_width(n) - 1LL;
		count += x << (x - 1LL);
		n -= 1LL << x;
		count += n + 1LL;
	}
	return count;
}
int numberWithOnes(int n){
// returns 1st num smaller than the n number with 1s
// n=10101, result: 01111
   return 1<<bit_width(n)-1;
}
string binaryRepresnetation(int n){
   return format("{:032b}", n);
}