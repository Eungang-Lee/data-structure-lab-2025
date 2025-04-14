#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX_DEGREE 101  // �ʿ� �� ��� (����� ��� �� ��)

class SparsePoly {
    int numTerms;                        // ���� ����
    vector<int> exponents;              // �� ���� ���� ����
    vector<float> coefficients;         // �� ���� ��� ����

public:
    // ������
    SparsePoly() : numTerms(0) {}

    // ���׽� �Է� �Լ�
    void read() {
        cout << "���� ������ �Է��ϼ���: ";
        cin >> numTerms;

        for (int i = 0; i < numTerms; ++i) {
            float coef;
            int exp;

            cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��:��� ����): ";
            cin >> coef >> exp;

            // ��� 0�� ���� �������� ����
            if (coef != 0.0f) {
                coefficients.push_back(coef);
                exponents.push_back(exp);
            }
        }

        // ���� ����� �� ���� ������Ʈ
        numTerms = coefficients.size();
    }

    // ���׽� ��� �Լ�
    void display(const char* label) const {
        cout << label;

        for (int i = 0; i < numTerms; ++i) {
            cout << fixed << setprecision(1) << coefficients[i] << "x^" << exponents[i];
            if (i != numTerms - 1) cout << " + ";
        }
        cout << endl;
    }

    // ���� �Լ�: C = A + B
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        coefficients.clear();
        exponents.clear();

        // �� ���׽��� ���� �������� ����
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

        // ���� �� ó��
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

        // ���� ��� �� ���� ����
        numTerms = coefficients.size();
    }
};

#endif