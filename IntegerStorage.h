//
// Created by PC_1M on 2024-11-09.
//
/*
 * ������ �����ϴ� ��ü�� ����� ���� Ŭ������ ����
 * C++ ���α׷���
 * 2024.11.04
 * ������ 202334-364307
 */

#ifndef MYFIRSTC__PROJECT_INTEGERSTORAGE_H
#define MYFIRSTC__PROJECT_INTEGERSTORAGE_H

#include <iostream>
#include <vector>

using namespace std;

class IntegerStorage {
private:
    std::vector<int> data; // ������ ������ ����. �迭�� ���̰� �������̶� ���
    size_t maxSize; // �ִ� ����. ������ ��ü�� �ִ��� ��ü ������ �� ���ؾ� �ϱ⿡ (2��� Ȥ�� �ʿ�� ����) const ������ ���� ����

public:
    explicit IntegerStorage(size_t maxCount); // ������ ����
    ~IntegerStorage(); // �Ҹ��� ����
    size_t add(int value); // ������ �߰��ϴ� �Լ�
    size_t afterPrint(); //���� ���� �� �������� ȣ���� �Լ�. ������ ���� ��ü�� ���� ������ üũ
    int printOldestData(); //���� �������� ������ ���ڸ� ����
    int printLatestData(); // ���������� ������ ���� ����
    int printBiggestData(); // ����� ���� �� ���� ū �� ����
    int printSmallestData(); // ����� ���� �� ���� ���� �� ����
    int printAverageData(); // ��ü�� ����� ���ڵ��� ��� ����
    size_t increaseMaxCapacity(size_t num);//��ü�� ������ �� �ִ� ������ �ִ� ������ ����
};

#endif //MYFIRSTC__PROJECT_INTEGERSTORAGE_H



