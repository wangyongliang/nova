class Solution {
public:
    string simplifyPath(string path) {
      stack<string> stack_;
      string dir = "";
      for (int i = 1; i < path.size(); i ++) {
        if (path[i] == '/') {
          if (dir == ".");
          else if (dir == "..") {
            if (stack_.size() > 0) stack_.pop();
          }
          else {
            if (!dir.empty()) stack_.push(dir);
          }
          dir = "";
        } else
          dir += path[i];
      }

      if (!dir.empty()) {
        if (dir == "..") {
          if (stack_.size() > 0) stack_.pop();}
        else if (dir == ".");
        else {
          if (!dir.empty()) stack_.push(dir);
        }
      }

      string result = "";
      while (stack_.size()) {
        result = "/" + stack_.top() + result;
        stack_.pop();
      }
      if (result == "")
        result = "/";
      return result;
    }
};