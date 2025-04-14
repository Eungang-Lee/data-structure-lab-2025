#include "sparsepoly.hpp"

int main() {
    // ��� ���׽� A, B ����
    SparsePoly A;
    SparsePoly B;

    // A �Է� �� ���
    A.read();
    A.display("Poly A: ");

    // B �Է� �� ���
    B.read();
    B.display("Poly B: ");

    // A + B ����� C�� ���� �� ���
    SparsePoly C;
    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}