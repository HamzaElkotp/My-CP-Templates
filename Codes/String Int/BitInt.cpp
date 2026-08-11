struct BigInt {
    string s;
    bool neg;

    void trim() {
       int pos = 0;
       while (pos < (int)s.length() - 1 && s[pos] == '0') pos++;
       s = s.substr(pos);
       if (s == "0") neg = false;
    }

    static bool abs_less(const string& a, const string& b) {
       if (a.length() != b.length()) return a.length() < b.length();
       return a < b;
    }

    static string add_abs(const string& a, const string& b) {
       string res = "";
       int i = a.length() - 1, j = b.length() - 1, carry = 0;
       while (i >= 0 || j >= 0 || carry > 0) {
          int d1 = (i >= 0) ? (a[i] - '0') : 0;
          int d2 = (j >= 0) ? (b[j] - '0') : 0;
          int sum = d1 + d2 + carry;
          res.push_back((sum % 10) + '0');
          carry = sum / 10;
          i--; j--;
       }
       reverse(res.begin(), res.end());
       return res;
    }

    static string sub_abs(const string& a, const string& b) { // Assumes a >= b
       string res = "";
       int i = a.length() - 1, j = b.length() - 1, borrow = 0;
       while (i >= 0) {
          int d1 = (a[i] - '0') - borrow;
          int d2 = (j >= 0) ? (b[j] - '0') : 0;
          if (d1 < d2) { d1 += 10; borrow = 1; }
          else { borrow = 0; }
          res.push_back((d1 - d2) + '0');
          i--; j--;
       }
       reverse(res.begin(), res.end());
       int pos = 0;
       while (pos < (int)res.length() - 1 && res[pos] == '0') pos++;
       return res.substr(pos);
    }

    static string mul_abs(const string& a, const string& b) {
       if (a == "0" || b == "0") return "0";
       int n = a.length(), m = b.length();
       vector<int> res(n + m, 0);
       for (int i = n - 1; i >= 0; i--) {
          for (int j = m - 1; j >= 0; j--) {
             int mul = (a[i] - '0') * (b[j] - '0');
             int sum = mul + res[i + j + 1];
             res[i + j + 1] = sum % 10;
             res[i + j] += sum / 10;
          }
       }
       string p = "";
       for (int digit : res) {
          if (!(p.empty() && digit == 0)) p.push_back(digit + '0');
       }
       return p.empty() ? "0" : p;
    }

    static pair<string, string> div_abs(const string& dividend, const string& divisor) {
       if (abs_less(dividend, divisor)) return {"0", dividend};
       string q = "", rem = "";
       for (char ch : dividend) {
          rem.push_back(ch);
          int pos = 0;
          while (pos < (int)rem.length() - 1 && rem[pos] == '0') pos++;
          rem = rem.substr(pos);

          int cnt = 0;
          while (!abs_less(rem, divisor)) {
             rem = sub_abs(rem, divisor);
             cnt++;
          }
          q.push_back(cnt + '0');
       }
       int pos = 0;
       while (pos < (int)q.length() - 1 && q[pos] == '0') pos++;
       return {q.substr(pos), rem};
    }

    // --- Constructors ---
    BigInt() : s("0"), neg(false) {}

    BigInt(int v) {
       if (v < 0) { neg = true; v = -v; }
       else { neg = false; }
       s = to_string(v);
    }

    BigInt(string str) {
       if (str.empty()) { s = "0"; neg = false; return; }
       if (str[0] == '-') { neg = true; s = str.substr(1); }
       else { neg = false; s = str; }
       trim();
    }

    // --- Comparisons ---
    bool operator==(const BigInt& o) const { return neg == o.neg && s == o.s; }
    bool operator!=(const BigInt& o) const { return !(*this == o); }

    bool operator<(const BigInt& o) const {
       if (neg != o.neg) return neg;
       if (s != o.s) {
          bool abs_l = abs_less(s, o.s);
          return neg ? !abs_l : abs_l;
       }
       return false;
    }
    bool operator>(const BigInt& o) const { return o < *this; }
    bool operator<=(const BigInt& o) const { return !(*this > o); }
    bool operator>=(const BigInt& o) const { return !(*this < o); }

    // --- Arithmetic Operators ---
    BigInt operator-() const {
       BigInt res = *this;
       if (res.s != "0") res.neg = !res.neg;
       return res;
    }

    BigInt operator+(const BigInt& o) const {
       if (neg == o.neg) {
          BigInt res;
          res.s = add_abs(s, o.s);
          res.neg = neg;
          res.trim();
          return res;
       }
       if (abs_less(s, o.s)) {
          BigInt res;
          res.s = sub_abs(o.s, s);
          res.neg = o.neg;
          res.trim();
          return res;
       } else {
          BigInt res;
          res.s = sub_abs(s, o.s);
          res.neg = neg;
          res.trim();
          return res;
       }
    }

    BigInt operator-(const BigInt& o) const { return *this + (-o); }

    BigInt operator*(const BigInt& o) const {
       BigInt res;
       res.s = mul_abs(s, o.s);
       res.neg = (res.s != "0") && (neg ^ o.neg);
       res.trim();
       return res;
    }

    BigInt operator/(const BigInt& o) const {
       BigInt res;
       res.s = div_abs(s, o.s).first;
       res.neg = (res.s != "0") && (neg ^ o.neg);
       res.trim();
       return res;
    }

    BigInt operator%(const BigInt& o) const {
       BigInt res;
       res.s = div_abs(s, o.s).second;
       res.neg = (res.s != "0") && neg;
       res.trim();
       return res;
    }

    BigInt& operator+=(const BigInt& o) { return *this = *this + o; }
    BigInt& operator-=(const BigInt& o) { return *this = *this - o; }
    BigInt& operator*=(const BigInt& o) { return *this = *this * o; }
    BigInt& operator/=(const BigInt& o) { return *this = *this / o; }
    BigInt& operator%=(const BigInt& o) { return *this = *this % o; }

    friend ostream& operator<<(ostream& os, const BigInt& b) {
       if (b.neg && b.s != "0") os << '-';
       os << b.s;
       return os;
    }

    friend istream& operator>>(istream& is, BigInt& b) {
       string str;
       if (is >> str) b = BigInt(str);
       return is;
    }
};