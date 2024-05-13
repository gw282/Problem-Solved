def solution(my_string):
    answer = ''
    for i in my_string:
        if i != 'a' and i != 'i' and i != 'o' and i != 'e' and i != 'u':
            answer += i
    return answer