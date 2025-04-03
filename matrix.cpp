#include "matrix.hpp"
using namespace std;  //no more "std::"" crud

// constructor to initialize an empty NxN matrix
Matrix::Matrix(size_t N) : N(N), data(N, vector<int>(N, 0)) {}

// constructor to initialize matrix from a given 2D vector
Matrix::Matrix(vector<vector<int>> nums) : N(nums.size()), data(nums) {}

// reads matrix from a file
Matrix Matrix::from_file(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    size_t size;
    file >> size; //read matrix size
    
    //declare nxn matricies
    vector<vector<int>> matrix1(size, vector<int>(size));
    vector<vector<int>> matrix2(size, vector<int>(size));

    //read the first matrix from file
    for (auto &row : matrix1)
        for (auto &num : row)
            file >> num;

    //read second file from matrix
    for (auto &row : matrix2)
        for (auto &num : row)
            file >> num;

    //print the first matrix
    cout << "Matrix 1:\n";
    Matrix m1(matrix1);
    m1.print_matrix();
    
    //print the second matrix
    cout << "Matrix 2:\n";
    Matrix m2(matrix2);
    m2.print_matrix();

    return m1 + m2; // returns sum of matrices
}

// overloading + operator for matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const {
    vector<vector<int>> result(N, vector<int>(N));          //create a new nxn result matrix
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            result[i][j] = data[i][j] + rhs.data[i][j];     //add elements

    return Matrix(result);      //return resulting matrix
}

// overloading * operator for matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const {
    vector<vector<int>> result(N, vector<int>(N, 0));       //all 0 result matrix
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            for (size_t k = 0; k < N; k++)
                result[i][j] += data[i][k] * rhs.data[k][j];//matrix multiplication

    return Matrix(result);  //return matrix product
}

// set value at given row and column
void Matrix::set_value(size_t i, size_t j, int n) {
    if (i < N && j < N)
        data[i][j] = n;
}

// get value from given row and column
int Matrix::get_value(size_t i, size_t j) const {
    return (i < N && j < N) ? data[i][j] : 0;
}

// get size of the matrix
int Matrix::get_size() const {
    return N;
}

// compute sum of main diagonal elements
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < N; i++)
        sum += data[i][i];          //add elements along the main diagonal

    return sum;
}

// compute sum of secondary diagonal elements
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (size_t i = 0; i < N; i++)
        sum += data[i][N - i - 1];      //add elements along the secondary diagonal

    return sum;
}

//swap two rows
void Matrix::swap_rows(size_t r1, size_t r2) {
    if (r1 < N && r2 < N)           //bounds check
        swap(data[r1], data[r2]);   //swap rows
}

//swap two columns
void Matrix::swap_cols(size_t c1, size_t c2) {
    if (c1 < N && c2 < N)                   //bounds check
        for (size_t i = 0; i < N; i++)     
            swap(data[i][c1], data[i][c2]); //swap columns
}

// print the matrix in proper form
void Matrix::print_matrix() const {
    for (const auto &row : data) {      //for each row
        for (int num : row)             //each element in row
            cout << setw(4) << num;     //print each element with space
        cout << '\n';                   //move to next line for new row
    }
}
