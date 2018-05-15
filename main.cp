#include <iostream>
#include "AVLTree.h"

using namespace std;
int main() {
    AVLTree a;

    cout << "isFull:" << a.isFull();
    cout << endl;
    cout << "isEmpty:" << a.isEmpty();
    cout << endl;
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    a.append(6);
    a.append(2000);
    a.append(7);
    a.append(8);
    a.append(9);
    a.append(10);
    a.remove(10);
    a.print();

    cout << endl;
    cout << "Found number:" << a.find(3);
    cout << endl;
    cout << "Found number:" << a.find(0);
    cout << endl;
    cout << endl;
    cout << "isFull:" << a.isFull();
    cout << endl;
    cout << "isEmpty:" << a.isEmpty();
    cout << endl;

    a.remove(6);
    a.remove(4);
    a.remove(7);
    a.remove(8);
    a.remove(2);
    a.print();
    cout << endl;
    a.print();
    cout << endl;
    a.print();
    cout << endl;


    //a.append(1);
    //a.append(3);
    //cout << a.isFull();
    //cout << a.isEmpty();
    //cout << a.find(2) << endl;
    //a.clear();
    //a.print();

    //cout << a.find(2);
    //a.print();
    a.clear();
    a.print();
    //a.print();

}