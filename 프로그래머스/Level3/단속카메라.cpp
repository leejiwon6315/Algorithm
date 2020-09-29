#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int cam=routes[0][1];
    
        for(int j=0; j<routes.size()-1; j++){
            if(cam>routes[j][1]) cam=routes[j][1];
            if(cam<routes[j+1][0]){
                cam=routes[j+1][1];
                answer ++;
            }
        }
    
    return answer;
}
