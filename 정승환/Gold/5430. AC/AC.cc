#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int T;
    cin >> T;
    while(T--){
        string cmd;
        cin >> cmd;
        int N;
        cin >> N;
        string arr;
        cin >> arr;
        arr = arr.substr(1,arr.length()-2);
    
        istringstream ss(arr);
        string stringBuffer;
        deque<string> x;
        x.clear();
        while(getline(ss,stringBuffer,',')){
            x.push_back(stringBuffer);
        }
        
        int reversed = 0; // 뒤집혔는지 확인
        int errorFlag = 0;
        
        for(char c : cmd){
            if(c == 'R'){
                reversed = !reversed;
            }
            else if(c =='D'){
                if(x.empty()){
                    cout << "error\n";
                    errorFlag = 1;
                    break;
                }
                if(!reversed){ // 안 뒤집힘
                    x.pop_front();
                }
                else{ // 뒤집힘
                    x.pop_back();
                }
            }
        }
        if(!errorFlag){
            if(!reversed){ // 안 뒤집힘
                cout << "[";
                for(int i = 0; i < (int)x.size(); i++){
                    cout << x[i];
                    if(i < (int)x.size()-1) cout << ",";
                }
                cout << "]\n";
            }
            else{ // 뒤집힘
                cout << "[";
                for(int i = (int)x.size()-1; i>=0;  i--){
                    cout << x[i];
                    if(i > 0 ) cout << ",";
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}