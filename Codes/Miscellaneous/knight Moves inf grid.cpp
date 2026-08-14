int knight_move(int x, int y) {
  int cnt = max({(x + 1) / 2, (y + 1) / 2, (x + y + 2) / 3});
  while((cnt % 2) != (x + y) % 2) cnt++;
  if(x == 1 && !y) return 3;
  if(y == 1 && !x) return 3;
  if(x == y && x == 2) return 4;
  return cnt;
}