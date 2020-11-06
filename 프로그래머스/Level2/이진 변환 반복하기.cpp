#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    
    while(s!="1"){
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0'){
                s.erase(s.begin()+i);
                answer[1]++;
                i--;
            }
        }
        int numberLength = s.length();
        string tmp = "";

        while(numberLength){
            tmp += to_string(numberLength%2);
            numberLength /= 2;
        }

        s= "";

        for(int i=tmp.length()-1; i>=0; i--) s += tmp[i];

        answer[0]++;
    }
    return answer;
}
