import java.util.ArrayList;

public class Store{
    ArrayList<Client> clients = new ArrayList<>();

    // metoda dodajaca nowego klienta na koncu listy
    void add(Client aClient){
        clients.add(aClient);
    }

    // metoda wyswietlajaca wszystkich klientow w sklepie
    public void print(){
        for (Client elem : clients) {
            elem.print();
        }
    } 

    // metoda zwraca referencje do klienta o podanym ID, lub null jesli nie ma takiego klienta.
    public Client find(int ID){
        for (Client elem : clients) {
            if(elem.clientId == ID){
                return elem;
            }
        }
        return null;
    } 

}



