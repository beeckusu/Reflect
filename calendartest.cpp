/*********************************************************//**
  * Filename: calendar.cpp
  * Author: Leo Kim
  * Date: 11/08/2018
  *
  * This file tests the Calendar constructor and printEvents method
  ************************************************************/

#include <vector>
#include <unistd.h>
#include "calendar.h"

int main() {
  Calendar c1;
  // constuctor will print the events from your calendar

  c1.printEvents();
  // printEvents call will print the canned data events
  return 0;
}
