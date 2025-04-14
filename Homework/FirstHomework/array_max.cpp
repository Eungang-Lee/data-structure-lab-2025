#include <iostream>                                 // ����� ��Ʈ��
#include <sstream>                                  // ���ڿ� ��Ʈ�� (���ڿ� �� ���� ��ȯ)
#include <string>                                   // string Ŭ����
#include <vector>                                   // ���� ���
using namespace std;

// �Էµ� �迭���� �ִ��� ã�� ��ȯ�ϴ� �Լ�
int findMax(const vector<int>& arr) {
    int maxVal = arr[0];                            // ù ��° ���� �ִ����� ����
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) maxVal = arr[i];       // �� ū �� �߰� �� ����
    }
    return maxVal;
}

int main() {
    string line;                                    // �� �� �Է��� ������ ���ڿ�
    vector<int> arr;                                // �Էµ� ���ڵ��� ������ ����
    vector<int> maxResults;                         // �� �ٸ��� ���� �ִ� �����

    // ���� �� �Է� �ޱ� (�� �� �Է� �� ����)
    while (getline(cin, line) && !line.empty()) {
        // ��ǥ(,)�� ����(' ')���� �ٲ㼭 ���� �и��ǰ� �����
        for (char& c : line) {
            if (c == ',') c = ' ';
        }

        stringstream ss(line);                      // ���ڿ��� ��Ʈ�� ���·� ��ȯ
        int num;
        arr.clear();                                // ���� �Է� ���� �ʱ�ȭ

        // ���� �������� ���� �Ľ��ؼ� ���Ϳ� �߰�
        while (ss >> num) {
            arr.push_back(num);
        }

        // �迭�� ������� ������ �ִ� ã�Ƽ� ����
        if (!arr.empty()) {
            maxResults.push_back(findMax(arr));
        }
    }

    // ����� �ִ񰪵� ��� (������ �� �ڿ��� ������ ���� ���)
    for (int i = 0; i < maxResults.size(); ++i) {
        cout << maxResults[i];
        if (i != maxResults.size() - 1) cout << "/";
    }

    return 0;
}