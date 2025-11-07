#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(NULL) {}
};

// Function to add two polynomials
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 && poly2) {
        Node* temp = NULL;

        if (poly1->pow == poly2->pow) {
            temp = new Node(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->pow > poly2->pow) {
            temp = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else {
            temp = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        if (!result) {
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add remaining nodes
    while (poly1) {
        Node* temp = new Node(poly1->coeff, poly1->pow);
        tail->next = temp;
        tail = temp;
        poly1 = poly1->next;
    }
    while (poly2) {
        Node* temp = new Node(poly2->coeff, poly2->pow);
        tail->next = temp;
        tail = temp;
        poly2 = poly2->next;
    }

    return result;
}

// Helper function to print polynomial
void printPoly(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        if (poly->next) cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    // Example: 5x^2 + 4x + 2
    Node* poly1 = new Node(5,2);
    poly1->next = new Node(4,1);
    poly1->next->next = new Node(2,0);

    // Example: 5x^1 + 5
    Node* poly2 = new Node(5,1);
    poly2->next = new Node(5,0);

    cout << "First polynomial: ";
    printPoly(poly1);

    cout << "Second polynomial: ";
    printPoly(poly2);

    Node* result = addPoly(poly1, poly2);

    cout << "Sum of polynomials: ";
    printPoly(result);

    return 0;
}