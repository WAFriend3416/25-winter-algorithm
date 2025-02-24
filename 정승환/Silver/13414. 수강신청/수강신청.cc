#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    unordered_map<string,int> m;
    for(int i=0; i<M; i++){
        string student_num;
        cin >> student_num;
        m[student_num] = i;
    }
    
    vector<pair<string, int> > v(m.begin(),m.end());
    sort(v.begin(),v.end(),[](auto& a,auto& b){return a.second < b.second;});


    int ens = min(N,(int)m.size()); // 전체 수강인원 보다 신청인원이 적은 경우!

    for(int i=0; i<ens; i++){
        cout << v[i].first << "\n";
    }
    
    // for(int i=0; i<N; i++){
    //     cout << v[i] << "\n";
    // }

    return 0;
}