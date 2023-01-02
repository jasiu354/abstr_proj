#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Operation {
public:
    virtual T Evaluate(const T &operand1, const T &operand2) const = 0;
};

template<typename T>
class Addition : public Operation<T> {
public:
    T Evaluate(const T &operand1, const T &operand2) const {
        return operand1 + operand2;
    }
};

template<typename T>
class Subtraction : public Operation<T> {
public:
    T Evaluate(const T &operand1, const T &operand2) const {
        return operand1 - operand2;
    }
};

template<typename T>
class Multiplication : public Operation<T> {
public:
    T Evaluate(const T &operand1, const T &operand2) const {
        return operand1 * operand2;
    }
};

template<typename T>
class Division : public Operation<T> {
public:
    T Evaluate(const T &operand1, const T &operand2) const {
        if (operand2 == 0) {
            throw std::invalid_argument("cannot divide by 0");
        }
        return operand1 / operand2;
    }
};

template<typename T>
class Calculator {
public:
    T Evaluate(const T &operand1, const T &operand2,
               const Operation<T> &operation) {
        return operation.Evaluate(operand1, operand2);
    }
};

int main() {
    Calculator<double> calculator;
    std::vector<Operation<double> *> operations;
    operations.push_back(new Addition<double>());
    operations.push_back(new Subtraction<double>());
    operations.push_back(new Multiplication<double>());
    operations.push_back(new Division<double>());

    std::cout << "Calculator" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;

    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > 4) {
        throw std::invalid_argument("choose choice between 1 and 4");
    }

    std::cout << "Enter your numbers: ";

    double result;
    double num1;
    double num2;
    std::cin >> num1;
    std::cin >> num2;
    result = calculator.Evaluate(num1, num2, *operations[choice - 1]);
    std::cout << "Result: " << result << std::endl;

    return 0;
}