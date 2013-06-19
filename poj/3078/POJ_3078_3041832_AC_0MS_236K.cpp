#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
void process(void)
{
    int data_num, data_idx;
    cin >> data_num;
    for(data_idx = 0; data_idx < data_num; data_idx++) {
        int op_num, op_idx, str_num, str_idx;
        vector<string> data;
        map<int, string> inserts;
        map<int, bool> deletes;
        cin >> str_num >> op_num;
        for(str_idx = 0; str_idx < str_num; str_idx++) {
            string s;            
            cin >> s;
            data.push_back(s);
        }
        for(op_idx = 0; op_idx < op_num; op_idx++) {
            int src, dst;
            cin >> src >> dst;
            src--;
            dst--;        
            deletes[src] = true;
            inserts[dst] = data[src];
        }        
        int src, dst;
        for(src = 0, dst = 0; dst < str_num; dst++) {                            
            if(inserts[dst] != "") {
                cout << inserts[dst] << " ";
            }
            else {                  
                while(deletes[src]) {
                    src++;
                }                
                cout << data[src] << " ";
                src++;
            }
        }
        cout << endl;
    }
}
int main(void)
{
    cin.exceptions(ios::eofbit | ios::failbit);
    try {
        process();
    }
    catch(char const *e) {
        cerr << "Exception: " << e << endl;
    }
    catch(ios::failure const &e) {
        cerr << "Unexpected EOF or data type mismatch on input" << endl;
    }

    return 0;
}
