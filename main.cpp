#include "matrix.hpp"
using namespace std;  // This allows us to write cout instead of std::cout, etc.

int main(int argc, char *argv[]) {
    //command line arg check
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    
    string filename = argv[1];                          //get filename from command-line
    Matrix sum_matrix = Matrix::from_file(filename);    //read the matrix data from file andget the sum
    
    cout << "Sum of Matrices:\n";   
    sum_matrix.print_matrix();      // print the sum of the matricies

    //creating additional operations
    Matrix matrix1 = sum_matrix;
    Matrix matrix2 = sum_matrix;

    cout << "\nMultiplication of Matrices:\n";
    Matrix multiplied_matrix = matrix1 * matrix2;   //mult two matricies
    multiplied_matrix.print_matrix();               //print result

    //compute and display the sum of both diagonals
    cout << "\nSum of Main Diagonal: " << matrix1.sum_diagonal_major() << '\n';
    cout << "Sum of Secondary Diagonal: " << matrix1.sum_diagonal_minor() << '\n';

    //swap rows and print the updated matrix
    cout << "\nSwapping rows 0 and 1:\n";
    matrix1.swap_rows(0, 1);
    matrix1.print_matrix();

    //swap rows and print the updated matrix
    cout << "\nSwapping columns 0 and 1:\n";
    matrix2.swap_cols(0, 1);
    matrix2.print_matrix();

    //swap columns and print the updated matrix
    cout << "\nUpdating matrix value at (2,2) to 99:\n";
    sum_matrix.set_value(2, 2, 99);
    sum_matrix.print_matrix();

    return 0;
}
