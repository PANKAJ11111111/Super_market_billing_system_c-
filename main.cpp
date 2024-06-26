#include <bits/stdc++.h>
using namespace std;

class Bill {
private:
    int Rate;
    string ProductName;
    int Quantity; // Corrected spelling
    int Discount;

public:
    Bill() {
        Rate = 0;
        ProductName = "";
        Quantity = 0; // Corrected spelling
        Discount = 0;
    }

    void setRate(int r) {
        Rate = r;
    }

    void setProductName(string pn) {
        ProductName = pn;
    }

    void setQuantity(int q) { // Corrected spelling
        Quantity = q;
    }

    void setDiscount(int d) {
        Discount = d;
    }

    string getProductName() {
        return ProductName;
    }

    int getRate() {
        return Rate;
    }

    int getQuantity() { // Corrected spelling
        return Quantity;
    }

    int getDiscount() {
        return Discount;
    }
};

void add(Bill &b) { 
    cout<<endl<<endl;
    bool close = false;

    while (!close) {
        int choice;
        
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t 1. ADD ITEM \t\t" << endl;
        cout << "\t\t 2. CLOSE \t\t" << endl << endl;

        cout << "\t\t ENTER OPTION \t = ";
        cin >> choice;
        cout<<endl;

        if (choice == 1) {
            string itemname;
            int itemrate;
            int itemquantity; // Corrected spelling
            int itemdiscount;

            cout << "1. ENTER PRODUCT NAME  = " ;
            cin >> itemname;
            b.setProductName(itemname); // Corrected function call
            cout << "2. ENTER PRODUCT RATE = " ;
            cin >> itemrate;
            b.setRate(itemrate); // Corrected function call
            cout << "3. ENTER PRODUCT QUANTITY = " ;
            cin >> itemquantity;
            b.setQuantity(itemquantity); // Corrected function call and spelling
            cout << "4. ENTER PRODUCT DISCOUNT = " ;
            cin >> itemdiscount;
            b.setDiscount(itemdiscount); // Corrected function call
             
            ofstream out("super_market_billing.txt", ios::app); // Corrected file path
            
            if (!out) {
                cout<<endl;
                cout << "\t FILE NOT OPEN " << endl;
            } else {
                out << b.getProductName() << " " << b.getRate() << " " << b.getQuantity() << " " << b.getDiscount() << endl;
            }

            out.close();
            cout<<endl;
            cout << "\t ITEM ADD SUCCESSFULLY" << endl << endl;
           
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\t BACK TO MAIN MENU " << endl<<endl;
            
        }
    }
}

void printbill(Bill &b) {
    ifstream in("super_market_billing.txt");

    if (!in) {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    double totalAmount = 0.0;

    cout << "-------------------- BILL --------------------" << endl;
    cout << left << setw(20) << "Product Name" << setw(10) << "Rate" << setw(10) << "Quantity" << setw(10) << "Discount" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------------------" << endl;

    while (getline(in, line)) {
        istringstream iss(line);
        string productName;
        int rate, quantity, discount;

        if (!(iss >> productName >> rate >> quantity >> discount)) {
            continue; // Skip the line if parsing fails
        }

        double price = (rate * quantity) * (1 - discount / 100.0);
        totalAmount += price;

        cout << left << setw(20) << productName << setw(10) << rate << setw(10) << quantity << setw(10) << discount << setw(10) << price << endl;
    }

    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(50) << "Total Amount: " << totalAmount << endl;
    cout << "----------------------------------------------" << endl;

    in.close();
}

int main() {
    cout<<endl<<endl;
    Bill B;

    bool exit = false;

    while (!exit) {
        int val;

        cout << "\t************************ WELCOME TO BILLING SYSTEM ***************************** \t" << endl << endl;

        cout << "\t\t 1. ADD ITEM \t\t" << endl;
        cout << "\t\t 2. GENERATE BILL \t\t" << endl; // Corrected spelling
        cout << "\t\t 3. EXIT \t\t" << endl << endl;

        cout << "\t\t SELECT OPTION \t = ";

        cin >> val;

        if (val == 1) {
            add(B);
        } else if(val == 2) {
            printbill(B);
        } else if (val == 3) {
            exit = true;
        }
    }
    return 0;
}
