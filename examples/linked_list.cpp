#include <iostream>
using namespace std;

//struct list_element_old_style{
//    list_element_old_style(int n = 0, list_element_old_style *ptr = 0):
//        d(n), next(ptr){}
//    int d;
//    list_element_old_style *next;
//};

class list_element{
    public:
        list_element(int n=0, list_element *ptr=0):
            d(n), next(ptr){}
        int d;
        list_element *next;
};

class list{
    public:
        list():head(0), cursor(0){}
        //list(const list &list);
        void prepend(int n); //insert at front value n
        int get_element(){return cursor->d;}
        void advance(){cursor=cursor->next;}
        void print();
        ~list();
    private:
        list_element *head;
        list_element *cursor;
};

list::~list()
{
    for(cursor = head; cursor != 0;)
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

//list::list(const list &lst)
//{
//    if(lst.head == 0)
//    {
//        head = 0; cursor = 0;
//    }
//    else
//    {
//        cursor = lst.head;
//        list_element *h = new list_element();
//        list_element *previous;
//        head = h;
//        h->d = lst.head->d;
//        previous = h;
//    }
//    for (cursor = lst.head; cursor != 0;)
//    {
//        h = new list_element();
//        h->d = cursor->d;
//        previous->next = h;
//        cursor = cursor->next;
//        previous = h;
//    }
//    cursor = head;
//}

void list::prepend(int n)
{
    if(head == 0) //empty list case
        cursor = head = new list_element(n, head);
    else // add to fron -chain
        head = new list_element(n, head);
}

void list::print()
{
    list_element *h = head;
    while(h != 0) //idiom for chaining
    {
        cout << h->d << ", ";
        h = h->next;
    }
    cout << "###" << endl;
}

int main(int argc, char **argv)
{
    list a, b;
    a.prepend(9); a.prepend(8);
    cout << "list a" << endl;
    a.print();
    for (int i=0; i < 40; ++i)
        b.prepend(i*i);
    cout << "list b" << endl;
    b.print();
}
