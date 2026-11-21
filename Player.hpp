#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using namespace std;
class Player {
    string name;
    int discovered;
    bool finished;
public:
    Player(string playerName = "Explorer");
    string getName() const;
    void setName(string playerName);
    void setTotalDiscovered(int number);
    int getTotalDiscovered() const;
    int getCompletionPercentage() const;
    bool isCompleted() const;
};
#endif
