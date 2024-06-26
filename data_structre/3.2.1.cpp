#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};



class LinkedList 
{
    // Todo: some variables here
private:
    node* head;
    int total = 0;
public:
    void initialize() 
    {
        int n;
        scanf("%d", &n);
        head = new node;
        node* tail = head;
        total = n;
        head->next = tail;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
        {
            tail->next = new node;
            scanf("%d", &a[i]);
            tail = tail->next;
            tail->data = a[i];
            tail->next = nullptr;
        }
        // Todo

        delete[] a;
    }

    void insert(int i, int x) 
    {
        // Todo
        node* p;
        p = head;
        while (i--)
        {
            p = p->next;
        }
        node* tmp=new node;
        tmp->data = x;
        tmp->next = p->next;
        p->next = tmp;
        total++;
    }

    void eraseFromHead(int i) 
    {
        // Todo
        node* p;
        p = head;
        while (p&&(--i))
        {
            p = p->next;
        }
        if (!p)return;
        node* tmp;
        tmp = p->next;
        if (!tmp)return;
        p->next = tmp->next;
        total--;
    }

    void eraseFromEnd(int i) 
    {
        // Todo
        eraseFromHead(total - i+1);
    }

    void printAll() 
    {
        // Todo
        node* tmp ;
        tmp = head->next;
        while (total--)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void ClearMemory() 
    {
        // Todo
        node* p, * q;
        p = head->next;
        head->next = nullptr;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }
};

int main() 
{
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        }
        else if (op == 2) {
            scanf("%d", &i);
            List.eraseFromHead(i);
        }
        else if (op == 3) {
            scanf("%d", &i);
            List.eraseFromEnd(i);
        }
    }
    List.printAll();
    List.ClearMemory();
    return 0;
}