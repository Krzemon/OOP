#include "Zoo.h"

int main() {
    Zoo zoo;

    // Tworzenie zwierząt
    Birds* bird1 = new Birds("Eagle");
    Birds* bird2 = new Birds("Parrot");
    Whales* whale1 = new Whales("Blue Whale");
    Whales* whale2 = new Whales("Humpback Whale");

    std::cout << "---------------------------" << std::endl;
    zoo.addAnimal(bird1);
    zoo.addAnimal(bird2);
    zoo.addAnimal(whale1);
    zoo.addAnimal(whale2);
    std::cout << "---------------------------" << std::endl;

    // Próba dodania zwierzęcia o tej samej nazwie
    Birds* bird3 = new Birds("Parrot");
    zoo.addAnimal(bird3); // Komunikat o błędzie: zwierzę o tej samej nazwie już istnieje.

    // Próba dodania zwierzęcia o tym samym adresie
    zoo.addAnimal(bird2); // Komunikat o błędzie: zwierzę o tym samym adresie już istnieje.

    // Próba dodania zwierzęcia, gdy limit ptaków jest osiągnięty
    delete bird3;
    bird3 = new Birds("Stork");
    Birds* bird4 = new Birds("Sparrow");
    Birds* bird5 = new Birds("Swallow");
    Birds* bird6 = new Birds("Pigeon");

    Whales* whale3 = new Whales("Orca");
    zoo.addAnimal(bird3); 
    zoo.addAnimal(bird4); 
    zoo.addAnimal(bird5);
    zoo.addAnimal(bird6);  // Komunikat o błędzie: Zoo already has 5 birds, cannot add more!
    zoo.addAnimal(whale3); // Komunikat o błędzie: Zoo already has 2 whales, cannot add more!

    std::cout << "---------------------------" << std::endl;
    
    zoo.print();

    return 0;
}