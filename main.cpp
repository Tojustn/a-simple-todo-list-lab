#include <iostream>
#include <string>
#include "src/todo_list.hpp"

int main() {
 TodoList list;
 
 list.add("Buy milk");
 list.add("Buy eggs");
 list.add("Prepare a lesson for CSC 122");
 list.add("Sow beet seeds");
 list.add("");
 list.add("Buy milk");
 list.add("Buy bread", {"shopping", "important"});
 list.add("Go to the grocery store", {"shopping", "important"});
 list.add("Go to the bank", {"finance", "important"});
 list.add("Go to the post office", {"finance", "important"});
 list.add("Go to the library", {"education", "important"});
 list.add("Go to the park", {"education", "important"});
 list.add("Go to the museum", {"education", "important"});
 list.add("Go to the zoo", {"education", "important"});

 list.complete("Buy eggs");
 
  // Pretty prints a list of each of the four tasks above
  list.all();
  list.find_tags("education");
  list.find_tags("important");
  // Pretty prints the task "Buy eggs"
  list.complete();
 
  // Pretty prints the tasks "Buy milk",
  // "Prepare a lesson for CSC 122", and "Sow beet seeds"
  list.incomplete();
 
  // Clears the to-do list
  list.clear();
 
  // Pretty prints a message saying that the list is empty
  list.all();
}
