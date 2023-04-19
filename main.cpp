#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Vector {
private:
    int size; // Размерность
    int* array; // Массив
    int n; // Номер
    int cifr =0;
public:
    static int count; //кол-во массивов
    Vector operator + (Vector& r); //сложение
    Vector operator - (Vector& r); // Вычитание
    Vector operator = (Vector& r); // Присваивание
    Vector operator * (Vector& r); // Произведение
    Vector operator - (); // Унарный минус
    Vector operator / (Vector& r); // деление
    Vector operator ^ (Vector& r); //скалярное произведение с углом
    Vector operator & (Vector& r); //скалярное произведение без угла
    Vector operator < (Vector& r);
    Vector operator > (Vector& r);

// КОНСТРУКТОРЫ

// Конструктор принимающий размерность
    Vector(int s, int f, int d) {
        size = 3;
        array = new int[3];
        array[0] = s;
        array[1] = f;
        array[2] = d;
        count++;
        n = count;
        cout << "\x1B[90mCalled constructor \033[0m" << "Vector(int s): " << "\x1B[90mVector is made \033[0m" << n << endl;
    }
    Vector(int s, int f, int d, int g) {
        size = 3;
        array = new int[4];
        array[0] = s;
        array[1] = f;
        array[2] = d;
        array[3] = g;
        count++;
        n = count;
        cout << "\x1B[90mCalled constructor \033[0m" << "Vector(int s): " << "\x1B[90mVector is made \033[0m" << n << endl << endl;
    }

    Vector(int s) {
        size = s;
        array = new int[s];
        for (int i = 0; i < s; i++) array[i] = rand() % 10;
        count++;
        n = count;
        cout << "\x1B[90mCalled constructor \033[0m" << "Vector(int s): " << "\x1B[90mVector is made \033[0m" << n << endl<< endl;
    }
    // Конструктор по умолчанию
    Vector() {
        size = 3;
        array = new int[3];
        for (int i = 0; i < 3; i++) array[i] = 0;
        count++;
        n = count;
        cout << "\x1B[90mCalled constructor \033[0m" << "Vector(): " << "\x1B[90mсVector is made \033[0m" << n << endl;
    };

// Конструктор принимающий размерность и элементы массива
    Vector(int s, int* x) {
        size = s;
        array = x;
        for (int i = 0; i < s; i++) array[i] = x[i];
        count++;
        n = count;
    };
    // Конструктор копирования
    Vector(const Vector& V) {
        size = V.size;
        array = new int[V.size];
        for (int i = 0; i < V.size; i++) array[i] = V.array[i];
        count++;
        n = count;
        cout << "\x1B[90mCalled constructor \033[0m" << "Vector(Vector& V): " << "\x1B[90mVector is made \033[0m" << n << endl << endl;
    };

// Деструктор
    ~Vector() {
        delete[] array;
        cout << "\x1B[31mCalled destructor: cleared vector memory \033[0m" << n << endl << endl;
    }


    void Print() {
        cout << "\x1B[31mInformation about vector: \033[0m" << endl << "Vector:\t";
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl << "Number:\t" << n << endl << endl;
    }
};
// РЕАЛИЗАЦИЯ ОПЕРАТОРОВ
Vector Vector :: operator +(Vector& r) {
    cout << "\x1B[31mSlozhenie vectorov \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] + r.array[i] << " ";
    cout << endl << endl;
    return 0;
}

Vector Vector :: operator -(Vector& r) {
    cout << "\x1B[31mVychitanie vectorov \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] - r.array[i] << " ";
    cout << endl << endl;
    return 0;
}
Vector Vector :: operator -() {
    cout << "\x1B[31mUnar minus vectora \033[0m" << n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << -array[i] << " ";
    cout << endl << endl;
    return 0;
}
Vector Vector :: operator *(Vector& r) {
    cout << "\x1B[31mProizvedenie vectorov \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] * r.array[i] << " ";
    cout << endl << endl;
    return 0;
}
Vector Vector :: operator ^(Vector& r) {
    int a = array[0];
    int b = array[1];
    int c = array[2];
    int d = array[3];
    double e;
    e = sqrt((a ^ 2) + (b ^ 2) + (c ^ 2));
    int a1 = r.array[0];
    int b1 = r.array[1];
    int c1 = r.array[2];

    double e1;
    e1=
            sqrt((a1 ^ 2) + (b1 ^ 2) + (c1 ^ 2));
    double tfi = e * e1 * cos(d);
    cout << "\x1B[31mсScalyarnoe proizvedenie vectorov s uglom \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl << endl;

    cout << tfi;
    cout << endl << endl;

    return 0;
}
Vector Vector :: operator <(Vector& r) {
    int a = array[0];
    int b = array[1];
    int c = array[2];
    cin >> cifr;
    double gf;
    a = a * cifr;
    b = b * cifr;
    c = c * cifr;

    cout << "\x1B[31mProizvedenie vectora na chislo \033[0m " << a << " " << b << " " << c;
    cout << endl << endl;
    return 0;
}
Vector Vector :: operator >(Vector& r) {
    int a = array[0];
    int b = array[1];
    int c = array[2];
    cin >> cifr;
    double gf;
    a = a / cifr;
    b = b / cifr;
    c = c / cifr;

    cout << "\x1B[31mDelenie vectora na chislo \033[0m " << a << " " << b << " " << c;
    cout << endl << endl;
    return 0;

}

Vector Vector :: operator &(Vector& r) {
    cout << "\x1B[31mCkalyarnoe proizvedenie vectorov bez ugla \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl << endl;
    int a = array[0];
    int b = array[1];
    int c = array[2];

    int a1 = r.array[0];
    int b1 = r.array[1];
    int c1 = r.array[2];

    double e;
    e = (a * a1) + (a * b1) + (a * c1);
    cout << e;
    cout << endl << endl;
    return 0;

}

Vector Vector :: operator =(Vector& r) {
    cout << "\x1B[31mPrisvaivanie vectoru \033[0m" << n << "\x1B[31m znachenie vectora \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++) array[i] = r.array[i];
    cout << endl;
    return 0;
}
Vector Vector :: operator /(Vector& r) {
    cout << "\x1B[31mDelenie vectorov \033[0m" << n << "\x1B[31m и \033[0m" << r.n << "\x1B[31m:\033[0m";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] / r.array[i] << " ";
    cout << endl << endl;
    return 0;
}
int Vector::count = 0;
// Вывод количества созданных векторов
void Total() {
    cout << "\x1B[31mSozdano vectorov: \033[0m" << Vector::count << endl << endl;
}
int main() {
    cout << "sdfsdf";
    cout << "vvesti znacheniya vruchnuyu?\n da-1\nnet-0";
    int as = 0;
    cin >> as;
    if (as == 0) {
// Создание объектов класса Vector
//Vector a(3);
//Vector b(3);
//Vector c;
//Vector d(b);
        Vector a(3, 4, 5, 45);
        Vector b(5, 4, 3);
// Вывод объектов
        a.Print();
        b.Print();
// Вывод объектов

//c.Print();
//d.Print();

// Вывод кол-ва созданных объектов
        Total();
// Операции с векторами
        a + b;
        a - b;
        -b;
        a* b;
        a^ b;
        a& b;
        a / b;
        a < b;
        a > b;

//a = b;
        a.Print();
        b.Print();
    }
    else {
        cout << "input elements of vector_1 x,y,z ";
        int x;
        int y;
        int z;
        cin >> x;
        cin >> y;
        cin >> z;
        Vector a(x, y, z);
        cout << "input elements of vector_2 x,y,z ";
        int x1;
        int y1;
        int z1;
        cin >> x1;
        cin >> y1;
        cin >> z1;
        Vector b(x1, y1, z1);
// Вывод объектов
        a.Print();
        b.Print();
        cout << "choose operation \n1 - +\n2 - -\n3 - *\n4 - /";
        int fd;
        cin >> fd;
        switch (fd)
        {
            case 1:
                a + b;
                break;
            case 2:
                a - b;
                break;
            case 3:
                a * b;
                break;
            case 4:
                a / b;
                break;
        }
    }

}