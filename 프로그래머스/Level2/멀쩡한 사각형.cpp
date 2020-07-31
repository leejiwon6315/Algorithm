using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    long long sum = (long long)w * (long long)h;
    
    int startPoint = w < h ? w : h;
    int k = 0;
    for(int i=startPoint; i>0; i--){
        if(w%i == 0 && h%i == 0){
            k = i;
            break;
        }
    }
    answer = sum - k*((w/k)+(h/k)-1);
    return answer;
}
