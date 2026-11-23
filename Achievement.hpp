#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include <string>
using namespace std;
class Achievement {
public:
    static int getCount(int discoveries, int attempts, int successes, int hints);
    static string getName(int index, int discoveries, int attempts, int successes, int hints);
};
#endif
