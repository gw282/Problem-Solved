def solution(my_string):
    answer = 0
    
    for i in my_string:
        if i >= '0' and i <= '9':
            answer += int(i)
    return answer