#include "todo_list.hpp"
#include "task.hpp"
#include <iostream>

void TodoList::add(std::string task_description) {
    Task* new_task = new Task();
    new_task->description = task_description;
    new_task->is_complete = false;
    task_list.push_back(new_task);
}

void TodoList::complete(std::string task_description) {
    for (Task* task : task_list) {
        if (task->description == task_description) {
            task->is_complete = true;
            break;
        }
    }
}

void TodoList::all() {
    if (task_list.size() == 0) {
        std::cout << "No tasks to display" << std::endl;
        return;
    }
    for (Task* task : task_list) {
        std::cout << task->description << std::endl;
    }
}

void TodoList::complete() {
    for (Task* task : task_list) {
        if (task->is_complete) {
            std::cout << task->description << std::endl;
        }
    }
}

void TodoList::incomplete() {
    for (Task* task : task_list) {
        if (!task->is_complete) {
            std::cout << task->description << std::endl;
        }
    }
}

void TodoList::clear() {
    for (Task* task : task_list) {
        delete task;
    }
    task_list.clear();
}

