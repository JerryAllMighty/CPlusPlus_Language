#include <iostream>
#include "IntegerStorage.h"

int main() {
    //① 저장할 수 있는 정수의 최대 개수는 객체가 생성될 때 지정한다.
    IntegerStorage integerStorage(4); // 클래스 객체 생성
    // integerStorage.test();
    //② 정수를 저장할 수 있다. 만일 객체가 가득 찬 상태면 저장 공간을 2배 확장한다.
    integerStorage.add(2);
    integerStorage.add(22);
    integerStorage.add(25);
    integerStorage.add(3);

    //③ 다음의 방법으로 정수를 인출할 수 있다.
    // 인출 후 빈 공간이 전체의 3/4 이상이면 저장 공간을 줄인다. 줄어든 저장 공간의 크기는 ①에서 지정된 크기와 현재 공간의 1/2 중 큰 것으로 한다.
    // 초기화 크기 4: 데이터 16개까지 늘려서 capa를 16으로 만든 후, 4개가 인출된 시점부터 데이터 저장 공간 리사이징 확인 가능
    //㈀ 가장 오래전에 저장한 숫자를 인출할 수 있다.
//    integerStorage.printOldestData();

    //㈁ 마지막으로 저장한 숫자를 인출할 수 있다.
//    integerStorage.printLatestData();
    //㈂ 저장된 숫자 중 가장 큰 값을 인출할 수 있다. (최댓값이 2개 이상이면 그중 가장 오래전에 저장한 숫자를 인출함)
//    integerStorage.printBiggestData();
    //㈃ 저장된 숫자 중 가장 작은 값을 인출할 수 있다. (최솟값이 2개 이상이면 그중 가장 오래전에 저장한 숫자를 인출함)
//    integerStorage.printSmallestData();
    //⑦ 객체에 저장된 숫자들의 평균을 구할 수 있다.
//    integerStorage.printAverageData();
    //⑧ 객체에 저장할 수 있는 숫자의 최대 개수를 변경한다. 만일 현재 저장되어 있는 숫자의 개수보다 적을 때는 변경할 수 없다.
//    integerStorage.increaseMaxCapacity(38);
}
