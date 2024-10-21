// UWAGA: Przy wykonaniu zadania można sprawdzić genereowanie kodu i logiki aplikacji
// z wykorzystaniem chatGPT / Copiltot, itp.
//
// Celem zadania jest przeanalizowanie kodu, oraz eksploracja obliczeń asynchronicznych.
// 1. Stwórz wektor `gameObjects`, który będzie przechowywał wskaźniki do wielu obiektów gry. 
// Następnie wypełnij ten wektor mieszanką Player i Enemy. Następnie, w pętli, 
// zaktualizuj (update) każdy obiekt gry asynchronicznie, korzystając z `std::async`. 
// Podczas oczekiwania na zakończenie aktualizacji, wykonujemy akcje takie jak ataki 
// i otrzymywanie obrażeń na obiektach gry.
// Na koniec czekamy, aż wszystkie aktualizacje zakończą się, korzystając 
// z metody `get()` na futurach reprezentujących asynchroniczne zadania.
// 
// 2. Wykonaj symulację kosztownych (heavy) operacji numerycznych asynchronicznie za pomocą std::async
//    oraz std::this_thread::sleep_for(std::chrono::seconds(X))
// Symulujemy postęp aktualizacji za pomocą komunikatów drukowanych na ekranie, aby pokazać,
// że można wykonywać inne zadania podczas oczekiwania na zakończenie kosztownej operacji. 
// Gdy taka operacja zostanie zakończona, pobieramy wynik za pomocą future.get() i kontynuujemy proces aktualizacji.



#include <vector>
#include <typeinfo>
#include "Player.h"
#include "Enemy.h"

int main() {
  // Create instances of Player and Enemy
    // Player player;
    // Enemy enemy;

    // // Update player asynchronously
    // std::future<void> player_future = std::async(std::launch::async, &Player::update, &player);

    // // Update enemy asynchronously
    // std::future<void> enemy_future = std::async(std::launch::async, &Enemy::update, &enemy);

    // // Do some other work while the player and enemy are updating...
    // // Perform actions while waiting for updates
    // player.attack();
    // enemy.takeDamage(20);

    // // Wait for player update to finish
    // player_future.get();

    // // Wait for enemy update to finish
    // enemy_future.get();

    std::cout << "All updates completed!" << std::endl << " ------------------ " << std::endl << "Nowa Gra" << std::endl <<  " ------------------ " << std::endl;

    std::vector<GameObject*> gameObjects;

    int num_of_players = 3;
    int num_of_enemies = 10;

    for(int i = 0; i < num_of_players; ++i){
      Player temp = Player();
      gameObjects.push_back(&temp);
    }
    
    for(int i = 0; i < num_of_enemies; ++i){
      Enemy temp = Enemy();
      gameObjects.push_back(&temp);
    }
    // mooj wektor: ket = [p,p,p, e,e,...]
    for(auto i = gameObjects.begin(); i != gameObjects.end(); ++i){
      
      // warunki logiczne i asynchronicznosc chyba nie ida w parze..   
      // if(typeid(*i) == typeid(Player())){
      //   std::future<void> player_future = std::async(std::launch::async, &Player::update, i);
      // }
      // else if(typeid(*i) == typeid(Enemy())){
      //   std::future<void> enemy_future = std::async(std::launch::async, &Enemy::update, i);
      // }
      // else{
      //   std::cout << "pominieto ture, bocian" << std::endl;
      // }

    }

    return 0;
}

/*
c++ async race
std lock guard c++
std::
      array, vector, async, find
      np.:
      asynchroniczne prezeszukiwanie drzewa katalogu, lepiej jak w windows, w polaczeniu z projektem

*/