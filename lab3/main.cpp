#include <iostream>
using namespace std;
class Matrix
{
private:
    int rows, columns;
    int *pMatrix;
    int number;
public:
    void Print()
    {
        cout << "Matrix " << "№ " << number << ", size " << rows << "x" << columns << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << pMatrix[i * columns + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Конструктор принимающий размерность (2 значения)
    Matrix(int n, int m)
    {
        rows = n;
        columns = m;

        pMatrix = new int[rows * columns];

        for (int i = 0; i < rows * columns; i++)
        {
            pMatrix[i] = 0;
        }

        cout << "Called constructor" << "Matrix(int n, int m) " << " made object " << "№" << number << endl << endl;
    }

    // Конструктор принимающий размерность и элементы массива
    Matrix(int n, int m, double* x)
    {
        rows = n;
        columns = m;

        pMatrix = new int[rows * columns];

        for (int i = 0; i < rows * columns; i++)
        {
            pMatrix[i] = x[i];
        }

        cout << "Called constructor " << "Matrix(int n, int m, double* x) " << " made object " << "№" << number << endl << endl;
    };

    // Конструктор копирования
    Matrix(const Matrix& matrix)
    {
        rows = matrix.rows;
        columns = matrix.columns;

        pMatrix = new int[rows * columns];

        for (int i = 0; i < rows * columns; i++)
        {
            pMatrix[i] = matrix.pMatrix[i];
        }

        cout << "Called constructor " << "Matrix(const Matrix& matrix) " << " made object " << "№" << number << endl << endl;
    };
    Matrix operator + (Matrix& r);
    Matrix operator - (Matrix& r);
    Matrix operator * (Matrix& r);
    Matrix operator * (int n);
};
// Сложение двух матриц
Matrix Matrix :: operator +(Matrix& r)
{
    if (rows == r.rows && columns == r.columns)
    {
        Matrix result(rows, columns);

        cout << "Slozhenie " << "№" << number << " and " << "№" << r.number << ", in object " << "№" << result.number + 1;
        cout << endl << endl;

        for (int i = 0; i < rows * columns; i++)
        {
            result.pMatrix[i] = pMatrix[i] + r.pMatrix[i];
        }
        result.Print();

        return result;
    }
    else cout << "ne ydaloc slozit " << "№" << number << " and " << "№" << r.number << endl << endl;
}

// Вычитание двух матриц
Matrix Matrix :: operator -(Matrix& r)
{
    if (rows == r.rows && columns == r.columns)
    {
        Matrix result(rows, columns);
        cout << "vychitanie " << "№" << number << " and " << "№" << r.number << ", in object " << "№" << result.number + 1;
        cout << endl << endl;

        for (int i = 0; i < rows * columns; i++)
        {
            result.pMatrix[i] = pMatrix[i] - r.pMatrix[i];
        }
        result.Print();
        return result;
    }
    else cout << "ne ydaloc " << "№" << number << " and " << "№" << r.number << endl << endl;
}

// Произведение двух матриц
Matrix Matrix :: operator *(Matrix& r)
{
    if (columns == r.rows)
    {
        Matrix result(rows, r.columns);

        cout << "proizvedenie " << "№" << number << " and " << "№" << r.number << ", in object " << "№" << result.number + 1;
        cout << endl << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < r.columns; j++) {
                result.pMatrix[i * result.columns + j] = 0;
                for (int k = 0; k < columns; k++) {
                    result.pMatrix[i * result.columns + j] += pMatrix[i * columns + k] * r.pMatrix[k * r.columns + j];
                }
            }
        }
        return result;
    }
    else cout << "ne ydaloc " << "№" << number <<  " and " << "№" << r.number << endl << endl;
}

// Произведение матрицы на число
Matrix Matrix :: operator *(int n)
{
    Matrix result(rows, columns);

    cout << "proizvedenie " << "№" << number << " na chislo " << n << ", in object " << "№" << result.number + 1;
    cout << endl << endl;

    for (int i = 0; i < rows * columns; i++)
    {
        result.pMatrix[i] = pMatrix[i] * n;
    }
    return result;
}

int main()
{
    double* A;
    int x, y;

    cout << "input size of matrix (n x m): ";
    cin >> x >> y;

    int size = x * y;
    A = new double[size];
    cout << "input elements of matrix: "<< endl;
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    Matrix a(x,y,A);

    a.Print();

    double* B;
    cout << "input size of matrix (n x m): ";
    cin >> x >> y;

    size = x * y;
    B = new double[size];
    cout << "input elements of matrix: "<< endl;
    for (int i = 0; i < size; i++)
    {
        cin >> B[i];
    }
    Matrix b(x, y, B);
    b.Print();
    a + b;
    a - b;
}
