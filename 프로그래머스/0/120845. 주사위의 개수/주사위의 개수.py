def solution(box, n):
    answer = 1
    
    for i in box:
        answer = answer * int (i/n)
    return answer