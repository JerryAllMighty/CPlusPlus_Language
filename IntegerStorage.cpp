//
// Created by PC_1M on 2024-11-09.
//
/*
 * 정수를 저장하는 객체를 만들기 위한 클래스를 설계
 * C++ 프로그래밍
 * 2024.11.04
 * 김윤민 202334-364307
 */

#include "IntegerStorage.h"
#include <iostream>
#include <vector>

using namespace std;

/*
 * 저장할 수 있는 정수의 최대 개수는 객체가 생성될 때 지정한다.
 * 생성자에서 최대 개수 설정
 * maxCount를 전달 받아서, 멤버변수 maxSize에 그 값을 전달.
*/
IntegerStorage::IntegerStorage(size_t maxCount) : maxSize(maxCount) {
    data.reserve(maxCount); // 데이터 저장 객체의 크기도 함께 변경
}

IntegerStorage::~IntegerStorage() {
    data.clear(); // 요소 모두 삭제. 메모리는 여전히 남아 있음
    data.shrink_to_fit(); //실제 메모리 반환
}

/*
 * 정수를 추가하는 함수
 * 만일 객체가 가득 찬 상태면 저장 공간을 2배 확장한다.
 */
size_t IntegerStorage::add(int value) {
    size_t currentSize = data.capacity(); //현재 데이터 저장 객체의 용량을 담는 변수
    if (data.size() == currentSize) { //객체가 가득 찬 상태인지 체크
        data.reserve(currentSize * 2); //데이터를 저장하는 벡터의 크기를 2배 확장
        std::cout << "저장 공간이 부족하여 " << currentSize * 2 << " 크기로 확장되었습니다.\n"; // 함수 동작 확인을 위한 문자열 출력
    }
    data.push_back(value); //벡터에 정수를 추가
    std::cout << "데이터를 저장하였습니다." << value << "\n"; // 함수 동작 확인을 위한 문자열 출력
    return data.capacity();
}


/*
 * 정수 인출 후 공통으로 호출할 함수.
 * 인출 후 빈 공간이 전체의 3/4 이상이면 저장 공간을 줄인다.
 * 줄어든 저장 공간의 크기는 지정된 크기와 현재 공간의 1/2 중 큰 것으로 한다.
 */
size_t IntegerStorage::afterPrint() {
    int emptySize = data.capacity() - data.size(); //현재 빈 공간 크기 변수에 담기
    if (emptySize >= (data.capacity() * 0.75)) { // 인출 후 빈 공간이 전체의 3/4 이상인지 체크
        int newMaxSize = maxSize; //새롭게 할당할 저장공간의 크기를 담당하는 변수
        if (maxSize < (data.capacity() * 0.5)) { //지정된 크기와 현재 공간의 1/2 중 큰 것을 찾는다
            newMaxSize = (data.capacity() * 0.5); //현재 공간의 1/2가 더 크다면 변수에 값을 담는다.
        }
        //vector의 reserve 함수는 capa를 상향해주는 것에는 사용할 수 있지만, 줄이는 것에는 적용이 안되는 이슈
        //먼저 데이터의 사이즈에 맞게 줄인 후 다시 reserve를 활용
        data.shrink_to_fit();
        data.reserve(newMaxSize);

        std::cout << "인출 후 빈 공간이 전체의 3/4 이상이어 저장 공간이"<< data.capacity() <<  "로 줄었습니다.\n"; // 함수 동작 확인을 위한 문자열 출력
    }
    return data.capacity();
}

/*
 * 가장 오래전에 저장한 숫자를 인출할 수 있다.
 */
int IntegerStorage::printOldestData() {
    int result = data[0]; //리턴값이 될 변수. 가장 처음의 값을 담는다.
    std::cout << "가장 오래전에 저장한 숫자 : " << data[0] << "\n"; // 해당 값 확인 함수
    data.erase(data.begin()); // 벡터에서 해당하는 값 삭제
    afterPrint(); // 인출 후 저장 공간 체크하는 함수
    return result; // 값 반환
}
/*
 * 마지막으로 저장한 숫자를 인출할 수 있다.
 */
int IntegerStorage::printLatestData() {
    int result = data[data.capacity() - 1]; //리턴값이 될 변수. 가장 최근의 값을 담는다.
    std::cout << "마지막으로 저장한 숫자 : " << data[data.capacity() - 1]  << "\n"; // 해당 값 확인 함수
    data.pop_back(); // 벡터에서 해당하는 값 삭제
    afterPrint(); // 인출 후 저장 공간 체크하는 함수
    return result; // 값 반환
}

/*
 * 저장된 숫자 중 가장 큰 값을 인출할 수 있다.
 * (최댓값이 2개 이상이면 그중 가장 오래전에 저장한 숫자를 인출함)
 */
int IntegerStorage::printBiggestData() {
    int maxNum = -2147483648; //리턴값이 될 변수. 가장 큰 값을 담는 목적. 비교를 위해 가장 작은 int의 값을 할당
    vector<int> maxNumIdxList; //구하고자 하는 값이 2개 이상일 수 있기에, 이를 비교하기 위해 배열의 인덱스를 저장하는 용도의 벡터
    for (int i = 0; i < data.size(); i++) { // 가장 큰 값을 찾는 로직
        int num = data[i];
        if (num > maxNum) {
            maxNum = num;
        }
    }
    for (int i = 0; i < data.size(); i++) { // 찾은 최댓값의 인덱스들을 벡터에 저장하는 로직
        int num = data[i];
        if (num == maxNum) {
            maxNumIdxList.push_back(i);
        }
    }
    data.erase(data.begin() + maxNumIdxList[0]); // 해당 최댓값을 벡터에서 지워준다
    std::cout << "저장된 숫자 중 가장 큰 값 : " << maxNum  << "\n"; // 해당 값 확인 함수
    afterPrint(); // 인출 후 저장 공간 체크하는 함수
    return maxNum; // 값 리턴
}

/*
 * 저장된 숫자 중 가장 작은 값을 인출할 수 있다.
 * (최솟값이 2개 이상이면 그중 가장 오래전에 저장한 숫자를 인출함)
 */
int IntegerStorage::printSmallestData() {
    int minNum = 2147483647;  //리턴값이 될 변수. 가장 작은 값을 담는 목적. 비교를 위해 가장 큰 int의 값을 할당
    vector<int> minNumIdxList; //구하고자 하는 값이 2개 이상일 수 있기에, 이를 비교하기 위해 배열의 인덱스를 저장하는 용도의 벡터
    for (int i = 0; i < data.size(); i++) {
        int num = data[i];
        if (num < minNum) {
            minNum = num;
        }
    }
    for (int i = 0; i < data.size(); i++) { // 찾은 최솟값의 인덱스들을 벡터에 저장하는 로직
        int num = data[i];
        if (num == minNum) {
            minNumIdxList.push_back(i);
        }
    }
    data.erase(data.begin() + minNumIdxList[0]); // 해당 최솟값을 벡터에서 지워준다
    std::cout << "저장된 숫자 중 가장 작은 값 : " << minNum  << "\n"; // 해당 값 확인 함수
    afterPrint(); // 인출 후 저장 공간 체크하는 함수
    return minNum;  // 값 리턴
}


/*
 * 객체에 저장된 숫자들의 평균을 구할 수 있다.
 */
int IntegerStorage::printAverageData() {
    int result = 0; // 평균 값을 담을 변수
    int total = 0; // 전체 합산 수를 담을 변수
    for (int num: data) {
        total += num;
    }
    result = total / data.size(); // 전체 합산 수와 객체 사이즈를 나누어 평균 만들기
    std::cout << "평균 값 : " << result << "\n"; // 함수 동작 확인을 위한 문자열 출력
    afterPrint(); // 인출 후 저장 공간 체크하는 함수
    return result;

}

/*
 * 객체에 저장할 수 있는 숫자의 최대 개수를 변경한다.
 * 만일 현재 저장되어 있는 숫자의 개수보다 적을 때는 변경할 수 없다.
 */
size_t IntegerStorage::increaseMaxCapacity(size_t num) {
    if (num < data.size()) { //만일 현재 저장되어 있는 숫자의 개수보다 적을 때는 변경할 수 없게 바로 리턴
        return -1;
    }
    std::cout << "기존 저장 최대 개수 : " << data.capacity() << " "; // 함수 동작 확인을 위한 문자열 출력
    //vector의 reserve 함수는 capa를 상향해주는 것에는 사용할 수 있지만, 줄이는 것에는 적용이 안되는 이슈
    //먼저 데이터의 사이즈에 맞게 줄인 후 다시 reserve를 활용
    //파라미터(num)가 데이터의 사이즈보다 항상 크다는 전제조건이 있기에, reserve는 항상 num으로 capa를 바꿔준다.
    data.shrink_to_fit();
    data.reserve(num);
    std::cout << "변경된 저장 최대 개수 : " << data.capacity() << " "; // 함수 동작 확인을 위한 문자열 출력
    return data.capacity(); // 바뀐 객체의 사이즈를 리턴
}
