#include <iostream>
using namespace std;

//Constants
const int MAX_TRANSACTIONS = 50;

//Declare arrays
int transactionNo[MAX_TRANSACTIONS];
string cookieType[MAX_TRANSACTIONS];
int quantitySold[MAX_TRANSACTIONS];
double pricePerUnit[MAX_TRANSACTIONS];
string customerName[MAX_TRANSACTIONS];

//Function Prototypes
void recordSales();
double calculateTotalRevenue();
void displaySalesRecords();
void findSalesByCustomer();
void updateSalesRecord();


int main() {
    //User interface
    int choice;
    do {
        cout << "===== Cookie Sales Management System for the Hari Raya Aidilfitri =====\n";
        cout << "1. Record Sales\n";
        cout << "2. Calculate Total Revenue\n";
        cout << "3. Display Sales Records\n";
        cout << "4. Find Sales by Customer\n";
        cout << "5. Update Sales Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            recordSales();
        } else if (choice == 2) {
            cout << "Total Revenue: RM" << calculateTotalRevenue() << endl;
        } else if (choice == 3) {
            displaySalesRecords();
        } else if (choice == 4) {
            findSalesByCustomer();
        } else if (choice == 5) {
            updateSalesRecord();
        } else if (choice == 6) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void recordSales() {
    static int transactionCounter = 0;
    if (transactionCounter >= MAX_TRANSACTIONS) {
        cout << "Maximum transactions reached.\n";
        return;
    }

    cout << "Enter cookie type: ";
    cin >> cookieType[transactionCounter];
    cout << "Enter quantity sold: ";
    cin >> quantitySold[transactionCounter];
    cout << "Enter price per unit: RM";
    cin >> pricePerUnit[transactionCounter];
    cout << "Enter customer name: ";
    cin >> customerName[transactionCounter];

    transactionNo[transactionCounter] = transactionCounter + 1; //Assign transaction number
    transactionCounter++;
}

double calculateTotalRevenue() {
    double totalRevenue = 0;
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        totalRevenue += quantitySold[i] * pricePerUnit[i];
    }
    return totalRevenue;
}

void displaySalesRecords() {
    cout << "===== Sales Records =====\n";
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (transactionNo[i] != 0) {
            cout << "Transaction No: " << transactionNo[i] << endl;
            cout << "Cookie Type: " << cookieType[i] << endl;
            cout << "Quantity Sold: " << quantitySold[i] << endl;
            cout << "Price Per Unit: RM" << pricePerUnit[i] << endl;
            cout << "Customer Name: " << customerName[i] << endl;
            cout << "Total Revenue: RM" << quantitySold[i] * pricePerUnit[i] << endl;
            cout << "------------------------\n";
        }
    }
}

void findSalesByCustomer() {
    string targetCustomer;
    cout << "Enter customer name to search for: ";
    cin >> targetCustomer;

    cout << "===== Sales Records for Customer: " << targetCustomer << " =====\n";
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (customerName[i] == targetCustomer) {
            cout << "Transaction No: " << transactionNo[i] << endl;
            cout << "Cookie Type: " << cookieType[i] << endl;
            cout << "Quantity Sold: " << quantitySold[i] << endl;
            cout << "Price Per Unit: RM" << pricePerUnit[i] << endl;
            cout << "Total Revenue: RM" << quantitySold[i] * pricePerUnit[i] << endl;
            cout << "------------------------\n";
        }
    }
}

void updateSalesRecord() {
    int transactionToUpdate;
    cout << "Enter transaction number to update: ";
    cin >> transactionToUpdate;
    
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (transactionNo[i] == transactionToUpdate) {
            cout << "Enter new cookie type (or enter '-' to keep unchanged): ";
            cin >> cookieType[i];
            cout << "Enter new quantity sold (or enter -1 to keep unchanged): ";
            cin >> quantitySold[i];
            cout << "Enter new price per unit (or enter -1 to keep unchanged): RM";
            cin >> pricePerUnit[i];
            cout << "Enter new customer name (or enter '-' to keep unchanged): ";
            cin >> customerName[i];
            cout << "Record updated successfully.\n";
            return;
        }
    }
    cout << "Transaction not found.\n";
}
