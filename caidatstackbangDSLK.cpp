#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
struct stack
{
    node* top;
};
void Init(stack& s) {
    s.top = NULL;
}
node* CreateNode(int x) {
    node* p= new node;
    if (p == NULL) {
        return NULL;
    }

    p->data = x;
    p->next = NULL;
    return p;
}
int IsEmpty(stack s) {
    if (s.top == NULL) {
        return 1;
    }
    return 0;
}
void Push(stack& s, int x) {
    node* NewNode = CreateNode(x);
    if (NewNode != NULL) {
        if (IsEmpty(s)) {
            s.top = NewNode;
        }
        else { 
            NewNode->next = s.top;
            s.top = NewNode;
        }
    }
}
void Pop(stack& s) {
    if (!IsEmpty(s)) {
        s.top = s.top->next;
    }
}
void Input(stack& s, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Push(s, x);
    }
}
void Output(stack s)
{
    node* p;
 
    for (p = s.top; p != NULL; p = p->next) {

        cout << p->data<<" ";
    }
    cout << endl;
}

int main() {
    stack s;
    Init(s);
    int n;
    cin >> n;
    Input(s, n);
    int x = 66;
    Push(s, x);
    Output(s);
    Pop(s);
    Output(s);
}