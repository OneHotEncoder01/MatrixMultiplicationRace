#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int N = 256;

class Matrix
{
private:
    int rows, cols;
    int* data;
public:
    // constructor
    Matrix(int r, int c)
        : rows(r), cols(c), data(new int[r * c])
    {
    }
    // destructor
    ~Matrix()
    {
        delete[] data;
    }

    // ()operator to get the value at index [i ,j]
    int& operator()(int i, int j)
    {
        return data[i * cols + j];
    }

    // getter for Rows
    int getRows() const
    {
        return rows;
    }

    // getter for columns
    int getCols() const
    {
        return cols;
    }


    // Matrix multiplication 
    Matrix multiply(Matrix& A, Matrix& B)
    {
        if (B.cols != A.rows) {
            throw "Invalid matrix dimensions";
        }

        Matrix result(A.rows, B.cols);

        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < cols; k++) {
                    result(i, j) += B(i, k) * A(k, j);
                }
            }
        }
        return result;
    }
};
// prints Matricies (for test purposes)
void print(Matrix& m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            std::cout << m(i, j) << " ";
        }
        std::cout << std::endl;
    }
}


// initialze matrix with random values 
void initialize(Matrix m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            m(i, j) = rand() % 100;
        }
    }
}

int main() {
    // how many floating point operation thas it take to multiply
    // 2 N by N matrices
    double flops = N * N * N * 2;

    // time measurment tools
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    srand(time(0));

    //create 2 matricies and initialize
    Matrix m1(N, N);
    initialize(m1);
    Matrix m2(N, N);
    initialize(m2);


    // multiply 2 N by N matrices 100 times and measure the time 
    // it takes to complete
    for (int i = 0; i < 100; i++) {
        auto t1 = high_resolution_clock::now();

        Matrix result = result.multiply(m2, m1);

        auto t2 = high_resolution_clock::now();


        // how many flops can this algorithm perform in a second
        duration<double, std::milli> ms_double = t2 - t1;
        double GFLOP = flops / ms_double.count() * 1e-9;
        std::cout << GFLOP << " gflops" << std::endl;
    }
    return 0;
}