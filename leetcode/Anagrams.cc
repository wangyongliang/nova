class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<string, string> > a;
        for (int i = 0; i < strs.size(); i ++) {
          a.push_back(make_pair(strs[i], strs[i]));
        }
        for (int i = 0; i < a.size(); i ++) {
          sort(a[i].first.begin(), a[i].first.end());
        }
        sort(a.begin(), a.end());
        vector<string> result;
        for (int i = 0; i < a.size(); i ++) {
          bool flag = false;
          if (!flag && i + 1 < a.size() && a[i].first == a[i + 1].first) {
            result.push_back(a[i].second);
            flag = true;
          }
          if (!flag && i > 0 && a[i].first == a[i - 1].first) {
            result.push_back(a[i].second);
            flag = true;
          }
        }
        sort(result.begin(), result.end());
        return result;
    }
};