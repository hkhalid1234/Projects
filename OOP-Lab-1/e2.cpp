#include <iostream>
#include <vector>

using namespace std;

class WareHouse{
private:
    vector<int> code;
    vector<int> quantity;
public:
    void stock(int c , int q){

        for (int i = 0; i < code.size(); i++){
            if (code[i] == c){
                code[i] = c;
                quantity[i] += q;
                cout << q << " more items with code " << c << " added , total " << quantity[i] << endl;
                return;
            }
        }
        code.push_back(c);
        quantity.push_back(q);
        cout << q << " items with code " << c << " added" << endl;
    }
    void order(int c, int q){
        for (int i = 0; i < code.size(); i++){
            if (c == code[i]){
                if (quantity[i] - q >= 0) {
                    quantity[i] -= q;
                    cout << q << " items delivered with code " << c << endl;
                    return;
                }
                else
                    cout << "the requested quantity is not available" << endl;
            }
        }
        cout << "Code " << c << " not found" << endl;
    }
    void show(int c){
        for (int i = 0; i < code.size(); i++){
            if (code[i] == c) {
                cout << quantity[i] << " items are stored with code " << c << endl;
                return;
            }
        }
        cout << "Code " << c << " not found" << endl;
    }
};

int main() {
    WareHouse w;
    w.stock(1, 10); // print "10 items with code 1 added"
    w.stock(2, 20); // print "20 items with code 2 added"
    w.stock(3, 30); // print "30 items with code 3 added"
    w.stock(1, 5); // print "5 more items with code 1 added, total 15"
    w.order(1, 3); // print "3 items delivered with code 1"
    w.order(2, 25); // print "the requested quantity is not available"
    w.order(2, 11); // print "11 items delivered with code 2"
    w.order(4, 5); // print "Code 4 not found"
    w.show(1); // print "12 items are stored with code 1"
    w.show(2); // print "9 items are stored with code 2"
    w.show(3); // print "30 items are stored with code 3"
    w.show(4); // print "Code 4 not found"
    return 0;
}