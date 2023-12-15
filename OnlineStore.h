#pragma once
#include "Store.h"

#include <vector>
#include <random>
using namespace std;

extern int numRecords;

class OnlineStore :
    public Store
{
private:

    string website;
    string store_email;
    string store_phone;
    int onlineUsersCount;
    vector<string> supportedPaymentMethods;

public:

    // ���������� ��� ����������
    OnlineStore();
    // ���������� � �����������
    OnlineStore(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray, const vector<string>& paymentMethods,
        string website, string storeEmail, string storePhone);
    // ����������
    ~OnlineStore();

    // ����� ��� ������ ���������� � ��������
    void outputStore() override;

    // ���������� ��������� << ��� ������ ���������� �� ������-��������
    friend ostream& operator<<(ostream& os, OnlineStore& onlineStore);

    // ����� ��� ��������� ���������� ���������� ������������� ������
    int generateRandomUsersCount();

    // ���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
    OnlineStore& operator=(Store& other);

    // ������� ��� ������
    void setWebsite(string newWebsite);
    void setStoreEmail(string newStoreEmail);
    void setStorePhone(string newStorePhone);
    void setOnlineUsersCount();
    void setSupportedPaymentMethods(vector<string>& methods);

    // ������� ��� ������
    const string getWebsite();
    const string getStoreEmail();
    const string getStorePhone();
    const int getOnlineUsersCount();
    const vector<string>& getSupportedPaymentMethods();
};

