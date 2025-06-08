# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    # 이곳에 코드를 작성하세요.
    mean = sum(input) // len(input)                   # 평균 계산 (정수 나눗셈)
    median = sorted(input)[len(input) // 2]           # 정렬 후 중앙값 추출
    result = [mean, median]
    return result

result = problem1(input)

assert result == [34, 30]
print("정답입니다.")
