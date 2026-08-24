/// n size of the string , k is the number of different type
int Balanced_parentheses_count(int n, int k, int mod) {
  if (n & 1)return 0;
  n /= 2;
  long long a = 1, b = 1, c = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    a = mult(a, i);
    if (i == n)b = a;
    if (i == n + 1)c = a;
  }
  int res = mult(a, mult(fastPower(b, mod - 2), fastPower(c, mod - 2)));
  return mult(res, fastPower(k, n));
}