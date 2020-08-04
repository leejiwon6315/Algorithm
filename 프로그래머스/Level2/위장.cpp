#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hookoo;
    
    for(vector<string> i : clothes) hookoo[i[1]]++;
    for(auto i = hookoo.begin(); i!=hookoo.end(); i++) answer *= i -> second + 1;
        
    return --answer;
}
