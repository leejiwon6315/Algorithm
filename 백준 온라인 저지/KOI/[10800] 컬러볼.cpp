#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200001;

struct ballInfo{
    int idx, color, size;
};

bool compare(ballInfo &a, ballInfo &b){
    return a.size < b.size;
}


int main(){
    vector<ballInfo> ball;
    
    int n, justSize = 0, sameColor[MAX], result[MAX];;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int size, color;
        cin >> color >> size;
        ball.push_back({i, color, size});
    }
    
    sort(ball.begin(), ball.end(), compare);
    
    for(unsigned long i=0, j=0; i<n; i++){
        while(ball[i].size > ball[j].size){
            
            justSize += ball[j].size;
            sameColor[ball[j].color] += ball[j].size;
            
            j++;
        }
        
        result[ball[i].idx] = justSize - sameColor[ball[i].color];
    }
    
    for(int i=0; i<n; i++){
        cout << result[i] << "\n";
    }
    return 0;
}
