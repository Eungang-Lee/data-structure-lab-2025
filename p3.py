# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    #여기에서부터 코드를 작성하세요.
    from collections import deque

    # 현재 위치에서 BFS로 먹을 수 있는 벌집 탐색
    def bfs(x, y):
        visited = [[False] * N for _ in range(N)]      # 방문 여부 추적 배열
        queue = deque([(x, y, 0)])                      # (x, y, 거리) 형태로 초기화
        visited[x][y] = True
        edible = []                                     # 먹을 수 있는 벌집 후보 저장

        while queue:
            cx, cy, dist = queue.popleft()

            for dx, dy in [(-1,0), (0,-1), (0,1), (1,0)]:  # 상, 좌, 우, 하 순으로 이동
                nx, ny = cx + dx, cy + dy

                # 범위 안이고 아직 방문하지 않았으며, 곰이 통과할 수 있는 칸이라면
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    if forest[nx][ny] <= bear_size:
                        visited[nx][ny] = True
                        queue.append((nx, ny, dist + 1))
                        # 먹을 수 있는 벌집이면 리스트에 저장
                        if 0 < forest[nx][ny] < bear_size:
                            edible.append((dist + 1, nx, ny))

        if edible:
            edible.sort()           # 거리 > 위쪽 > 왼쪽 우선순위로 정렬됨
            return edible[0]        # 가장 우선순위 높은 벌집 반환
        else:
            return None             # 먹을 수 있는 벌집이 없다면 None

    while True:
        target = bfs(bear_x, bear_y)
        if not target:
            break                   # 더 이상 먹을 수 있는 벌집이 없으면 종료
        dist, nx, ny = target
        time += dist                # 이동 시간 누적
        bear_x, bear_y = nx, ny     # 곰의 위치 갱신
        forest[nx][ny] = 0          # 벌집 제거 (빈 칸 처리)
        honeycomb_count += 1        # 먹은 벌집 수 증가

        # 먹은 수 == 곰의 크기 → 성장
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time
    return result

result = problem3(input)

assert result == 14
print("정답입니다.")
