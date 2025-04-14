#include <opencv2/opencv.hpp>                           // OpenCV 핵심 기능 포함
#include <iostream>
using namespace cv;
using namespace std;

// 이미지에서 가장 밝은 화소의 값을 구하는 함수
int findMaxBrightness(const Mat& grayImg) {
    CV_Assert(grayImg.type() == CV_8UC1);               // 입력이 그레이스케일 이미지인지 확인

    int maxVal = 0;

    // 모든 픽셀 순회하며 최댓값 찾기
    for (int row = 0; row < grayImg.rows; ++row) {
        for (int col = 0; col < grayImg.cols; ++col) {
            int pixel = grayImg.at<uchar>(row, col);    // 현재 픽셀의 밝기 값 (0~255)
            if (pixel > maxVal) maxVal = pixel;         // 더 큰 값이면 갱신
        }
    }

    return maxVal;
}

int main() {
    // 이미지 파일 읽기 (그레이스케일 모드)
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

    // 이미지가 정상적으로 로드되지 않은 경우
    if (img.empty()) {
        cout << "이미지 파일을 불러오지 못했습니다." << endl;
        return -1;
    }

    // 최대 밝기값 계산
    int maxBrightness = findMaxBrightness(img);

    // 결과 출력
    cout << "최대 밝기값 (0~255): " << maxBrightness << endl;

    return 0;
}