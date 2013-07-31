class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      if (start == end)
        return 0;
      vector<int> a(dict.size(), INT_MAX);

      int **road = new int*[dict.size()];
      for (int i = 0; i < dict.size(); i ++) {
        road[i] = new int[dict.size()];
        for (int j = 0; j < dict.size(); j ++) {
          road[i][j] = INT_MAX;
        }
      }

      vector<string> words;
      for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it ++) {
        words.push_back(*it);
      }

      int start_idx;
      int end_idx;
      for (int i = 0; i < words.size(); i ++) {
        if (words[i] == start)
          start_idx = i;
        if (words[i] == end)
          end_idx = i;
        road[i][i] = 0;
        for (int j = i + 1; j < words.size(); j ++) {
          int diff = 0;
          for (int k = 0; k < words[i].size(); k ++) {
            diff += (words[i][k] != words[j][k]);
          }
          road[i][j] = road[j][i] = (diff == 1);
        }
      }

      for (int k = 0; k < words.size(); k ++) {
        for (int i = 0; i < words.size(); i ++) {
          if (road[i][k] == INT_MAX) continue;
          for (int j = 0; j < words.size(); j ++) {
            if (road[k][j] == INT_MAX) continue;
            road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
          }
        }
      }

      int result = road[start_idx][end_idx];
      for (int i = 0; i < words.size(); i ++)
        delete [] road[i];
      delete [] road;
      result = result == INT_MAX? 0: result;
      return result;
    }
};