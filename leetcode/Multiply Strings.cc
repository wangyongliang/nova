class Solution {
public:
    string multiply(string num1, string num2) {
      if (num2 == "0" || num1 == "0")
        return "0";
      vector<int> a;
      a.resize(num1.size() + num2.size(), 0);
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      for (int i = 0; i < num1.size(); i ++) {
        for (int j = 0; j < num2.size(); j ++) {
          a[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
      }
      string result = "";
      int rest = 0;
      char digit;
      for (int i = 0; i < a.size(); i ++) {
        rest = rest + a[i];
        digit = rest % 10 + '0';
        rest /= 10;
        result += digit;
      }
      while (rest > 0) {
        digit = rest % 10 + '0';
        rest /= 10;
        result += digit;
      }
      int pos = result.find_last_not_of('0');
      result = result.substr(0, pos + 1);
      reverse(result.begin(), result.end());
      return result;
    }
};