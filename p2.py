# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    # 이 곳에 코드를 작성하세요.
    stack = []              # 여는 괄호 '('를 저장할 스택
    unmatched = 0           # 짝이 안 맞는 닫는 괄호 수

    for char in input:
        print(char)         # 한 글자씩 출력 (문제 조건)

        if char == '(':
            stack.append('(')   # 여는 괄호를 스택에 추가
        else:  # char == ')'
            if stack:
                stack.pop()     # 짝이 되는 여는 괄호 제거
            else:
                unmatched += 1  # 짝이 없으면 필요한 여는 괄호 개수 증가

    result = unmatched + len(stack)  # 닫는 괄호 부족 수 + 여는 괄호 남은 수
    return result

result = problem2(input)

assert result == 3
print("정답입니다.")