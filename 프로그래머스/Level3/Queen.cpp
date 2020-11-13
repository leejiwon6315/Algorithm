#include <string>
#include <vector>
#include <cmath>

using namespace std;
int tmp = 0;

bool checkQ(vector<int> map, int index){
    for(int i=0; i<index; i++){
        if(map[i] == map[index]) return false;
        if(abs(index-i) == abs(map[index] - map[i])) return false;
    }
    return true;
}

void queenMaker(vector<int> map, int cnt){
    if(cnt == map.size()){
        tmp ++;
        return;
    }
    
    for(int i=0; i<map.size(); i++){
        map[cnt] = i;
        if(checkQ(map, cnt)) queenMaker(map, cnt+1);
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> map(n);
    
    queenMaker(map, 0);
    answer = tmp;
    
    return answer;
}
