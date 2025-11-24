#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todo_list.hpp"

TEST_CASE( "TodoList functionality" ) {
    // Can be instantiated
    TodoList list;
    REQUIRE( true );
    
    // Test all() on empty list
    REQUIRE( list.all() == "No tasks to display" );
    
    // Can add tasks to the list
    list.add("Buy milk");
    list.add("Buy eggs");
    
    // Test all() returns all tasks with header
    REQUIRE( list.all() == "All Tasks:\nBuy milk\nBuy eggs\n" );
    
    // Test complete() with no completed tasks
    REQUIRE( list.complete() == "Completed Tasks:\n" );
    
    // Test incomplete() with incomplete tasks
    REQUIRE( list.incomplete() == "Incomplete Tasks:\nBuy milk\nBuy eggs\n" );
    
    // Can complete a task
    list.complete("Buy eggs");
    
    // Test complete() after completing a task
    REQUIRE( list.complete() == "Completed Tasks:\nBuy eggs\n" );
    
    // Test incomplete() after completing a task
    REQUIRE( list.incomplete() == "Incomplete Tasks:\nBuy milk\n" );
    
    // Can handle completing non-existent task
    list.complete("Non-existent task");
    
    // Can clear all tasks
    list.clear();
    
    // Test all() on cleared list
    REQUIRE( list.all() == "No tasks to display" );
}

TEST_CASE( "TodoList tags functionality" ) {
    TodoList list;
    
    // Can add tasks with tags
    list.add("Buy bread", {"shopping", "important"});
    list.add("Go to the grocery store", {"shopping", "important"});
    list.add("Go to the bank", {"finance", "important"});
    
    // Test find_tags returns tasks with specific tag
    REQUIRE( list.find_tags("shopping") == "Tasks with tag shopping:\nBuy bread\nGo to the grocery store\n" );
    REQUIRE( list.find_tags("finance") == "Tasks with tag finance:\nGo to the bank\n" );
    REQUIRE( list.find_tags("important") == "Tasks with tag important:\nBuy bread\nGo to the grocery store\nGo to the bank\n" );
    REQUIRE( list.find_tags("nonexistent") == "Tasks with tag nonexistent:\n" );
}

TEST_CASE( "TodoList edge cases" ) {
    TodoList list;
    
    // Test adding empty task description
    list.add("");
    REQUIRE( list.all() == "No tasks to display" );
    
    // Test adding duplicate task
    list.add("Buy milk");
    list.add("Buy milk");
    REQUIRE( list.all() == "All Tasks:\nBuy milk\n" );
    
    // Test completing task that doesn't exist
    list.complete("Non-existent task");
    REQUIRE( list.complete() == "Completed Tasks:\n" );
}

