function solution(table, languages, preference) {
    const tableArr = [], compArr = [], resultObject = {};
    let maxValue = 0, compName = '';
    
    const sortedArr = Sort(languages, preference);
    
    for(let i=0; i<table.length; i++){
        tableArr.push(table[i].split(' '));
        compArr.push(tableArr[i][0]);
        resultObject[tableArr[i][0]] = 0;
    }
    
    for(let i=0; i<sortedArr.length; i++)
        for(let j=0; j<tableArr.length; j++)
            for(let k=1; k<6; k++)
                if(sortedArr[i][0] === tableArr[j][k])
                    resultObject[tableArr[j][0]] += (6-k)*sortedArr[i][1]
    
    for(let i=0; i<compArr.length; i++){
        const value = resultObject[compArr[i]]
        if(maxValue < value){
            maxValue = value;
            compName = compArr[i];
        }
        else if(maxValue === value && compName > compArr[i]){
            compName = compArr[i];
        }
    }
    
    return compName;
}

const Sort = (lang, pref) => {
    const arr = lang.map((item, index) => [item, pref[index]]);
    const result = arr.sort((a, b) => b[1]-a[1]);
    
    return result;
}
