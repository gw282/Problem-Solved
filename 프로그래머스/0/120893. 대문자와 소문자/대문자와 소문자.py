def solution(my_string):
    answer = ''
    
    for i in my_string:
        if i >= 'A' and i <= 'Z':
            answer += i.lower()
        else:
            answer += i.upper()
    return answer