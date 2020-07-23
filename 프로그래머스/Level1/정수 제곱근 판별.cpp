#include <string>
#include <math.h>

using namespace std;

long long solution(long long n) {

    if((int)sqrt(n)==sqrt(n))return (sqrt(n)+1) * (sqrt(n)+1);
    else return -1;
}
