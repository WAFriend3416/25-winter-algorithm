#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
pair<int,int>arr[26] = {{0,0},};

bool cmpBySecond(const pair<int,int>& a, const pair<int,int>& b)
{
    if (a.second == b.second)
        return a.first > b.first;   // 2차 키
    return a.second > b.second;     // 1차 키
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(int i : str){
        if(i >= 65 && i <= 90){
            arr[i-65].first = i-65;
            arr[i-65].second++;
        }
        else{
           arr[i-97].first = i-97;
           arr[i-97].second++;
        }
    }

    sort(arr,arr+26,cmpBySecond);

    if(arr[0].second == arr[1].second){
        cout << "?";
    }
    else{
        cout << char(arr[0].first+65);
    }
    return 0;
}