#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    vector<int> w;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
    }
    
    sort(w.begin(), w.end(), less<int>());

    int min = w[0];
    int weight = min*w.size();
    
    for(int i=0; i<w.size(); i++){
        if(w[i]*(w.size()-i) > weight){
            weight = w[i]*(w.size()-i);
        }
    }
    
    cout << weight;
    
    return 0;
}

