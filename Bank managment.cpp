#include <iostream>
#include <string>
using namespace std;

int main() {
    int accountnumber[5];
    string accountholder[5];
    float balances[5];
    float totaldeposited[5] = {0};
    float totalwithdrawn[5] = {0};
    int totalaccounts = 0;

    int choice, i;

    while (1) {
        cout << "\n--- Banking Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Account List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (totalaccounts >= 5) {
                    cout << "Account limit reached.\n";
                } else {
                    cout << "Enter your preferred account number: ";
                    cin >> accountnumber[totalaccounts];
                    cin.ignore();

                    cout << "Enter account holder name: ";
                    getline(cin, accountholder[totalaccounts]);

                    cout << "Enter initial deposit: ";
                    cin >> balances[totalaccounts];

                    totaldeposited[totalaccounts] = balances[totalaccounts];
                    cout << "Account created successfully.\n";
                    totalaccounts++;
                }
                break;

            case 2: {
                int accno;
                float amount;
                bool found = false;

                cout << "Enter Account number: ";
                cin >> accno;

                for (i = 0; i < totalaccounts; i++) {
                    if (accountnumber[i] == accno) {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        balances[i] += amount;
                        totaldeposited[i] += amount;
                        cout << "Deposit successful.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 3: {
                int accno;
                float amount;
                bool found = false;

                cout << "Enter Account number: ";
                cin >> accno;

                for (i = 0; i < totalaccounts; i++) {
                    if (accountnumber[i] == accno) {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        if (amount > balances[i]) {
                            cout << "Insufficient balance.\n";
                            return 0;
                        } else {
                            balances[i] -= amount;
                            totalwithdrawn[i] += amount;
                            cout << "Withdrawal successful.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                int pass;
                cout << "Enter your password to continue: ";
                cin >> pass;
                if (pass == 1234) {
                    cout << "\n--- Account List ---\n";
                    for (i = 0; i < totalaccounts; i++) {
                        cout << "Account number : " << accountnumber[i] << endl;
                        cout << "Holder Name    : " << accountholder[i] << endl;
                        cout << "Balance        : " << balances[i] << endl;
                        cout << "Total Deposited: " << totaldeposited[i] << endl;
                        cout << "Total Withdrawn: " << totalwithdrawn[i] << endl;
                        cout << "-----------------------------\n";
                    }
                } else {
                    cout << "Incorrect pass" << endl;
                }
                break;
            }

            case 5:
                cout << "Thank you for using the Banking Management System.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}