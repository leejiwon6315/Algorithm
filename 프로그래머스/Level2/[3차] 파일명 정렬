#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<string> a, vector<string> b){
    string checkA;
    string checkB;
    
    for(int i=0; i<a[0].size(); i++) checkA += toupper(a[0][i]);
    for(int i=0; i<b[0].size(); i++) checkB += toupper(b[0][i]);
    
    if(!checkA.compare(checkB)) return stoi(a[1]) < stoi(b[1]);
    if(checkA.compare(checkB)>0) return false;
    else return true;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> data(files.size(), vector<string>(3));
    
    for(int i=0; i<files.size(); i++){
        int j=0;
        if(j<files[i].size()){
            while( files[i][j]<'0' || files[i][j]>'9' ){
                data[i][0] += files[i][j];
                j++;
            }
            while( files[i][j]>='0' && files[i][j]<='9' ){
                data[i][1] += files[i][j];
                j++;
            }
            while(j<files[i].size()){
                data[i][2] += files[i][j];
                j++;
            }
        }

    }
    
    stable_sort(data.begin(), data.end(), check);
    
    for(int i=0; i<files.size(); i++){
        string tmp = "";
        tmp += data[i][0] + data[i][1] + data[i][2];
        answer.push_back(tmp);
    }
    return answer;
}
