#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX_DEGREE 101  // 필요 시 사용 (현재는 사용 안 함)

class SparsePoly {
    int numTerms;                        // 항의 개수
    vector<int> exponents;              // 각 항의 차수 저장
    vector<float> coefficients;         // 각 항의 계수 저장

public:
    // 생성자
    SparsePoly() : numTerms(0) {}

    // 다항식 입력 함수
    void read() {
        cout << "항의 개수를 입력하세요: ";
        cin >> numTerms;

        for (int i = 0; i < numTerms; ++i) {
            float coef;
            int exp;

            cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ";
            cin >> coef >> exp;

            // 계수 0인 항은 저장하지 않음
            if (coef != 0.0f) {
                coefficients.push_back(coef);
                exponents.push_back(exp);
            }
        }

        // 실제 저장된 항 개수 업데이트
        numTerms = coefficients.size();
    }

    // 다항식 출력 함수
    void display(const char* label) const {
        cout << label;

        for (int i = 0; i < numTerms; ++i) {
            cout << fixed << setprecision(1) << coefficients[i] << "x^" << exponents[i];
            if (i != numTerms - 1) cout << " + ";
        }
        cout << endl;
    }

    // 덧셈 함수: C = A + B
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        coefficients.clear();
        exponents.clear();

        // 두 다항식을 차수 기준으로 병합
        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] > b.exponents[j]) {
                coefficients.push_back(a.coefficients[i]);
                exponents.push_back(a.exponents[i]);
                ++i;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                coefficients.push_back(b.coefficients[j]);
                exponents.push_back(b.exponents[j]);
                ++j;
            }
            else {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0.0f) {
                    coefficients.push_back(sum);
                    exponents.push_back(a.exponents[i]);
                }
                ++i;
                ++j;
            }
        }

        // 남은 항 처리
        while (i < a.numTerms) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            ++i;
        }

        while (j < b.numTerms) {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            ++j;
        }

        // 덧셈 결과 항 개수 갱신
        numTerms = coefficients.size();
    }
};

#endif