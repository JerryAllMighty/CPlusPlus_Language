#include "bigger.h"

int main() {
    biggerHeader();
    // a와 b의 값 중에서 더 큰 값을 출력한다
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