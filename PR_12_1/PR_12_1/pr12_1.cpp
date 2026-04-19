#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Node {
    int data;
    Node* p1; 
    Node* p2; 
};

void describeStructure(Node* n1, Node* n2, Node* n3, Node* n4) {
    Node* nodes[] = { n1, n2, n3, n4 };
    cout << "--- Опис структури зв'язків ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Вузол " << nodes[i]->data << ":" << endl;
        cout << "  p1 вказує на вузол " << (nodes[i]->p1 ? to_string(nodes[i]->p1->data) : "NULL") << endl;
        cout << "  p2 вказує на вузол " << (nodes[i]->p2 ? to_string(nodes[i]->p2->data) : "NULL") << endl;
    }
    cout << "-------------------------------" << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Node* n1 = new Node{ 1, nullptr, nullptr };
    Node* n2 = new Node{ 2, nullptr, nullptr };
    Node* n3 = new Node{ 3, nullptr, nullptr };
    Node* n4 = new Node{ 4, nullptr, nullptr };

    Node* p = n1;

    n1->p1 = n2;
    n1->p2 = n4;

    n2->p1 = n3;
    n2->p2 = n4;

    n3->p1 = n2;
    n3->p2 = n1;

    n4->p1 = n2;
    n4->p2 = n3;

    describeStructure(n1, n2, n3, n4);

    delete n1;
    delete n2;
    delete n3;
    delete n4;

    p = nullptr;

    cout << "Структуру успішно побудовано, описано та видалено з пам'яті." << endl;

    return 0;
}