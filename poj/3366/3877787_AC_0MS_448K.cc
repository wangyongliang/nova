#include <iostream>
#include <map>

using namespace std;

int n,m;
string pl[21];
map<string,int> hash;

int main()
{
    string s1,s2;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++)
    {
        cin >> s1 >> pl[i];
        hash[s1] = i+1;
    }
    while (m--)
    {
        cin >> s1;
        if (hash[s1])
        {
            cout << pl[hash[s1]-1] << endl;
        }
        else
        {
            char c = s1[s1.size()-1];
            if (c == 'y' && (s1.size()>1 && (s1[s1.size()-2] != 'a' && s1[s1.size()-2] != 'o' && s1[s1.size()-2] != 'e' && s1[s1.size()-2] != 'u' && s1[s1.size()-2] != 'i')))
            {
                s1[s1.size()-1] = 'i';
                s1 += "es";
            }
            else if (c == 'o'|| c == 's' || c == 'x' || (c == 'h' && s1.size() > 1 && (s1[s1.size()-2] == 'c' || s1[s1.size()-2] == 's')))
            {
                 s1 += "es";
            }
            else
                s1 += 's';
            cout << s1 << endl;
        }
    }
    //system("PAUSE");
    return 0;
}
