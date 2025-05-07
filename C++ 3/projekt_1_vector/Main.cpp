/*

#### Celem zadania
jest implementacja struktury organizacyjnej firmy przy użyciu klas:
Company, Department oraz Employee.
Dane powinny być przechowywane w listach dwukierunkowych, bez użycia kontenerów STL,
takich jak `std::vector` czy `std::list`.

--------------------------------------------------------------------------------------------
## Lista Dwukierunkowa – Definicja i Implementacja
Lista dwukierunkowa to **dynamiczna struktura danych**, w której każdy element (węzeł) zawiera:
1. **Wskaźnik na poprzedni element** (`prev`)
2. **Dane** (np. `Employee` lub `Department`)
3. **Wskaźnik na następny element** (`next`)

### Jak działa lista dwukierunkowa w naszym projekcie?
#### **Dodawanie elementu na końcu listy**
1. Tworzymy nowy węzeł (`newNode`).
2. Jeśli lista jest pusta – ustawiamy `m_head = m_tail = newNode`.
3. Jeśli nie – podpinamy `newNode` do `m_tail`:
   m_tail->next = newNode;
   newNode->prev = m_tail;
   m_tail = newNode;

#### Iteracja po liście
// Od początku do końca:
EmployeeNode* current = m_head;
while (current) {
    current->employee.printInfo();
    current = current->next;
}
// Od końca do początku:
EmployeeNode* current = m_tail;
while (current) {
    current->employee.printInfo();
    current = current->prev;
}

--------------------------------------------------------------------------------------------

## Struktura i Zależności Klas w projekcie

### Klasa `Employee` (Pracownik)
Reprezentuje pojedynczego pracownika w firmie. Może należeć do jednego działu (`Department`).
#### **Atrybuty:**
- `m_name` – nazwa pracownika
- `m_department` – wskaźnik na dział, do którego należy

#### **Metody:**
- Konstruktor do inicjalizacji pracownika
- `printInfo()` – wypisuje informacje o pracowniku

---
#### Do klasy Employee odnosi sie struktura `EmployeeNode` (Węzeł listy)

---

### Klasa `Department` (Dział)
Reprezentuje dział w firmie. Przechowuje listę pracowników w dwukierunkowej liście.

#### **Atrybuty:**
- `m_name` – nazwa działu
- `m_head` – wskaźnik na pierwszy element listy `EmployeeNode`
- `m_tail` – wskaźnik na ostatni element listy `EmployeeNode`

#### **Metody:**
- Konstruktor inicjalizujący dział
- **`addEmployee(Employee&)`** – dodaje nowego pracownika do listy
- **`removeEmployee(std::string name)`** – usuwa pracownika z listy
- **`operator[](int index)`** – umożliwia dostęp do pracownika po indeksie
- **`printEmployeesForward()`** – iteruje po pracownikach od `head` do `tail`
- **`printEmployeesBackward()`** – iteruje od `tail` do `head`
- **Destruktor** – zwalnia pamięć usuwając całą listę

---

#### Do klasy Department odnosi sie struktura `DepartmentNode` (Węzeł listy)
---

### Klasa `Company` (Firma)
Reprezentuje firmę, która przechowuje listę działów.

#### **Atrybuty:**
- `m_name` – nazwa firmy
- `m_head` – wskaźnik na pierwszy element listy `DepartmentNode`
- `m_tail` – wskaźnik na ostatni element listy `DepartmentNode`

#### **Metody:**
- Konstruktor inicjalizujący firmę
- **`addDepartment(Department&)`** – dodaje dział do firmy
- **`printDepartments()`** – wypisuje wszystkie działy
- **Destruktor** – zwalnia pamięć usuwając całą listę
*/

#include "Company.h"
#include "Department.h"
#include "Employee.h"
#include <iostream>

int main() {
    // Tworzymy firmę
    Company myCompany("TechCorp");

    // Tworzymy działy
    Department itDept("IT");
    Department hrDept("HR");
    Department financeDept("Finance");

    // Dodajemy działy do firmy
    myCompany.addDepartment(itDept);
    myCompany.addDepartment(hrDept);
    myCompany.addDepartment(financeDept);

    // Dodajemy pracowników
    Employee e1("Alice", &itDept);
    Employee e2("Bob", &itDept);
    Employee e3("Charlie", &hrDept);
    Employee e4("Dave", &financeDept);
    Employee e5("Eve", &itDept);

    // Wypisujemy działy firmy
    myCompany.printDepartments();

    // Iteracja po pracownikach w dziale IT (od początku do końca)
    std::cout << "\nEmployees in IT (forward):\n";
    itDept.printEmployeesForward();

    // Iteracja po pracownikach w dziale IT (od końca do początku)
    std::cout << "\nEmployees in IT (backward):\n";
    itDept.printEmployeesBackward();

    // Usunięcie pracownika z działu IT
    std::cout << "\nRemoving Bob from IT...\n";
    itDept.removeEmployee("Bob");

    // Sprawdzenie listy po usunięciu
    std::cout << "\nEmployees in IT after removal:\n";
    itDept.printEmployeesForward();

    return 0;
}

/* wynik działania:
Company: TechCorp departments:
- IT
- HR
- Finance

Employees in IT (forward):
Employee: Alice (Department: IT)
Employee: Bob (Department: IT)
Employee: Eve (Department: IT)

Employees in IT (backward):
Employee: Eve (Department: IT)
Employee: Bob (Department: IT)
Employee: Alice (Department: IT)

Removing Bob from IT...

Employees in IT after removal:
Employee: Alice (Department: IT)
Employee: Eve (Department: IT)
*/
