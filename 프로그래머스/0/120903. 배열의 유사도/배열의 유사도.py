def solution(s1, s2):
    answer = 0
    
    for i in s1:
        for j in s2:
            if i == j:
                answer = answer +1
    return answer