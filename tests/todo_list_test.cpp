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
    
    // Test all() returns first task
    REQUIRE( list.all() == "Buy milk\n" );
    
    // Test complete() with no completed tasks
    REQUIRE( list.complete() == "" );
    
    // Test incomplete() with incomplete tasks
    REQUIRE( list.incomplete() == "Buy milk" );
    
    // Can complete a task
    list.complete("Buy eggs");
    
    // Test complete() after completing a task
    REQUIRE( list.complete() == "Buy eggs" );
    
    // Test incomplete() after completing a task
    REQUIRE( list.incomplete() == "Buy milk" );
    
    // Can handle completing non-existent task
    list.complete("Non-existent task");
    
    // Can clear all tasks
    list.clear();
    
    // Test all() on cleared list
    REQUIRE( list.all() == "No tasks to display" );
}

