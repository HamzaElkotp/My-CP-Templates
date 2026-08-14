int gcd(int a,int b) {
    if(a>b) swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}
int lcm(int a,int b){
   return a/gcd(a,b)*b;
}