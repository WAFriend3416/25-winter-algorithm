#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

char input[5][15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    for(int i=0; i<5; i++){
        cin >> input[i];
    }
    for(int k=0; k<15; k++){
        for(int m=0; m<5; m++){
            if(input[m][k] != NULL) cout << input[m][k];;
        }
    }
    return 0;
}