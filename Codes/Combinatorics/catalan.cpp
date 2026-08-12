const int MOD;
const int MAX;
int cat[MAX];
void init() {
    cat[0] = cat[1] = 1;
    for (int i=2; i<=n; i++) {
        cat[i] = 0;
        for (int j=0; j < i; j++) {
            cat[i]+=(cat[j]*cat[i-j-1])%MOD;
            if(cat[i]>=MOD) cat[i] -= MOD;
        }
    }
}