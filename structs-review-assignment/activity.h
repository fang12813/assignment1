// for each activity, you need to keep track of
// activity name(e.g., skiing)
//ii. activity location (e.g., mt hood meadows)
// iii.activity level (e.g.l, easy, difficult, not for the faint of heart etc)
// iv.rating(e.g., 1-10 about how fun the experience is)
// v.type: athletic, food, arts, games, or others - have about 5 different types of
// activities for the user to choose from

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <cstddef>  // for size_t(ype)
using namespace std;

class Activity {  // can also use stuct activity
     public:      // only if using class keyword
     static const size_t MAX_CHARS = 50;

     char* name[MAX_CHARS + 1] = {0};
     char location[MAX_CHARS + 1] = {0};
     char level[MAX_CHARS + 1] = {0};
     int rating;   // 1-10
     int type;     // 0-4
     
};

void print(ostream &os, Activity &it);
void printAll(ostream &os, Activity arr[], size_t size);

#endif

