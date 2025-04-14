#include <opencv2/opencv.hpp>                           // OpenCV �ٽ� ��� ����
#include <iostream>
using namespace cv;
using namespace std;

// �̹������� ���� ���� ȭ���� ���� ���ϴ� �Լ�
int findMaxBrightness(const Mat& grayImg) {
    CV_Assert(grayImg.type() == CV_8UC1);               // �Է��� �׷��̽����� �̹������� Ȯ��

    int maxVal = 0;

    // ��� �ȼ� ��ȸ�ϸ� �ִ� ã��
    for (int row = 0; row < grayImg.rows; ++row) {
        for (int col = 0; col < grayImg.cols; ++col) {
            int pixel = grayImg.at<uchar>(row, col);    // ���� �ȼ��� ��� �� (0~255)
            if (pixel > maxVal) maxVal = pixel;         // �� ū ���̸� ����
        }
    }

    return maxVal;
}

int main() {
    // �̹��� ���� �б� (�׷��̽����� ���)
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

    // �̹����� ���������� �ε���� ���� ���
    if (img.empty()) {
        cout << "�̹��� ������ �ҷ����� ���߽��ϴ�." << endl;
        return -1;
    }

    // �ִ� ��Ⱚ ���
    int maxBrightness = findMaxBrightness(img);

    // ��� ���
    cout << "�ִ� ��Ⱚ (0~255): " << maxBrightness << endl;

    return 0;
}