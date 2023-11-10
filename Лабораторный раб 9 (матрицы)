#include <iostream>

using namespace std;

struct Matrix{
    int** data_ = nullptr;
    size_t rows_ = 0u;
    size_t columns_ = 0u;
};

void Construct(Matrix& out, size_t rows, size_t columns){
    out.data_ = new int*[rows];
    for(int i = 0; i < rows; i++){
        out.data_[i] = new int[columns];
    }
    out.rows_ = rows;
    out.columns_ = columns;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            out.data_[i][j] = 0;
        }
    }
};

void Destruct(Matrix& in){
    for (int i = 0; i < in.rows_; i++){
        delete[] in.data_[i];
    }
    delete[] in.data_;
};

Matrix Copy(const Matrix& matrix){
    Matrix copy;
    Construct(copy, matrix.rows_, matrix.columns_);
    for (int i = 0; i < matrix.rows_; i++){
        for (int j = 0; j < matrix.columns_; j++){
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
};

Matrix Add(const Matrix& a, const Matrix& b){
    if (a.rows_ == b.rows_ and a.columns_ == b.columns_){
        Matrix add;
        Construct(add, a.rows_, a.columns_);
        for (int i = 0; i < add.rows_; i++){
            for (int j = 0; j < add.columns_; j++){
                add.data_[i][j] = a.data_[i][j] + b.data_[i][j];
            }
        }
        return add;
    }
    return Matrix();
}

Matrix Sub(const Matrix& a, const Matrix& b){
    if (a.rows_ == b.rows_ and a.columns_ == b.columns_){
        Matrix sub;
        Construct(sub, a.rows_, a.columns_);
        for (int i = 0; i < sub.rows_; i++){
            for (int j = 0; j < sub.columns_; j++){
                sub.data_[i][j] = a.data_[i][j] - b.data_[i][j];
            }
        }
        return sub;
    }
    return Matrix();
}

Matrix Mult(const Matrix& a, const Matrix& b){
    if (a.columns_ == b.rows_){
        Matrix mult;
        Construct(mult, a.rows_, b.columns_);
        for (int i = 0; i < mult.rows_; i++){
            for (int j = 0; j < mult.columns_; j++){
                for (int k = 0; k < a.columns_; k++){
                    mult.data_[i][j] += a.data_[i][k] * b.data_[k][j];
                }
            }
        }
        return mult;
    }
    return Matrix();
}

void Transposition(Matrix& matrix){
    Matrix transpos;
    Construct(transpos, matrix.columns_, matrix.rows_);
    for (int i = 0; i < transpos.rows_; i++){
        for (int j = 0; j < transpos.columns_; j++){
            transpos.data_[i][j] = matrix.data_[j][i];
        }
    }
    matrix = transpos;
};

int main(){
    srand(time(0));
    Matrix pipec;
    Construct(pipec, 5, 3);
    for (int i = 0; i < pipec.rows_; i ++){
        for (int j = 0; j < pipec.columns_; j++){
            pipec.data_[i][j] = rand() % 20 - 10;
            cout << pipec.data_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=========" << endl;
    /*Matrix kapec;
    Construct(kapec, 3, 5);
    for (int i = 0; i < kapec.rows_; i ++){
        for (int j = 0; j < kapec.columns_; j++){
            kapec.data_[i][j] = rand() % 20 - 10;
            cout << kapec.data_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=========" << endl;*/
    Transposition(pipec);
    for (int i = 0; i < pipec.rows_; i ++){
        for (int j = 0; j < pipec.columns_; j++){
            cout << pipec.data_[i][j] << " ";
        }
        cout << endl;
    }
}
