#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.assign(r, vector<double>(c, 0.0));
    }

    void fill(double value) {
        for (auto& row : data) {
            fill(row.begin(), row.end(), value);
        }
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    double determinant() const {
        if (rows != cols) return 0.0;
        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        double det = 0.0;
        for (int i = 0; i < rows; i++) {
            det += data[0][i] * cofactor(0, i);
        }
        return det;
    }

private:
    double cofactor(int row, int col) const {
        int sign = ((row + col) % 2 == 0) ? 1 : -1;
        return sign * minor(row, col).determinant();
    }

    Matrix minor(int row, int col) const {
        Matrix m(rows - 1, cols - 1);
        int mi = 0;
        for (int i = 0; i < rows; i++) {
            if (i == row) continue;
            int mj = 0;
            for (int j = 0; j < cols; j++) {
                if (j == col) continue;
                m.data[mi][mj] = data[i][j];
                mj++;
            }
            mi++;
        }
        return m;
    }
};
