//
// Created by PC_1M on 2024-11-09.
//
/*
 * 정수를 저장하는 객체를 만들기 위한 클래스를 설계
 * C++ 프로그래밍
 * 2024.11.04
 * 김윤민 202334-364307
 */

#ifndef MYFIRSTC__PROJECT_INTEGERSTORAGE_H
#define MYFIRSTC__PROJECT_INTEGERSTORAGE_H

#include <iostream>
#include <vector>

using namespace std;

class IntegerStorage {
private:
    std::vector<int> data; // 정수를 저장할 벡터. 배열의 길이가 가변적이라 사용
    size_t maxSize; // 최대 개수. 각각의 객체의 최댓값은 객체 생성된 후 변해야 하기에 (2배로 혹은 필요시 증가) const 선언은 하지 않음

public:
    explicit IntegerStorage(size_t maxCount); // 생성자 선언
    ~IntegerStorage(); // 소멸자 선언
    size_t add(int value); // 정수를 추가하는 함수
    size_t afterPrint(); //정수 인출 후 공통으로 호출할 함수. 데이터 저장 객체의 저장 공간을 체크
    int printOldestData(); //가장 오래전에 저장한 숫자를 인출
    int printLatestData(); // 마지막으로 저장한 숫자 인출
    int printBiggestData(); // 저장된 숫자 중 가장 큰 값 인출
    int printSmallestData(); // 저장된 숫자 중 가장 작은 값 인출
    int printAverageData(); // 객체에 저장된 숫자들의 평균 리턴
    size_t increaseMaxCapacity(size_t num);//객체에 저장할 수 있는 숫자의 최대 개수를 변경
};

#endif //MYFIRSTC__PROJECT_INTEGERSTORAGE_H



