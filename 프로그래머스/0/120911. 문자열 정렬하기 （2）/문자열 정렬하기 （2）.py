def solution(my_string):
    answer = ''
    my_string = my_string.lower()
    sorted_characters = sorted(my_string)
    answer = ''.join(sorted_characters)
    return answer