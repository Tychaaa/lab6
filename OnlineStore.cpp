#include "OnlineStore.h"

// ���������� ��� ����������
OnlineStore::OnlineStore() : Store(), website(""), store_email(""), store_phone(""), onlineUsersCount(0) {}

// ���������� � �����������
OnlineStore::OnlineStore(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray, const vector<string>& paymentMethods,
    string website, string storeEmail, string storePhone)
    : Store(name, address, vinylRecordsArray, employeeArray), supportedPaymentMethods(paymentMethods),
    website(website), store_email(storeEmail), store_phone(storePhone)
{
    onlineUsersCount = 0;
}

// ����������
OnlineStore::~OnlineStore() {}

// ����������� ������ ��� ������ ���������� � ��������-��������
void OnlineStore::outputStore()
{
    Store::outputStore(); // �������� ����� �������� ������

    // ������� �������������� ���������� �� ������-��������
    cout << "\n\t~~���������� �� ������-��������~~" << endl;
    cout << "���� ��������: " << website << endl;
    cout << "Email ��������: " << store_email << endl;
    cout << "������� ��������: " << store_phone << endl;
    cout << "���������� ������� ������: " << onlineUsersCount << endl;

    cout << "�������������� ������ ������: ";
    for (const auto& method : supportedPaymentMethods) {
        cout << method << ", ";
    }
    cout << endl;
}

// ����� ��� ��������� ���������� ���������� ������������� ������
int OnlineStore::generateRandomUsersCount()
{
    int onlineUsers;

    random_device rd;  // �������� ��������
    mt19937 gen(rd()); // ��������� ��������� �����
    uniform_int_distribution<> dist(1, 1000); // ����������� ������������� �� 1 �� 1000

    onlineUsers = dist(gen);
    
    return onlineUsers;
}

// ����� ��� ��������� �������� ��������
void OnlineStore::setWebsite(string newWebsite)
{
    website = newWebsite;
}

// ����� ��� ��������� ����������� �����
void OnlineStore::setStoreEmail(string newStoreEmail)
{
    store_email = newStoreEmail;
}

// ����� ��� ��������� ������ ��������
void OnlineStore::setStorePhone(string newStorePhone)
{
    store_phone = newStorePhone;
}

// ����� ��� ��������� ���������� ������� ������
void OnlineStore::setOnlineUsersCount(int count)
{
    onlineUsersCount = generateRandomUsersCount();
}

// ����� ��� ��������� �������� ������
void OnlineStore::setSupportedPaymentMethods(vector<string>& methods)
{
    supportedPaymentMethods = methods;
}

// ����� ��� ��������� �������� ��������
const string OnlineStore::getWebsite()
{
    return website;
}

// ����� ��� ��������� ����������� �����
const string OnlineStore::getStoreEmail()
{
    return store_email;
}

// ����� ��� ��������� ������ ��������
const string OnlineStore::getStorePhone()
{
    return store_phone;
}

// ����� ��� ��������� ���������� ������� ������
const int OnlineStore::getOnlineUsersCount()
{
    return onlineUsersCount;
}

// ����� ��� ��������� �������� ������
const vector<string>& OnlineStore::getSupportedPaymentMethods()
{
    return supportedPaymentMethods;
}