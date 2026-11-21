#include "Player.hpp"
using namespace std;
Player::Player(string playerName) {
    name = playerName;
    discovered = 4;
    finished = false;
}
string Player::getName() const { return name; }
void Player::setName(string playerName) { name = playerName; }
void Player::setTotalDiscovered(int number) {
    discovered = number;
    finished = discovered >= 28;
}
int Player::getTotalDiscovered() const { return discovered; }
int Player::getCompletionPercentage() const { return discovered * 100 / 28; }
bool Player::isCompleted() const { return finished; }
