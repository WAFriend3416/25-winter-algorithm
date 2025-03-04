#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<int> devices(K);
    for (int i = 0; i < K; i++) {
        cin >> devices[i];
    }
    
    vector<int> plugged; // 현재 꽂혀있는 기기 목록
    int cnt = 0;        // 플러그 교체 횟수

    // Ex) N=3, devices = {1, 2, 3, 4, 5, 1, 2} 
    for (int i = 0; i < K; i++) {
        int device = devices[i];

        // 1. 이미 꽂혀있는 경우
        // ex) plugged에 이미 1이 있고, 현재 device도 1일 경우.
        if (find(plugged.begin(), plugged.end(), device) != plugged.end())
            continue;
        
        // 2. 빈 멀티탭 소켓이 남아 있는 경우
        // ex) plugged가 {1, 2}인데, N=3이므로 device 3을 추가 가능.
        if (plugged.size() < N) {
            plugged.push_back(device);
            continue;
        }
        
        // 3. 꽉 찬 경우, 교체가 필요함.
        // ex) plugged가 {1, 2, 3}이고 현재 device가 4일 경우.
        // 앞으로의 사용 순서를 조사하여 교체할 기기를 결정. -> {4, 5, 1, 2}
        int idxToRemove = -1, maxFutureIndex = -1;
        for (int j = 0; j < plugged.size(); j++) {
            int current = plugged[j];
            int nextIndex = -1;
            
            // 현재 기기가 앞으로 사용되는지 확인.
            // ex) plugged에 1, 2, 3이 있을 때, device 3가 이후에 사용되지 않으면 nextIndex는 -1.
            for (int k = i + 1; k < K; k++) {
                if (devices[k] == current) {
                    nextIndex = k;
                    break;
                }
            }
            // 만약 기기가 앞으로 사용되지 않으면, 바로 제거 대상으로 선택. -> 3 이 여기에 해당
            if (nextIndex == -1) {
                idxToRemove = j;
                break;
            }
            // 앞으로 사용되지만, 가장 늦게 사용되는 기기를 제거 대상으로 선정.
            if (nextIndex > maxFutureIndex) {
                maxFutureIndex = nextIndex;
                idxToRemove = j;
            }
        }
        // 선택된 기기를 제거하고 현재 기기를 꽂음.
        plugged[idxToRemove] = device;
        cnt++;
    }
    
    cout << cnt << "\n";
    return 0;
}
