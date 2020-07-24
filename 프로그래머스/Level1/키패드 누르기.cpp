#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Rthumb = 12, Lthumb = 10;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            Lthumb = numbers[i];
            answer += 'L';
        }
        
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            Rthumb = numbers[i];
            answer += 'R';
        }
            
        else{
            if(numbers[i] == 0) numbers[i] = 11;

            int distanceL = abs(numbers[i] - Lthumb);
            int distanceR = abs(numbers[i] - Rthumb);

            distanceL = (distanceL/3) + (distanceL%3);
            distanceR = (distanceR/3) + (distanceR%3);

            if(distanceL == distanceR){
                if(hand == "right"){
                    Rthumb = numbers[i];
                    answer += 'R';
                }else{
                    Lthumb = numbers[i];
                    answer += 'L';
                }
            } 
            else if(distanceL < distanceR){
                Lthumb = numbers[i];
                answer += 'L';
            }
            else {
                Rthumb = numbers[i];
                answer += 'R';
            }
        }
             
    }
    return answer;
}
