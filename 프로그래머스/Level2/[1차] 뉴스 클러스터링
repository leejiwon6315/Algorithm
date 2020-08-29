#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> subStr1;
    vector<string> subStr2;
    
    for(int i=0; i<str1.length()-1; i++){
        string tmp1 = "", tmp2 = "";
        tmp1 += str1[i];
        tmp2 += str1[i+1];
        subStr1.push_back(tmp1 + tmp2);
    }
    for(int i=0; i<str2.length()-1; i++){
        string tmp1 = "", tmp2 = "";
        tmp1 += str2[i];
        tmp2 += str2[i+1];
        subStr2.push_back(tmp1 + tmp2);
    }

    for(int i=0; i<subStr1.size(); i++){
        if(!((subStr1[i][0] >= 65 && subStr1[i][0] <= 90 ) || (subStr1[i][0] >= 97 && subStr1[i][0] <= 122)) || !((subStr1[i][1] >= 65 && subStr1[i][1] <= 90 ) || (subStr1[i][1] >= 97 && subStr1[i][1] <= 122))){
            subStr1[i] = ' ';
        }
        else{
            subStr1[i][0] = toupper(subStr1[i][0]);
            subStr1[i][1] = toupper(subStr1[i][1]);
        }
    }
    
    for(int i=0; i<subStr2.size(); i++){
        if(!((subStr2[i][0] >= 65 && subStr2[i][0] <= 90 ) || (subStr2[i][0] >= 97 && subStr2[i][0] <= 122)) || !((subStr2[i][1] >= 65 && subStr2[i][1] <= 90 ) || (subStr2[i][1] >= 97 && subStr2[i][1] <= 122))){
            subStr2[i] = ' ';
        }
        else{
            subStr2[i][0] = toupper(subStr2[i][0]);
            subStr2[i][1] = toupper(subStr2[i][1]);
        }
    }

    if(subStr1 == subStr2) return 65536;
    
    double cross = 0;
    double sum = 0;
    
    for(int i=0; i<subStr1.size(); i++){
        if(subStr1[i][0] != ' ' && subStr1[i][1] != ' ' ) sum ++;
    }
    
    for(int i=0; i<subStr1.size(); i++){
        for(int j=0; j<subStr2.size(); j++){
            if(subStr1[i][0] != ' ' && subStr1[i][1] != ' ' && subStr2[j][0] != ' ' && subStr2[j][1] != ' '){
                if(subStr1[i] == subStr2[j]){
                    cross ++;
                    subStr2[j] = "x";
                    break;
                }
            }
        }
    }
 
    for(int i=0; i<subStr2.size(); i++){
        if(subStr2[i] != "x" && subStr2[i][0] != ' ' && subStr2[i][1] != ' ') sum ++;
    }

    if(sum){
        answer = (int)(cross/sum*65536);
    }
    
    return answer;
}
