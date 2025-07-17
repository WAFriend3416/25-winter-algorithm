#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // N 입력
    int N;
    cin >> N;
    cin.ignore();
    // N 길이의 숫자 입력
    string numbers;
    getline(cin,numbers);
    // 합계 출력
    int sum = 0;
    for(int i=0; i<numbers.length(); i++){
        sum += (numbers[i]-'0');
    }
    // for(auto i : numbers){
    //     i = i + '0';
    //     sum += i;
    // }
    cout << sum ;
    return 0;
}