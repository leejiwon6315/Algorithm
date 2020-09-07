//
//  main.cpp
//  알고리즘공부
//
//  Created by 이지원 on 2020/01/09.
//  Copyright © 2020 이지원. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

#define MAX_TERMS 80

struct Term{
    int expon;      // 지수
    float coeff;    // 계수
};

class SparasePoly{
    int degree;
    int nTerms;
    Term term[MAX_TERMS];
    
public:
    SparasePoly(){
        nTerms = 0;
        degree = 0;
    }
    
    void read(){
        printf("다항식의 최고 차수를 입력하시오 : ");
        scanf("%d", &degree);
        printf("계수가 0 이 아닌 항의 개수를 입력하시오 : ");
        scanf("%d", &nTerms);
        printf("각 항의 계수를 입력하시오 : ");
        
        int count = 0;  // 지수를 세기 위한 변수
        int termArrIdx = 0;  // 0이 아닌 식의 정보만 term에 넣기위한 index
        for(int i=0; i<=degree; i++){

            float input;
            scanf("%f", &input);
            
            if(input != 0){
                term[termArrIdx].coeff = input;
                term[termArrIdx].expon = degree - count;
                count ++;
                termArrIdx ++;
            }
            else{
                count ++;
            }
        }
        printf("\n");
    }
    
    void display(const char *str = "Poly ="){
            printf("\t%s", str);
 
        for(int i=0; i<=nTerms; i++){
            if( term[i].coeff > 0){
                if(term[i].expon == 0){
                    printf("%4.1f",term[i].coeff);
                }
                else{
                    printf("%5.1f x^%d",term[i].coeff, term[i].expon);
                }
            }
            else if(term[i].coeff < 0){
                if(term[i].expon == 0){
                    printf("( %4.1f )",term[i].coeff);
                }
                else{
                    printf("( %5.1f x^%d )",term[i].coeff, term[i].expon);
                }
            }
            
            if(i < nTerms && term[i+1].coeff) printf(" +");
            else printf("\n");
        }
    }
    
    void add(SparasePoly a, SparasePoly b){
        
        if(a.degree > b.degree){
            *this = a;
            nTerms += b.nTerms;     // a의 0이 아닌 항 개수 + b의 0이 아닌 항 개수를 더한후, 후에 지수가 중복된 항을 빼줌
            Term *tmp = new Term[a.nTerms];     // 계산된 결과 배열을 임시로 담기 위해 할당한 배열
            
            int aCount = 0, bCount = 0, k = 0;
            
            while(aCount <= a.nTerms && bCount <= b.nTerms){
                if(term[aCount].expon == b.term[bCount].expon){
                    tmp[k].coeff = term[aCount].coeff + b.term[bCount].coeff;
                    tmp[k].expon = b.term[bCount].expon;
                    aCount ++;
                    bCount ++;
                    k++;
                    nTerms --;      // 지수가 중복된 항 제외
                }
                else if(term[aCount].expon > b.term[bCount].expon){
                    tmp[k].coeff = term[aCount].coeff;
                    tmp[k].expon = term[aCount].expon;
                    aCount ++;
                    k++;
                }
                else if(term[aCount].expon < b.term[bCount].expon){
                    tmp[k].coeff = b.term[bCount].coeff;
                    tmp[k].expon = b.term[bCount].expon;
                    bCount ++;
                    k++;
                }
                
            }
            
            for(int i=0; i<=nTerms; i++){
                term[i].coeff = tmp[i].coeff;
                term[i].expon = tmp[i].expon;
            }
            delete[] tmp;
        }
        
        else{
            *this = b;
            nTerms += a.nTerms;     // a의 0이 아닌 항 개수 + b의 0이 아닌 항 개수를 더한후, 후에 지수가 중복된 항을 빼줌
            Term *tmp = new Term[b.nTerms];     // 계산된 결과 배열을 임시로 담기 위해 할당한 배열
            
            int aCount = 0, bCount = 0, k = 0;
            
            while(aCount <= a.nTerms && bCount <= b.nTerms){
                if(term[bCount].expon == a.term[aCount].expon){
                    tmp[k].coeff = term[bCount].coeff + a.term[aCount].coeff;
                    tmp[k].expon = a.term[aCount].expon;
                    aCount ++;
                    bCount ++;
                    k++;
                    nTerms --;      // 지수가 중복된 항 제외
                }
                else if(term[bCount].expon > a.term[aCount].expon){
                    tmp[k].coeff = term[bCount].coeff;
                    tmp[k].expon = term[bCount].expon;
                    bCount ++;
                    k++;
                }
                else if(term[bCount].expon < a.term[aCount].expon){
                    tmp[k].coeff = a.term[aCount].coeff;
                    tmp[k].expon = a.term[aCount].expon;
                    aCount ++;
                    k++;
                }
                
            }
            
            for(int i=0; i<=nTerms; i++){
                term[i].coeff = tmp[i].coeff;
                term[i].expon = tmp[i].expon;
            }
            
            delete[] tmp;
        }
    }
    
};

int main(){
    
    SparasePoly a, b, c;
        
        a.read();
        b.read();
        
        a.display("a = ");
        b.display("b = ");
        
        c.add(a, b);
        c.display("a+b = ");
    
    return 0;
}
