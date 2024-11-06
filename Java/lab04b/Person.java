public class Person {
    private String name;   // imie
    private String street; // ulica
    private int number;    // numer adresu

    public Person(String name, String street, int num){
        this.setName(name);
        this.setStreet(street);
        this.setNumber(num);
    }

    // gettery
    public String getName(){
        return this.name;
    }
    public String getStreet(){
        return this.street;
    }
    public int getNumber(){
        return this.number;
    }

    // settery
    public void setName(String name){
        this.name = name;
    }
    public void setStreet(String street){
        this.street = street;
    }
    public void setNumber(int number){
        this.number = number;
    }

    // metoda wypisujaca uporzadkowanie szczegoly obiektu Person 
    public void printDetails(){
        System.out.println("name: " + this.getName());
        System.out.println("street: " + this.getStreet());
        System.out.println("number: " + this.getNumber());   
        System.out.println("--------------------------");   
    }


    // konstruktor kopiujacy plytki
	public Person (Person other){
        this.setName(other.getName());
        this.setStreet(other.getStreet());
        this.setNumber(other.getNumber());
	}


    // konstruktor kopiujacy gleboki
	public Person (Person other, int a){
        this.setName(new String(other.getName()));
        this.setStreet(new String(other.getStreet()));
        this.setNumber(other.getNumber());
	}

}
