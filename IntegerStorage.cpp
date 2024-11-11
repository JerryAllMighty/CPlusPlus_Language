//
// Created by PC_1M on 2024-11-09.
//
/*
 * ������ �����ϴ� ��ü�� ����� ���� Ŭ������ ����
 * C++ ���α׷���
 * 2024.11.04
 * ������ 202334-364307
 */

#include "IntegerStorage.h"
#include <iostream>
#include <vector>

using namespace std;

/*
 * ������ �� �ִ� ������ �ִ� ������ ��ü�� ������ �� �����Ѵ�.
 * �����ڿ��� �ִ� ���� ����
 * maxCount�� ���� �޾Ƽ�, ������� maxSize�� �� ���� ����.
*/
IntegerStorage::IntegerStorage(size_t maxCount) : maxSize(maxCount) {
    data.reserve(maxCount); // ������ ���� ��ü�� ũ�⵵ �Բ� ����
}

IntegerStorage::~IntegerStorage() {
    data.clear(); // ��� ��� ����. �޸𸮴� ������ ���� ����
    data.shrink_to_fit(); //���� �޸� ��ȯ
}

/*
 * ������ �߰��ϴ� �Լ�
 * ���� ��ü�� ���� �� ���¸� ���� ������ 2�� Ȯ���Ѵ�.
 */
size_t IntegerStorage::add(int value) {
    size_t currentSize = data.capacity(); //���� ������ ���� ��ü�� �뷮�� ��� ����
    if (data.size() == currentSize) { //��ü�� ���� �� �������� üũ
        data.reserve(currentSize * 2); //�����͸� �����ϴ� ������ ũ�⸦ 2�� Ȯ��
        std::cout << "���� ������ �����Ͽ� " << currentSize * 2 << " ũ��� Ȯ��Ǿ����ϴ�.\n"; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    }
    data.push_back(value); //���Ϳ� ������ �߰�
    std::cout << "�����͸� �����Ͽ����ϴ�." << value << "\n"; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    return data.capacity();
}


/*
 * ���� ���� �� �������� ȣ���� �Լ�.
 * ���� �� �� ������ ��ü�� 3/4 �̻��̸� ���� ������ ���δ�.
 * �پ�� ���� ������ ũ��� ������ ũ��� ���� ������ 1/2 �� ū ������ �Ѵ�.
 */
size_t IntegerStorage::afterPrint() {
    int emptySize = data.capacity() - data.size(); //���� �� ���� ũ�� ������ ���
    if (emptySize >= (data.capacity() * 0.75)) { // ���� �� �� ������ ��ü�� 3/4 �̻����� üũ
        int newMaxSize = maxSize; //���Ӱ� �Ҵ��� ��������� ũ�⸦ ����ϴ� ����
        if (maxSize < (data.capacity() * 0.5)) { //������ ũ��� ���� ������ 1/2 �� ū ���� ã�´�
            newMaxSize = (data.capacity() * 0.5); //���� ������ 1/2�� �� ũ�ٸ� ������ ���� ��´�.
        }
        //vector�� reserve �Լ��� capa�� �������ִ� �Ϳ��� ����� �� ������, ���̴� �Ϳ��� ������ �ȵǴ� �̽�
        //���� �������� ����� �°� ���� �� �ٽ� reserve�� Ȱ��
        data.shrink_to_fit();
        data.reserve(newMaxSize);

        std::cout << "���� �� �� ������ ��ü�� 3/4 �̻��̾� ���� ������"<< data.capacity() <<  "�� �پ����ϴ�.\n"; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    }
    return data.capacity();
}

/*
 * ���� �������� ������ ���ڸ� ������ �� �ִ�.
 */
int IntegerStorage::printOldestData() {
    int result = data[0]; //���ϰ��� �� ����. ���� ó���� ���� ��´�.
    std::cout << "���� �������� ������ ���� : " << data[0] << "\n"; // �ش� �� Ȯ�� �Լ�
    data.erase(data.begin()); // ���Ϳ��� �ش��ϴ� �� ����
    afterPrint(); // ���� �� ���� ���� üũ�ϴ� �Լ�
    return result; // �� ��ȯ
}
/*
 * ���������� ������ ���ڸ� ������ �� �ִ�.
 */
int IntegerStorage::printLatestData() {
    int result = data[data.capacity() - 1]; //���ϰ��� �� ����. ���� �ֱ��� ���� ��´�.
    std::cout << "���������� ������ ���� : " << data[data.capacity() - 1]  << "\n"; // �ش� �� Ȯ�� �Լ�
    data.pop_back(); // ���Ϳ��� �ش��ϴ� �� ����
    afterPrint(); // ���� �� ���� ���� üũ�ϴ� �Լ�
    return result; // �� ��ȯ
}

/*
 * ����� ���� �� ���� ū ���� ������ �� �ִ�.
 * (�ִ��� 2�� �̻��̸� ���� ���� �������� ������ ���ڸ� ������)
 */
int IntegerStorage::printBiggestData() {
    int maxNum = -2147483648; //���ϰ��� �� ����. ���� ū ���� ��� ����. �񱳸� ���� ���� ���� int�� ���� �Ҵ�
    vector<int> maxNumIdxList; //���ϰ��� �ϴ� ���� 2�� �̻��� �� �ֱ⿡, �̸� ���ϱ� ���� �迭�� �ε����� �����ϴ� �뵵�� ����
    for (int i = 0; i < data.size(); i++) { // ���� ū ���� ã�� ����
        int num = data[i];
        if (num > maxNum) {
            maxNum = num;
        }
    }
    for (int i = 0; i < data.size(); i++) { // ã�� �ִ��� �ε������� ���Ϳ� �����ϴ� ����
        int num = data[i];
        if (num == maxNum) {
            maxNumIdxList.push_back(i);
        }
    }
    data.erase(data.begin() + maxNumIdxList[0]); // �ش� �ִ��� ���Ϳ��� �����ش�
    std::cout << "����� ���� �� ���� ū �� : " << maxNum  << "\n"; // �ش� �� Ȯ�� �Լ�
    afterPrint(); // ���� �� ���� ���� üũ�ϴ� �Լ�
    return maxNum; // �� ����
}

/*
 * ����� ���� �� ���� ���� ���� ������ �� �ִ�.
 * (�ּڰ��� 2�� �̻��̸� ���� ���� �������� ������ ���ڸ� ������)
 */
int IntegerStorage::printSmallestData() {
    int minNum = 2147483647;  //���ϰ��� �� ����. ���� ���� ���� ��� ����. �񱳸� ���� ���� ū int�� ���� �Ҵ�
    vector<int> minNumIdxList; //���ϰ��� �ϴ� ���� 2�� �̻��� �� �ֱ⿡, �̸� ���ϱ� ���� �迭�� �ε����� �����ϴ� �뵵�� ����
    for (int i = 0; i < data.size(); i++) {
        int num = data[i];
        if (num < minNum) {
            minNum = num;
        }
    }
    for (int i = 0; i < data.size(); i++) { // ã�� �ּڰ��� �ε������� ���Ϳ� �����ϴ� ����
        int num = data[i];
        if (num == minNum) {
            minNumIdxList.push_back(i);
        }
    }
    data.erase(data.begin() + minNumIdxList[0]); // �ش� �ּڰ��� ���Ϳ��� �����ش�
    std::cout << "����� ���� �� ���� ���� �� : " << minNum  << "\n"; // �ش� �� Ȯ�� �Լ�
    afterPrint(); // ���� �� ���� ���� üũ�ϴ� �Լ�
    return minNum;  // �� ����
}


/*
 * ��ü�� ����� ���ڵ��� ����� ���� �� �ִ�.
 */
int IntegerStorage::printAverageData() {
    int result = 0; // ��� ���� ���� ����
    int total = 0; // ��ü �ջ� ���� ���� ����
    for (int num: data) {
        total += num;
    }
    result = total / data.size(); // ��ü �ջ� ���� ��ü ����� ������ ��� �����
    std::cout << "��� �� : " << result << "\n"; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    afterPrint(); // ���� �� ���� ���� üũ�ϴ� �Լ�
    return result;

}

/*
 * ��ü�� ������ �� �ִ� ������ �ִ� ������ �����Ѵ�.
 * ���� ���� ����Ǿ� �ִ� ������ �������� ���� ���� ������ �� ����.
 */
size_t IntegerStorage::increaseMaxCapacity(size_t num) {
    if (num < data.size()) { //���� ���� ����Ǿ� �ִ� ������ �������� ���� ���� ������ �� ���� �ٷ� ����
        return -1;
    }
    std::cout << "���� ���� �ִ� ���� : " << data.capacity() << " "; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    //vector�� reserve �Լ��� capa�� �������ִ� �Ϳ��� ����� �� ������, ���̴� �Ϳ��� ������ �ȵǴ� �̽�
    //���� �������� ����� �°� ���� �� �ٽ� reserve�� Ȱ��
    //�Ķ����(num)�� �������� ������� �׻� ũ�ٴ� ���������� �ֱ⿡, reserve�� �׻� num���� capa�� �ٲ��ش�.
    data.shrink_to_fit();
    data.reserve(num);
    std::cout << "����� ���� �ִ� ���� : " << data.capacity() << " "; // �Լ� ���� Ȯ���� ���� ���ڿ� ���
    return data.capacity(); // �ٲ� ��ü�� ����� ����
}
