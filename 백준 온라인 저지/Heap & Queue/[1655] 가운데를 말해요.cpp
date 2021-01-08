#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    priority_queue<int, vector<int>, less<int>>maxQueue;
    vector<int> number;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        number.push_back(input);
    }
    
    for(int i=0; i<n; i++){
        if(minQueue.size() < maxQueue.size())
            minQueue.push(number[i]);
        else
            maxQueue.push(number[i]);
    
        if(!maxQueue.empty() && !minQueue.empty()){
            if(minQueue.top() < maxQueue.top()){
                int minValue = minQueue.top();
                int maxValue = maxQueue.top();
                
                minQueue.pop();
                maxQueue.pop();
                
                maxQueue.push(minValue);
                minQueue.push(maxValue);
            }
        }
        cout << maxQueue.top() <<"\n";
    }

    return 0;
}
