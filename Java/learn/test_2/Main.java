// AdresFormatter Interface
interface AdresFormatter {
    String getFormattedAddress();
}

// Address Class
class Address implements AdresFormatter {
    private String street, city, houseNumber, apartmentNumber, postalCode;

    public Address(String street, String city, String houseNumber, String apartmentNumber, String postalCode) {
        this.street = street;
        this.city = city;
        this.houseNumber = houseNumber;
        this.apartmentNumber = apartmentNumber;
        this.postalCode = postalCode;
    }

    @Override
    public String getFormattedAddress() {
        return street + ", " + houseNumber + "/" + apartmentNumber + ", " + city + ", " + postalCode;
    }
}

// Osoba Class
abstract class Osoba {
    private String name, phone, email, birthDate;
    private Address address;

    public Osoba(String name, String phone, String email, String birthDate, Address address) {
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.birthDate = birthDate;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public Address getAddress() {
        return address;
    }
}

// ProfessionalDataFormatter Interface
interface ProfessionalDataFormatter {
    String getFormattedProfessionalData();
}

// Pracownik Class
abstract class Pracownik extends Osoba implements ProfessionalDataFormatter {
    private String employmentDate;

    public Pracownik(String name, String phone, String email, String birthDate, Address address, String employmentDate) {
        super(name, phone, email, birthDate, address);
        this.employmentDate = employmentDate;
    }

    public String getEmploymentDate() {
        return employmentDate;
    }

    public abstract double getPensja();
}

// Umyslowy Class
class Umyslowy extends Pracownik {
    private double baseSalary;
    private boolean hasBonus;

    public Umyslowy(String name, String phone, String email, String birthDate, Address address, String employmentDate, double baseSalary, boolean hasBonus) {
        super(name, phone, email, birthDate, address, employmentDate);
        this.baseSalary = baseSalary;
        this.hasBonus = hasBonus;
    }

    @Override
    public double getPensja() {
        return hasBonus ? baseSalary * 1.24 : baseSalary * 1.12;
    }

    @Override
    public String getFormattedProfessionalData() {
        return String.format("Name: %s, Address: %s, Employment Date: %s, Salary: %.2f",
                getName(), getAddress().getFormattedAddress(), getEmploymentDate(), getPensja());
    }
}

// Fizyczny Class
class Fizyczny extends Pracownik {
    private double hourlyRate;
    private int hoursWorked;

    public Fizyczny(String name, String phone, String email, String birthDate, Address address, String employmentDate, double hourlyRate, int hoursWorked) {
        super(name, phone, email, birthDate, address, employmentDate);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    @Override
    public double getPensja() {
        return hourlyRate * hoursWorked;
    }

    @Override
    public String getFormattedProfessionalData() {
        return String.format("Name: %s, Address: %s, Employment Date: %s, Salary: %.2f",
                getName(), getAddress().getFormattedAddress(), getEmploymentDate(), getPensja());
    }
}

//Zaprogramuj powyższy diagram klas tak by z użyciem poniższych danych uzyskać dane wyjściowe umieszczone poniżej.
//W razie potrzeby dodaj potrzebne pola i metody.
// Main.java
public class Main {
    public static void main(String[] args) {
        Address adres1 = new Address("Zamkowa", "Olsztyn", "1", "10", "43-300");
        Address adres2 = new Address("Kręta", "Radom", "2", "20", "23-345");
        Address adres3 = new Address("Sienkiewicza", "Lublin", "4", "2", "12-167");

        Pracownik pracownik1 = new Umyslowy("Jan Kowalski", "123456789", "jan.k@example.com", "1980-01-01", adres1, "2010-01-01", 5000,true);
        Pracownik pracownik2 = new Umyslowy("Maria Konopnicka", "333456785", "maria.k@example.com", "1982-01-01", adres2, "2012-01-02", 3500,false);
        Pracownik pracownik3 = new Fizyczny("Adam Nowak", "987654321", "adam.n@example.com", "1985-06-01", adres3, "2015-03-15", 20, 160);

        System.out.println(pracownik1.getFormattedProfessionalData());
        System.out.println(pracownik2.getFormattedProfessionalData());
        System.out.println(pracownik3.getFormattedProfessionalData());
    }
}
//
//Name: Jan Kowalski, Address: Zamkowa, 1/10, Olsztyn, 43-300, Employment Date: 2010-01-01, Salary: 6200,00
//Name: Maria Konopnicka, Address: Kręta, 2/20, Radom, 23-345, Employment Date: 2012-01-02, Salary: 3920,00
//Name: Adam Nowak, Address: Sienkiewicza, 4/2, Lublin, 12-167, Employment Date: 2015-03-15, Salary: 3200,00