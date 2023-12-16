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
    setOnlineUsersCount();

    // ������� �������������� ���������� �� ������-��������
    cout << "\n\t~~���������� �� ������-��������~~" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "�������� ��������: " << storeName << endl;
    cout << "����� ��������: " << storeAddress << endl;
    cout << "���� ��������: " << website << endl;
    cout << "Email ��������: " << store_email << endl;
    cout << "������� ��������: " << store_phone << endl;
    outputVinylRecordsShortList();
    cout << "���������� ������� ������: " << onlineUsersCount << endl;
    cout << "�������������� ������ ������:" << endl;
    for (size_t i = 0; i < supportedPaymentMethods.size(); ++i) {
        cout << i + 1 << ") " << supportedPaymentMethods[i] << endl;
    }
    cout << "-------------------------------------------" << endl;
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

// ���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
OnlineStore& OnlineStore::operator=(Store& other)
{
    if (this != &other) {
        // �������� ����� ������
        setStoreName(other.getStoreName());
        setStoreAddress(other.getStoreAddress());
        setVinylRecordsInStore(other.getVinylRecordsInStore());
        setEmployeesInStore(other.getEmployeesInStore());
    }
    return *this;
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
void OnlineStore::setOnlineUsersCount()
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

// ���������� ��������� << ��� ������ ���������� �� ������-��������
ostream& operator<<(ostream& os, OnlineStore& onlineStore)
{
    onlineStore.setOnlineUsersCount();

    // ������� �������������� ���������� �� ������-��������
    os << "\n\t~~���������� �� ������-��������~~" << endl;
    os << "-------------------------------------------" << endl;
    os << "�������� ��������: " << onlineStore.getStoreName() << endl;
    os << "����� ��������: " << onlineStore.getStoreAddress() << endl;
    os << "���� ��������: " << onlineStore.website << endl;
    os << "Email ��������: " << onlineStore.store_email << endl;
    os << "������� ��������: " << onlineStore.store_phone << endl;

    // ����� ���������� � ��������� ����������
    os << "��������� � �������:" << endl;
    int recordNumber = 1;
    VinylRecord* recordsBegin = onlineStore.getVinylRecordsInStore();
    VinylRecord* recordsEnd = recordsBegin + numRecords;
    for (VinylRecord* record = recordsBegin; record != recordsEnd; ++record) {
        if (record->getAlbumName() != "") {
            os << recordNumber << ") " << record->getAlbumName() << " - " << record->getArtist() << " (" << record->getQuantity() << " ��.)" << endl;
            recordNumber++;
        }
    }

    os << "���������� ������� ������: " << onlineStore.onlineUsersCount << endl;
    os << "�������������� ������ ������:" << endl;
    for (size_t i = 0; i < onlineStore.supportedPaymentMethods.size(); ++i) {
        os << i + 1 << ") " << onlineStore.supportedPaymentMethods[i] << endl;
    }
    os << "-------------------------------------------" << endl;

    return os;
}
