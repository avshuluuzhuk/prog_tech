#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
    vector<int> vector;
    int size;

    Vector(int length) {
        size = length;
        vector.resize(size);
    }
    //сложение векторов
    Vector operator+(Vector &v) {
        Vector v3(size);
        for (int i = 0; i < size; i++) {
            v3.vector[i] = vector[i] + v.vector[i];
        }
        return v3;
    }
    //вычитание векторов
    Vector operator-(Vector &v) {
        Vector v3(size);
        for (int i = 0; i < size; i++) {
            v3.vector[i] = vector[i] - v.vector[i];
        }
        return v3;
    }
    //уножение вектора на число
    Vector operator*(int num) {
        Vector v3(size);
        for (int i = 0; i < size; i++) {
            v3.vector[i] = vector[i] * num;
        }
        return v3;
    }
    //скалярное проиведение векторов
    int operator*(Vector &v) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += vector[i] * v.vector[i];
        }
        return result;
    }
    void InputVector() {
        cout << "input coordinates of vector: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> vector[i];
        }
    }
    void PrintVector() {
        for (int i = 0; i < size; i++)
            cout << vector[i] << " ";
        cout << endl;
    }
};
int main() {
    int size;
    int number;
    cout << "Input size of vectors: ";
    cin >> size;

    Vector vector1(size);
    cout << "Vector 1: " << endl;
    vector1.InputVector();

    Vector vector2(size);
    cout << "Vector 2: " << endl;
    vector2.InputVector();

    cout << "Vector 1 + Vector 2 = ";
    Vector summa = vector1 + vector2;
    summa.PrintVector();

    cout << "Vector 1 - Vector 2 = ";
    Vector raznitsa = vector1 - vector2;
    raznitsa.PrintVector();

    cout << "Vector 1 * Vector 2 = ";
    int scal_proizvedenie = vector1 * vector2;
    cout << scal_proizvedenie << endl;

    cout << "Input a number to multiply the vector: ";
    cin >> number;
    cout << "Vector 1 * " << number << " = ";
    Vector proizvedenie_na_chislo1 = vector1 * number;
    proizvedenie_na_chislo1.PrintVector();

    cout << "Vector 2 * " << number << " = ";
    Vector proizvedenie_na_chislo2 = vector2 * number;
    proizvedenie_na_chislo2.PrintVector();
}
