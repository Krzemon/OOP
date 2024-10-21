public class Main{
   public static void main (String [] args){

    Client jeden = new Client("Adam");
    Client dwa = new Client("Asia");
    Client trzy = new Client();

    jeden.print();
    dwa.print();
    trzy.print();

    System.out.println("Teraz z uzyciem klasy store");

    Store store = new Store();

    store.add(jeden);
    store.add(dwa);
    store.add(trzy);

    store.print();
   }
}

