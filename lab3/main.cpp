#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    vector<vector<int>> matrix;
    int row, column;

    Matrix(int size1, int size2) {
        row = size1;
        column = size2;
        matrix.resize(row, vector<int>(column));
    }
    void InputMatrix() {
        cout << "input coordinates of matrix: " << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                cin >> matrix[i][j];
        }
    }
    void PrintMatrix() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    //сложение матриц
    Matrix operator+(Matrix &m) {
        Matrix m3(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
            m3.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
        return m3;
    }
    //вычитание матриц
    Matrix operator-(Matrix &m) {
        Matrix m3(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                m3.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
        return m3;
    }
    //уножение матрицы на число
    Matrix operator*(int num) {
        Matrix m3(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
            m3.matrix[i][j] = matrix[i][j] * num;
        }
        return m3;
    }
    //произведение матриц
    Matrix operator*(Matrix &m) {
        Matrix m3(row, column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                for (int k= 0; k < column; k++)
                    m3.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
        return m3;
    }
};
int main() {
    int row, column;
    int number;
    cout << "Input size of matrix (row x column): ";
    cin >> row >> column;
    Matrix matrix1(row, column);
    cout << "Matrix 1: " << endl;
    matrix1.InputMatrix();

    Matrix matrix2(row, column);
    cout << "Matrix 2: " << endl;
    matrix2.InputMatrix();

    cout << "Matrix 1: " << endl;
    matrix1.PrintMatrix();
    cout << "Matrix 2: " << endl;
    matrix2.PrintMatrix();

    cout << "Input a number to multiply the matrix: ";
    cin >> number;
    cout << endl;

    cout << "Matrix 1 + Matrix 2 = " << endl;
    Matrix summa = matrix1 + matrix2;
    summa.PrintMatrix();

    cout << "Matrix 1 - Matrix 2 = " << endl;
    Matrix raznitsa = matrix1 - matrix2;
    raznitsa.PrintMatrix();

    cout << "Matrix 1 * " << number << " = " << endl;
    Matrix proizvedenie_na_chislo1 = matrix1 * number;
    proizvedenie_na_chislo1.PrintMatrix();

    cout << "Matrix 2 * " << number << " = " << endl;
    Matrix proizvedenie_na_chislo2 = matrix2 * number;
    proizvedenie_na_chislo2.PrintMatrix();

    cout << "Matrix 1 * Matrix 2 = " << endl;
    if (row != column) {
        cout << "Matrix multiplication is not possible" << endl;
    } else {
        Matrix proizvedenie = matrix1 * matrix2;
        proizvedenie.PrintMatrix();
    }
    return 0;
}
