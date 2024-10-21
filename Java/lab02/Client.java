public class Client {
    int clientId;
    String clientName;
    public static int count;

    public Client(){
        ++count;
        this.clientName = "empty";
        this.clientId = count;
    }

    public Client(String default_name){
        ++count;
        this.clientName = default_name;
        this.clientId = count;
    }

    // metoda zwracajaca nazwe klienta
    public String getName() {
        return this.clientName;
    }

    // metoda zwracajaca ID klienta
    public int getID(){
        return this.clientId;
    }

    // metoda wyswietla dane klienta
    public void print(){
        System.out.println(this.clientId);
        System.out.println(this.clientName);
    }

    public static int countClients(){
        return count;
    }

}
