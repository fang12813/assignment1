#include <iostream>
#include "activity.h"
using namespace std;

void loadActivities(istream &is, Activity arr[], size_t &size);
void insert(Activity arr[], size_t &size, Activity it, size_t pos);
