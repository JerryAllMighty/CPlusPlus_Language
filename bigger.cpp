#include "bigger.h"

int main() {
    biggerHeader();
    // a�� b�� �� �߿��� �� ū ���� ����Ѵ�
    int a;
    int b;
    char str[2];
    std::cin >> a >> str;
    std::cin >> b >> str;
    if (a > b)
        std::cout << a << std::endl;
    else
        std::cout << b << std::endl;
    return 0;
}