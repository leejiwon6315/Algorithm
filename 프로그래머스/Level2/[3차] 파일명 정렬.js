function solution(files) {
    let answer = [];

    let orderObject = files.map((name, index) => ({name, index}));
    // sort 적용시 같은 결과 값에 대해 원래 순서를 유지하기 위해 index를 추출하여 묶음

    const compare = (a, b) => {
        let regNum = /[0-9]/g;
        // 숫자 표현 정규식
        
        let indexA = a.indexOf((a.match(regNum))[0]);
        let indexB = b.indexOf((b.match(regNum))[0]);
        // 정규식을 활용해 숫자로 존재하는 가장 첫번째 인덱스들을 담음
        
        let head = (a.substring(0, indexA)).toLowerCase().localeCompare(b.substring(0, indexB).toLowerCase());
        // 숫자가 나오기 직전까지인 HEAD부분을 분리하여 정렬하는 작업
        // substring(s, e) : 문자객체에서 s부분 부터 e부분까지를 반환
        // 모두 소문자로 변환하여 비교
        // 인수(localeCompare 내 파라미터 값)이 string 객체(localeCompare 앞 인자) 보다 뒤에 있으면 음수, 그 반대면 양수를 출력, 동등하면 0
        
        if(head === 0){
            // head가 같다면, number 기준으로 정렬
            
            let strA = parseInt(a.substring(indexA));
            let strB = parseInt(b.substring(indexB));
            
            if(strA < strB){
                return -1;
            }
            else if(strA > strB){
                return 1;
            }
            else {
                return 0;
            }
        }
        else if(head === -1){
            return -1;
        }
        else {
            return 1;
        }
    }
    
    orderObject.sort((a,b)=>{
        // sort 함수 내에서 비교값이 같은 경우 원래 순서를 유지하기 위함
        
        let result = compare(a.name, b.name);
        return result === 0 ? a.index - b.index : result;
        // 비교값이 같으면 원래 인덱스를 유지, 아니면 결과값을 반환
    })
    
    return orderObject.map(ans => ans.name);
    // 결과값 매핑 
}
