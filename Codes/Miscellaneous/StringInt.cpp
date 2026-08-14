string longDivision(string number, int divisor) {  
   if (divisor == 0) return "Undefined";
   if (number == "0") return "0";
  
   string quot;
   int curr_rem = 0;
  
   for (int i=0; i<number.length(); i++) {
      curr_rem = curr_rem * 10 + (number[i] - '0');
      quot += to_string(curr_rem / divisor);
      curr_rem = curr_rem % divisor;
   }
  
   int pos = 0;
   while (pos<quot.length() - 1 && quot[pos]=='0') pos++;
   return quot.substr(pos);
}

string multiplyByNumber(string num, int mult) {  
   if (mult == 0 || num == "0") return "0";  
  
   string res;  
   int carry = 0;  
   for (int i=num.length()-1; i>=0; i--) {  
      int prdct = (num[i] - '0') * mult + carry;  
      res.push_back((prdct%10) + '0');  
      carry = prdct / 10;  
   }  
   while(carry>0) {  
      res.push_back((carry%10) + '0');  
      carry /= 10;  
   }  
   reverse(res.begin(), res.end());  
   return res;  
}

string multiplyStrings(string num1, string num2) {  
   if (num1 == "0" || num2 == "0") return "0";  
  
   int n = num1.length();  
   int m = num2.length();  
   vector<int> res(n + m, 0);  
   for (int i=n-1; i>=0; i--) {  
      for (int j = m - 1; j >= 0; j--) {  
         int mul = (num1[i] - '0') * (num2[j] - '0');  
         int sum = mul + res[i + j + 1];  
         res[i + j + 1] = sum % 10;  
         res[i + j] += sum / 10;  
      }  
   }  
  
   string prdct = "";  
   for (int digit:res)  
      if (!(prdct.empty() && digit == 0)) prdct.push_back(digit+'0');  
  
   return prdct.empty() ? "0" : prdct;  
}

string addStringAndInt(string num, int val) {  
   if (val == 0) return num.empty() ? "0" : num;  
   string res;  
   int carry = val;  
   for (int i=num.length()-1; i>=0; i--) {  
      int sum = (num[i] - '0') + carry;  
      res.push_back((sum % 10) + '0');  
      carry = sum / 10;  
   }  
   while (carry > 0) {  
      res.push_back((carry % 10) + '0');  
      carry /= 10;  
   }  
   reverse(allv(res));  
   return res;  
}

string addStrings(string num1, string num2) {  
   string res;  
   int i = num1.length() - 1;  
   int j = num2.length() - 1;  
   int carry = 0;  
   while (i >= 0 || j >= 0 || carry > 0) {  
      int d1 = (i >= 0) ? (num1[i] - '0') : 0;  
      int d2 = (j >= 0) ? (num2[j] - '0') : 0;  
      int sum = d1 + d2 + carry;  
      res.push_back((sum % 10) + '0');  
      carry = sum / 10;  
      i--; j--;  
   }  
   reverse(allv(res));  
   return res;  
}

bool isSmaller(string num1, string num2) {  
   int n1 = num1.length(), n2 = num2.length();  
   if (n1 != n2) return n1 < n2;  
   return num1 < num2;  
}  
  
string subtractStrings(string num1, string num2) {  
   if (isSmaller(num1, num2))  
      return "-" + subtractStrings(num2, num1);  
  
   string res;  
   int i = num1.length() - 1, j = num2.length() - 1;  
   int borrow = 0;  
  
   while (i >= 0) {  
      int d1 = (num1[i] - '0') - borrow;  
      int d2 = (j >= 0) ? (num2[j] - '0') : 0;  
      if (d1 < d2) {  
         d1 += 10;  
         borrow = 1;  
      } else borrow = 0;  
  
      res.push_back((d1 - d2) + '0');  
      i--; j--;  
   }  
  
   reverse(allv(res));  
   int strt = 0;  
   while(strt<res.length()-1 && res[strt]=='0') strt++;  
  
   return res.substr(strt);  
}