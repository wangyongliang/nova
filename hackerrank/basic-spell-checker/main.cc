// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github:https://github.com/wangyongliang

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cctype>
#include <set>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::map;
using std::string;
using std::set;

class Segmenter {
public:
    Segmenter() {
        delimter_ = "!\"#$%&'()*+,-./0123456789:;<=>?@[]^_|~";
    }
    ~Segmenter() {
    }
    void Segment(const string &text, vector<string> &terms) {
        string token;
        token = "";
        for (size_t i = 0; i < text.size(); ++i) {
            if (delimter_.find(text[i]) != string::npos) {
                ToLower(token);
                terms.push_back(token);
                token = "";
            } else {
                token += text[i];
            }
        }
        if (token.size()) {
            ToLower(token);
            terms.push_back(token);
        }
    }
    
    void ToLower(string& text) {
        for (size_t i = 0; i < text.size(); ++i) {
            text[i] = static_cast<char>(tolower(text[i]));
        }
    }
private:
    string delimter_;
};

void generate_dict() {
    freopen("corpus.txt","r", stdin);
    freopen("dict.txt", "w", stdout);
    string text;
    map<string, int> dict;

    Segmenter segmenter;
    vector<string> words;
    while (cin >> text) {
        words.clear();
        segmenter.Segment(text, words);
        // cout << text << endl;
        // cout << words.size() << endl;
        for (std::vector<string>::iterator i = words.begin(); 
            i != words.end(); ++i) {
            dict[*i] ++;
        }
    }

    for (map<string, int>::iterator it = dict.begin(); it != dict.end();
        it ++) {
        cout << it->first << "|" << it->second << endl;
    }    
}

void generate_punch() {
    freopen("corpus.txt","r", stdin);
    freopen("punch.txt", "w", stdout);
    string text;
    set<char> punch;
    while (cin >> text) {
        for (size_t i = 0; i < text.size(); ++i) {
            if (!isalpha(text[i])) punch.insert(text[i]);
        }
    }
    
    for (set<char>::iterator it = punch.begin(); it != punch.end(); \
        it ++) {
        cout << *it;
    }
    cout << endl;
}
int main(int argc, char const *argv[]) {
    // generate_punch();
    generate_dict();
    return 0;
}