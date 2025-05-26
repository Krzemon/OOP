#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <iostream>

using Student = std::tuple<std::string, int, double>;
using StudentList = std::vector<Student>;

int main() {
    StudentList students = {
        {"Anna", 12345, 4.5},
        {"Bartek", 23456, 3.8},
        {"Celina", 34567, 4.9}
    };

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return std::get<2>(a) > std::get<2>(b); // sortowanie po średniej malejąco
    });

    std::for_each(students.begin(), students.end(), [](const Student& s) {
        std::cout << std::get<0>(s) << " (" << std::get<1>(s) << "): " << std::get<2>(s) << '\n';
    });

    // static_assert przykład
    static_assert(std::is_same<StudentList::value_type, Student>::value, "Błędny typ");
}
