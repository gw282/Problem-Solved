def solution(myString, pat):
    answer = 0
    myString = myString.upper()
    pat = pat.upper()
    
    answer = myString.find(pat)
    
    if answer == -1:
        answer = 0
    else:
        answer =1
    return answer