def solution(hp):
    answer = 0
    rest = hp
    answer += int(rest/5)
    rest = rest - int(rest/5) * 5
    
    answer += int(rest/3)
    rest = rest - int(rest/3) * 3
    
    answer += rest
    return answer