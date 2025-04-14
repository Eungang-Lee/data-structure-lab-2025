#include "sparsepoly.hpp"

int main() {
    // 희소 다항식 A, B 생성
    SparsePoly A;
    SparsePoly B;

    // A 입력 및 출력
    A.read();
    A.display("Poly A: ");

    // B 입력 및 출력
    B.read();
    B.display("Poly B: ");

    // A + B 결과를 C에 저장 후 출력
    SparsePoly C;
    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}