#include <iostream>
#include <string>

using namespace std;

struct Phone
{
    string name; // название телефона
    int year; // год выпуска
    float price; // цена телефона
    Phone* next; // указатель на следующий элемент
};

Phone* CreatePhone (string name, int year, float price) //добавление элемента в список
{
    Phone* NewPhone = new Phone;
    NewPhone->name = name;
    NewPhone->year = year;
    NewPhone->price = price;
    NewPhone->next = NULL;
    return NewPhone;
}
void AddFirst (Phone* Head, string name, int year, float price) //добавление в начало списка
{
    Phone* NewPhone = new Phone;
    NewPhone->name = name;
    NewPhone->year = year;
    NewPhone->price = price;
    NewPhone->next = Head;
    Head = NewPhone;
    return;
}
void AddLast (Phone* Head, string name, int year, float price) //добавление элемента в конец списка
{
    Phone *tmp = Head;
    if (Head == NULL){
        AddFirst(Head, name, year, price);
        return;
    }
    while (tmp->next){
        tmp = tmp->next;
    }
    Phone *NewPhone = new Phone;
    NewPhone->name = name;
    NewPhone->year = year;
    NewPhone->price = price;
    NewPhone->next = NULL;
    tmp->next = NewPhone;
    return;
}
int AddAfter (Phone *Head, string name, int year, float price, string AfterElement)//добавление после заданного элемента
{
    if (Head == NULL)
        return 1;
    Phone *tmp = Head;
    while (tmp != NULL && tmp->name != AfterElement){
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return 1;
    Phone *NewPhone = new Phone;
    NewPhone->name = name;
    NewPhone->year = year;
    NewPhone->price = price;
    NewPhone->next = tmp->next;
    tmp->next = NewPhone;
    return 0;
}
int AddBefore (Phone *Head, string name, int year, float price, string BeforeElement)//добавление перед заданным элементом
{
    if (Head == NULL)
        return 1;
    if (Head->name == BeforeElement){
        AddFirst(Head, name, year, price);
        return 0;
    }
    if (Head->next == NULL)
        return 1;
    Phone *prev = Head, *tmp = Head->next;
    while (tmp->next != NULL && tmp->name != BeforeElement){
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->name != BeforeElement)
        return 1;
    Phone *NewPhone = new Phone;
    NewPhone->name = name;
    NewPhone->year = year;
    NewPhone->price = price;
    NewPhone->next = tmp;
    prev->next = NewPhone;
    return 0;
}
int DeletePhone (Phone* Head, string DeletePhone)//удаление элемента по имени
{
    if (Head == NULL)
        return 1;
    Phone *tmp = Head;
    if (Head->name == DeletePhone){
        delete tmp;
        return 0;
    }
    if (Head->next == NULL)
        return 1;
    Phone *prev = Head;
    tmp = Head->next;
    while (tmp->next != NULL && tmp->name != DeletePhone){
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp-> name != DeletePhone)
        return 1;
    prev->next = tmp->next;
    delete tmp;
    return 0;
}
void PrintList (Phone *Head)// вывод списка 
{
    if (Head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Phone *tmp = Head;
    while (tmp != NULL) {
        cout << "Product: " << tmp->name << "\nYear: " << tmp->year << "\nPrice: " << tmp->price << endl;
        tmp = tmp->next;
    }
    cout << endl;
    return;
}
int main()
{
    Phone *Head = NULL; //указатель на начало списка
    Phone *NewPhone = NULL;
    string name, BeforeElement, AfterElement;
    int year;
    float price;
    int action = 0;

    while (action != 8)
    {
        cout << "1. add a phone;\n";
        cout << "2. add an item to the top of the list;\n";
        cout << "3. add an item to the end of the list; \n";
        cout << "4. add an item to the list after a given item;\n";
        cout << "5. add an item to the list before the specified item;\n";
        cout << "6. delete an item from the list ;\n";
        cout << "7. print list;\n";
        cout << "8. program exit;\n";

        cout << "choose action: ";
        cin >> action;

        switch(action)
        {
            case 8:
            {
                break;//выход из цикла
            }

            case 1:
            {
                cout << "Enter Phone: " << endl;
                cin >> name >> year >> price;
                NewPhone = CreatePhone(name, year, price);// добавление элемента в список
                break;
            }

            case 2:
            {
                cout << "Enter Phone: " << endl;
                cin >> name >> year >> price;
                AddFirst(Head,name,year,price); //добавление элемента в начало списка
                break;
            }
            case 3:
            {
                cout << "Enter Phone: " << endl;
                cin >> name >> year >> price;
                AddLast(Head,name,year,price); //добавление элемента в конец списка
                break;
            }
            case 4:
            {
                cout << "Input name of Phone" << endl;
                cin >> AfterElement;
                AddAfter (Head, name, year, price, AfterElement); //добавление после заданного элемента
                break;
            }
            case 5:
            {
                cout << "Input name of Phone" << endl;
                cin >> BeforeElement;
                AddBefore(Head, name, year, price, BeforeElement);//добавление перед заданным элементом
                break;
            }
            case 6:
            {
                cout << "Input name of Phone" << endl;
                cin >> name;
                DeletePhone(Head, name);//удаление по имени элемента
                cout << name << " is deleted" << endl;
                break;;
            }
            case 7:
            {
	      PrintList(Head);//печать списка
                break;;
            }
        }
    }
}
