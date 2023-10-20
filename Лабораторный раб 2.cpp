#include <iostream>
#include <math.h>

int main()
{
    int task_number;
    std::cout << "task_number = "; std::cin >> task_number;
    switch (task_number)
    {
    case 1:
    {
        int X;
        int Y;
        int Z;
        std::cout << "X = "; std::cin >> X;
        std::cout << "Y = "; std::cin >> Y;
        std::cout << "Z = "; std::cin >> Z;
        if (X % 2 == 1 and Y % 2 == 1){
            std::cout << "condition 1 is true" << std::endl;
        }else{
            std::cout << "condition 1 is false" << std::endl;
        }if (X < 20 ^ Y < 20) {
            std::cout << "condition 2 is true" << std::endl;
        }
        else {
            std::cout << "condition 2 is false" << std::endl;
        }if (X == 0 or Y == 0) {
            std::cout << "condition 3 is true" << std::endl;
        }
        else {
            std::cout << "condition 3 is false" << std::endl;
        }if (X < 0 and Y < 0 and Z < 0) {
            std::cout << "condition 4 is true" << std::endl;
        }
        else {
            std::cout << "condition 4 is false" << std::endl;
        }int counter = 0;
        if (X % 5 == 0) { counter++; }
        if (Y % 5 == 0) { counter++; }
        if (Z % 5 == 0) { counter++; }
        if (counter == 1){
            std::cout << "condition 5 is true" << std::endl;
        }
        else {
            std::cout << "condition 5 is false" << std::endl;
        }if (X > 100 or Y > 100 or Z > 100) {
            std::cout << "condition 6 is true" << std::endl;
        }
        else {
            std::cout << "condition 6 is false" << std::endl;
        }
        break;
    }
    case 2:
    {
        using byte = int;
        std::pair<byte, byte> positionA;
        std::pair<byte, byte> positionB;
        std::cout << "a = "; std::cin >> positionA.first;
        std::cout << "b = "; std::cin >> positionA.second;
        std::cout << "c = "; std::cin >> positionB.first;
        std::cout << "d = "; std::cin >> positionB.second;
        if (positionA.first == positionB.first or positionA.second == positionB.second) {
            std::cout << "1) field B is in danger" << std::endl;
        }
        else {
            std::cout << "1) field B is safe" << std::endl;
        }if (abs(positionA.first - positionB.first) == abs(positionA.second - positionB.second)) {
            std::cout << "2) field B is in danger" << std::endl;
        }
        else {
            std::cout << "2) field B is safe" << std::endl;
        }if (abs(positionA.first - positionB.first) == 1 or abs(positionA.second - positionB.second) == 1) {
            std::cout << "3) king can move to field B" << std::endl;
        }
        else {
            std::cout << "3) king can not move to field B" << std::endl;
        }if (positionA.first == positionB.first or positionA.second == positionB.second or abs(positionA.first - positionB.first) == abs(positionA.second - positionB.second)) {
            std::cout << "4) field B is in danger" << std::endl;
        }
        else {
            std::cout << "4) field B is safe" << std::endl;
        }if ((positionA.second == 2 and positionB.second == 4) or (positionB.first == positionA.first and positionB.second - positionA.second == 1)) {
            std::cout << "5) pawn can move to field B normally" << std::endl;
        }else if(abs(positionB.first - positionA.first) == 1 and positionB.second - positionA.second == 1) {
            std::cout << "5) pawn can move to field B by eating a black figure" << std::endl;
        }
        else {
            std::cout << "5) pawn can not move to field B" << std::endl;
        }
        break;
    }
    case 3:
    {
        for (int i = 1; i <= 9; i++) {
            std::cout << i << " x 7 = " << i * 7 << std::endl;
        }
        int N;
        std::cout << "N = "; std::cin >> N;
        for (int i = 1; i <= 9; i++) {
            std::cout << i << " x "<< N << " = " << i * N << std::endl;
        }
        break;
    }
    case 4:
    {
        int proizvedenie = 1;
        for (int i = 8; i <= 15; i++) {
            proizvedenie *= i;
        }std::cout << proizvedenie << std::endl;

        proizvedenie = 1;
        int a;
        std::cout << "a = "; std::cin >> a;
        for (a; a <= 20; a++) {
            proizvedenie *= a;
        }std::cout << proizvedenie << std::endl;

        proizvedenie = 1;
        int b;
        std::cout << "b = "; std::cin >> b;
        for (int i = 1; i <= b; i++) {
            proizvedenie *= i;
        }std::cout << proizvedenie << std::endl;

        proizvedenie = 1;
        std::cout << "a = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        for (a; a <= b; a++) {
            proizvedenie *= a;
        }std::cout << proizvedenie << std::endl;
        break;
    }
    }
}
