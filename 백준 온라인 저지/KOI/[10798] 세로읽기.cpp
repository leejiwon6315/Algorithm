#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> word;
    string result = "";
    
    for(int i=0; i<5; i++){
        string input;
        cin >> input;
        word.push_back(input);
    }
    
    for(int k=0; k<15; k++){
        for(int i=0; i<5; i++){
            if(word[i].size()>k)
                cout << word[i][k];
        }
    }
    
    return 0;
}
