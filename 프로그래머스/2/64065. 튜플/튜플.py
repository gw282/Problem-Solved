def solution(s):
    answer = []
    counts = count_num_freq(s)

    # 개수 기준으로 내림차순 정렬된 숫자 리스트 생성
    sorted_counts = sorted(counts.items(), key=lambda x: x[1], reverse=True)

    # 개수가 많은 숫자부터 answer에 추가
    for num, count in sorted_counts:
        answer.append(num)

    return answer

def count_num_freq(s):
    # 중괄호를 제거
    cleaned_string = s.strip('{}')
    
    # 쉼표로 나누어 리스트 생성
    parts = cleaned_string.split('},{')
    
    # 모든 숫자를 저장할 리스트
    numbers = []

    # 각 부분에서 숫자를 정수로 변환하여 numbers 리스트에 추가
    for part in parts:
        # 쉼표로 나누고 정수로 변환
        numbers.extend(map(int, part.split(',')))

    # 숫자의 개수 세기
    counts = {}
    for number in numbers:
        # 숫자의 개수 카운트
        counts[number] = counts.get(number, 0) + 1  

    return counts
