#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

Elem* L = NULL;

void Insert(Elem*& L, Info value);
void insertAfter(Elem*& L, Elem* first, Info supposed);
void Print(Elem* L);
void Remove(Elem*& L, Elem* prev);

void main()
{
    int amount;
    cout << "\n Enter the number of elements in the list: ";
    cin >> amount;

    int num;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter the number to include in the list: ";
        cin >> num;
        Insert(L, num);
    }
    cout << "\n List: ";
    Print(L);
    Info supposed;
    cout << "\n Enter the value of the element to be duplicated: ";
    cin >> supposed;
    insertAfter(L, L, supposed);
    Print(L);
    Remove(L, NULL);
}

void Insert(Elem*& L, Info value)
{
    if (L == NULL)
    {
        L = new Elem;
        L->info = value;
        L->link = L;
        return;
    }

    if (L->link == L)
    {
        Elem* tmp = new Elem;
        tmp->info = value;
        tmp->link = L;
        L->link = tmp;
        return;
    }

    Insert(L->link, value);
}

void insertAfter(Elem*& L, Elem* first, Info supposed)
{
    if (L == NULL)
        return;

    if (L->info == supposed)
    {
        Elem* tmp = new Elem;
        tmp->info = supposed;

        tmp->link = L->link;
        L->link = tmp;
        L = tmp;
    }

    if (L->link != first)
        insertAfter(L->link, first, supposed);
}

void Print(Elem* L)
{
    if (L == NULL)
        return;

    cout << " " << L->info;

    if (L->link != L)
        Print(L->link);
    else
        cout << endl;
}

void Remove(Elem*& L, Elem* prev)
{
    if (L == NULL)
        return;

    if (L->link == L)
    {
        delete L;
        L = NULL;
        return;
    }

    Elem* next = L->link;

    if (prev != NULL)
        prev->link = next;

    delete L;
    L = next;

    Remove(L, prev);
}
