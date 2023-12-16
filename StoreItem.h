#pragma once

#include <string>
#include <iostream>
using namespace std;

// ����� ��� ������� "�������", ������� �������
// �� ������ ��������� ���������, �� ����� �������-����� � �������
template <typename T1, typename T2>
class StoreItem {

private:

	T1 itemName;
	T2 price;

public:

	// ���������� ��� ����������
	StoreItem() : itemName(), price() {}
	// ���������� � �����������
	StoreItem(T1 itemName, T2 price) : itemName(itemName), price(price) {}
	// ����������
	~StoreItem() {}

	// ����� ��� ������ ���������� � ������
	void displayInfo() {
		cout << "�����: " << itemName << ", ����: " << price << " ���." << endl;
	}
};
