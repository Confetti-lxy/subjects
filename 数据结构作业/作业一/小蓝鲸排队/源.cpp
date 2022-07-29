#include <iostream>

using namespace std;

struct node {
    int number = 0;
    bool left_bool = 1, right_bool = 1;
    node *left = NULL;
    node *right = NULL;
};

node *create_node(int n);

node *create(int x);

node *find(node *head, int i);

int main() {
    int number, count, start;
    cin >> number >> count >> start;
    node *head = create(number);
    node *first1 = find(head, start);
    node *first2 = find(head, start);
    int x1 = number, x2 = number;
    while (x1 != 0) {
        for (int i = 1; i < count;) {
            first1 = first1->right;
            if (first1->right_bool == 1)
                i++;
        }
        first1->right_bool = 0;
        cout << first1->number << " ";
        x1--;
        while (first1->right_bool == 0 && x1 != 0) {
            first1 = first1->right;
        }
    }
    cout << endl;
    while (x2 != 0) {
        for (int i = 1; i < count;) {
            first2 = first2->left;
            if (first2->left_bool == 1)
                i++;
        }
        first2->left_bool = 0;
        cout << first2->number << " ";
        x2--;
        while (first2->left_bool == 0 && x2 != 0) {
            first2 = first2->left;
        }
    }
    cout << endl;
}

node *create_node(int n) {
    node *p = new node;
    p->number = n;
    p->left = p;
    p->right = p;
    return p;
}

node *create(int x) {
    node *p = create_node(1);
    node *head = p;
    for (int i = 2; i <= x; i++) {
        node *q = create_node(i);
        q->right = p->right;
        p->right = q;
        q->right->left = q;
        q->left = p;
        p = q;
    }
    return head;
}

node *find(node *head, int i) {
    node *p = head;
    int x = 1;
    while (x != i && p != NULL) {
        p = p->right;
        x++;
    }
    if (p != NULL)
        return p;
    else
        return NULL;
}