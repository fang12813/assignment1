// Author: Fang Huang
// Assignment: Stuct review assignment1
// Date: Apr 06, 2025
// Description: write an app to maintain a list of activities that the user likes to participate in. The app should load all activity information from a data file (activities.txt) once the app is started. 
//It allows the user to view, add, remove, and search for activities.
// Sources:cs161B the concept of a struct

#include <iostream>
#include <fstream>
#include <cstring>  
#include "activity.h"
#include "main.h"

using namespace std;

int main(){
  size_t MAX_ACTIVITIES = 30;
  size_t activitiesSize = 0;

  Activity activities[MAX_ACTIVITIES];
  ifstream fin = ifstream("activities.txt";
  loadActivities(fin, activities, activitiesSize);
  printALL(cout, activities,activitiesSize);

  return 0;
  }

// Skiing;Mt Hood Meadows;Difficult;6;0
void loadActivities(istream &is, Activity arr[], size_t &size){
  char const DELIMITER = ';';
  size = 0;
  while(is && !is.peek() != EOF){
    Activity it;
    // read data from fil
    is.getline(it.name, Activity::MAX_CHARS, DELIMITER);
    is.getline(it.location, Activity::MAX_CHARS, DELIMITER);
    is.getline(it.level, Activity::MAX_CHARS, DELIMITER);
    is >> it.rating;
    is.get(); // remove delimiter
    is. >> it.type;
    is.get(); // remove  \n newline character

  // find sorted position
    int pos = 0;

  // refactored to not use while true
   bool next = true;
   while(next){
      if (pos == size) {
        next = false;
      }
      else if(strcmp(arr[pos].name, it.name) > 0){
       pos++;
      }else{
        next = false;
      }
   }

// insert at position
   insert(arr, size, it, pos);
  }
}

void insert(Activity arr[], size_t &size, Activity it, size_t pos){
  for(size_t i = size + 1; i > pos; i--){
     arr[i] = arr[i-1];
  }
   arr[pos] = it;
   size++;
}




