#include <iostream>                                 // 입출력 스트림
#include <sstream>                                  // 문자열 스트림 (문자열 → 숫자 변환)
#include <string>                                   // string 클래스
#include <vector>                                   // 벡터 사용
using namespace std;

// 입력된 배열에서 최댓값을 찾아 반환하는 함수
int findMax(const vector<int>& arr) {
    int maxVal = arr[0];                            // 첫 번째 값을 최댓값으로 설정
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) maxVal = arr[i];       // 더 큰 값 발견 시 갱신
    }
    return maxVal;
}

int main() {
    string line;                                    // 한 줄 입력을 저장할 문자열
    vector<int> arr;                                // 입력된 숫자들을 저장할 벡터
    vector<int> maxResults;                         // 각 줄마다 계산된 최댓값 저장용

    // 여러 줄 입력 받기 (빈 줄 입력 시 종료)
    while (getline(cin, line) && !line.empty()) {
        // 쉼표(,)를 공백(' ')으로 바꿔서 숫자 분리되게 만들기
        for (char& c : line) {
            if (c == ',') c = ' ';
        }

        stringstream ss(line);                      // 문자열을 스트림 형태로 변환
        int num;
        arr.clear();                                // 이전 입력 값들 초기화

        // 공백 기준으로 숫자 파싱해서 벡터에 추가
        while (ss >> num) {
            arr.push_back(num);
        }

        // 배열이 비어있지 않으면 최댓값 찾아서 저장
        if (!arr.empty()) {
            maxResults.push_back(findMax(arr));
        }
    }

    // 저장된 최댓값들 출력 (마지막 값 뒤에는 슬래시 없이 출력)
    for (int i = 0; i < maxResults.size(); ++i) {
        cout << maxResults[i];
        if (i != maxResults.size() - 1) cout << "/";
    }

    return 0;
}