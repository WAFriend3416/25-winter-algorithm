#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    while (num--)
    {
        string s;
        cin >> s;

        list<char> l;
        auto iter = l.begin();

        for(auto ch : s){
            if (ch == '<'){
                if(iter != l.begin()) iter--;
            }
            else if (ch == '>'){
                if(iter != l.end()) iter++;
            }
            else if (ch == '-'){
                if(iter != l.begin()){
                    auto temp = iter;
                    temp--;
                    l.erase(temp);
                }
            }
            else{
                l.insert(iter, ch);
            }
        }

        for(auto c : l) cout << c;
        cout << "\n";
    }

    return 0;
}
