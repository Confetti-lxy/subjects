#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

void calculate(node *l1, node *l2, int add);

node *ans = new node;
node *ans1 = ans;
node *head = ans;

int main() {
    node *p1 = new node;
    node *p2 = new node;
    node *a = p1;
    node *b = p2;
    int m = 0, n = 0;
    while (m != -1) {
        cin >> m;
        if (m != -1) {
            p1->data = m;
            p1->next = new node;
            p1 = p1->next;
        } else {
            p1->data = -1;
            p1->next = NULL;
        }
    }
    while (n != -1) {
        cin >> n;
        if (n != -1) {
            p2->data = n;
            p2->next = new node;
            p2 = p2->next;
        } else {
            p2->data = -1;
            p2->next = NULL;
        }
    }
    if (a->data == -1 && b->data == -1)
        return 0;
    calculate(a, b, 0);
    node *answer = head;
    if (head == NULL)
        return -1;
    while (answer != NULL) {
        cout << answer->data << " ";
        answer = answer->next;
    }
}

void calculate(node *a, node *b, int add) {
    if (a->next == NULL && b->next == NULL) {
        if (add != 0)
            ans->data += add;
        else {
            ans1->next = NULL;
            delete ans;
        }
        return;
    }
    if (a->next == NULL && b->next != NULL) {
        int temp = b->data;
        if (add != 0) {
            temp += add;
            add = 0;
        }
        if (temp >= 10) {
            ans->data = temp % 10;
            add++;
        } else {
            ans->data = temp;
        }
        ans->next = new node;
        ans1 = ans;
        ans = ans->next;
        calculate(a, b->next, add);
    }
    if (b->next == NULL && a->next != NULL) {
        int temp = a->data;
        if (add != 0) {
            temp += add;
            add = 0;
        }
        if (temp >= 10) {
            ans->data = temp % 10;
            add++;
        } else {
            ans->data = temp;
        }
        ans->next = new node;
        ans1 = ans;
        ans = ans->next;
        calculate(a->next, b, add);
    }
    if (a->next != NULL && b->next != NULL) {
        int temp = a->data + b->data;
        if (add != 0) {
            temp += add;
            add = 0;
        }
        if (temp >= 10) {
            ans->data = temp % 10;
            add++;
        } else {
            ans->data = temp;
        }
        ans->next = new node;
        ans1 = ans;
        ans = ans->next;
        calculate(a->next, b->next, add);
    }
}