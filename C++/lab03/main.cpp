#include "equation_solver.h"

int main(int argc, char* argv[]) {
    float a, b, c;

    switch (argc) {
        case 1:
            std::cout << "No arguments provided.\n";
            return 0;
        case 2:
            if (!isNumber(argv[1])) {
                std::cout << "Argument 1 is not a number.\n";
                return 1;
            }
            a = std::atof(argv[1]);
            handleOneArgument(a);
            break;
        case 3:
            if (!isNumber(argv[1]) || !isNumber(argv[2])) {
                std::cout << "Argument 1 or 2 is not a number.\n";
                return 1;
            }
            a = std::atof(argv[1]);
            b = std::atof(argv[2]);
            handleTwoArguments(a, b);
            break;
        case 4:
            if (!isNumber(argv[1]) || !isNumber(argv[2]) || !isNumber(argv[3])) {
                std::cout << "Argument 1, 2, or 3 is not a number.\n";
                return 1;
            }
            a = std::atof(argv[1]);
            b = std::atof(argv[2]);
            c = std::atof(argv[3]);
            handleThreeArguments(a, b, c);
            break;
        default:
            std::cout << "Too many arguments provided.\n";
            break;
    }

    return 0;
}
