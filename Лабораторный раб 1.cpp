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
        std::cout << "1 13 49";
        break;
    }
    case 2:
    {
        char symbol;
        std::cout << "symbol = "; std::cin >> symbol;
        std::cout << "1" << symbol << "13" << symbol << "49";
        break;
    }
    case 3:
    {
        int number1;
        int number2;
        int number3;
        std::cout << "number1 = "; std::cin >> number1;
        std::cout << "number2 = "; std::cin >> number2;
        std::cout << "number3 = "; std::cin >> number3;
        std::cout << number1 << " " << number2 << " " << number3;
        break;
    }
    case 4:
    {
        int a;
        std::cout << "a = "; std::cin >> a;
        std::cout << "x = " << 12 * pow(a, 2) + 7 * a - 12 << "\n";
        int x;
        std::cout << "x = "; std::cin >> x;
        std::cout << "y = " << 3 * pow(x, 3) + 4 * pow(x, 2) - 11 * x + 1;
        break;
    }
    case 5:
    {
        float volume;
        std::cout << "volume = "; std::cin >> volume;
        float mass;
        std::cout << "mass = "; std::cin >> mass;
        std::cout << "density = " << mass / volume;
        break;
    }
    case 6:
    {
        float a;
        float b;
        std::cout << "a = "; std::cin >> a;
        while (a == 0)
        {
            std::cout << "wrong input!\n";
            std::cout << "a = "; std::cin >> a;
        }
        std::cout << "b = "; std::cin >> b;
        std::cout << "x = " << -b / a;
        break;
    }
    case 7:
    {
        int x1;
        int y1;
        int x2;
        int y2;
        std::cout << "x1 = "; std::cin >> x1;
        std::cout << "y1 = "; std::cin >> y1;
        std::cout << "x2 = "; std::cin >> x2;
        std::cout << "y2 = "; std::cin >> y2;
        std::cout << "distance = " << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        break;
    }
    case 8:
    {
        int a;
        int b;
        int h;
        std::cout << "a = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        std::cout << "h = "; std::cin >> h;
        std::cout << "P = " << a + b + sqrt(pow(abs(a - b) / 2, 2) + pow(h, 2)) * 2;
        break;
    }
    case 9:
    {
        int a;
        std::cout << "a = "; std::cin >> a;
        std::cout << "V = " << pow(a, 3) << "\n";
        std::cout << "S = " << pow(a, 2) * 6;
        break;
    }
    case 10:
    {
        int a;
        std::cout << "a = "; std::cin >> a;
        std::cout << "P = " << a * 4;
        break;
    }
    case 11:
    {
        int r;
        std::cout << "r = "; std::cin >> r;
        std::cout << "d = " << r * 2;
        break;
    }
    case 12:
    {
        char name[100];
        std::cout << "name = "; std::cin >> name;
        std::cout << "Hello, " << name << "! My name is C++ and I'm here to make you cry.";
        break;
    }
    }
}
