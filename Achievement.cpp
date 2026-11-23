#include "Achievement.hpp"
using namespace std;
int Achievement::getCount(int discoveries, int attempts, int successes, int hints) {
    int count = 0;
    if (discoveries >= 5) count++;
    if (discoveries >= 10) count++;
    if (discoveries >= 20) count++;
    if (discoveries == 28) count++;
    if (attempts >= 15) count++;
    if (successes >= 10) count++;
    if (discoveries >= 10 && hints == 0) count++;
    return count;
}
string Achievement::getName(int index, int discoveries, int attempts, int successes, int hints) {
    string names[7];
    int count = 0;
    if (discoveries >= 5) names[count++] = "First Spark";
    if (discoveries >= 10) names[count++] = "Curious Mind";
    if (discoveries >= 20) names[count++] = "Master Alchemist";
    if (discoveries == 28) names[count++] = "Elementoria Master";
    if (attempts >= 15) names[count++] = "Experimenter";
    if (successes >= 10) names[count++] = "Craftsman";
    if (discoveries >= 10 && hints == 0) names[count++] = "Independent Thinker";
    if (index < 0 || index >= count) return "";
    return names[index];
}
