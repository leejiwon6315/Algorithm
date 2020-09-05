#include <string>
#include <vector>

using namespace std;

string calNum(int num, int n){
    string tmp = "";
    string number = "0123456789ABCDEF";
    
    while(num/n){
        tmp = number[num%n] + tmp;
        num /= n;
    }
    
    tmp = number[num%n] + tmp;
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string allAnswer = "";
    
    for(int i=0; i<t*m; i++){ 
        allAnswer += calNum(i,n);
    }
    int count = 0;
    for(int i=p-1; i<allAnswer.size(); i+=m){
        answer += allAnswer[i];
        if(count +1 == t) break;
        count ++;
    }
    return answer;
}
