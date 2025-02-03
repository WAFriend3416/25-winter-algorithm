#include <iostream>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin >> N >> K;

    list<int> l;
    for(int i=1; i<=N; i++){
        l.push_back(i);
    }
    cout << "<";
    //list<int>::iterator iter = l.begin();
    auto iter = l.begin();
    while(!l.empty()){
        for(int j=0; j<K-1; j++){
            if(*iter == l.back()){
                iter = l.begin();
            }
            else{
                iter++;
            }
        }
        if(l.size() == 1){
            cout << *iter;
        }
        else{
            cout << *iter << ", ";
        }
        iter = l.erase(iter);
        if(iter == l.end()) iter = l.begin();
    }
    cout << ">" << endl;
    return 0;
}