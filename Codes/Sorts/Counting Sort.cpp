const int MAX = 100;
void solve() {
  int n; cin >> n;
  vector<int> cnt(MAX + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for (int i = 0; i <= MAX; i++) {
    while (cnt[i] > 0) {
      cout << i << ' ';
      cnt[i]--;
    }
  }
  cout << '\n';
  return 0;
}
