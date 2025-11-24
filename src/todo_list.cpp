#include "todo_list.hpp"
#include "task.hpp"
#include <iostream>
#include <string>
#include <vector>

void TodoList::add(std::string task_description, std::vector<std::string> tags = {}) {
    if (task_description.empty()) {
        std::cout << "Task description cannot be empty" << std::endl;
        return;
    }
    for(Task* task : task_list) {
        if (task->description == task_description) {
            std::cout << "Task already exists" << std::endl;
            return;
        }
    }

    Task* new_task = new Task();
    new_task->description = task_description;
    new_task->is_complete = false;
    new_task->tags = tags;
    task_list.push_back(new_task);
}

void TodoList::add(std::string task_description) {
    add(task_description, {});
}
void TodoList::complete(std::string task_description) {
    for (Task* task : task_list) {
        if (task->description == task_description) {
            task->is_complete = true;
            break;
        }
    }
}

std::string TodoList::find_tags(std::string tag) {
    std::string result = "Tasks with tag " + tag + ":\n";
    for (Task* task : task_list) {
        std::vector<std::string> tags = task->tags;
        for (std::string t : tags) {
            if (t == tag) {
                result += task->description + "\n";
            }
        }
    }
    std::cout << result << std::endl;
    return result;
}
std::string TodoList::all() {
    if (task_list.size() == 0) {
        std::cout << "No tasks to display" << std::endl;
        return "No tasks to display";
    }
    std::string result = "All Tasks:\n";
    for (Task* task : task_list) {
        result += task->description + "\n";
    }
    return result;
}

std::string TodoList::complete() {
    std::string result = "Completed Tasks:\n";
    for (Task* task : task_list) {
        if (task->is_complete) {
            result += task->description + "\n";
        }
    }
    return result;
}

std::string TodoList::incomplete() {
    std::string result = "Incomplete Tasks:\n";
    for (Task* task : task_list) {
        if (!task->is_complete) {
            result += task->description + "\n";
        }
    }
    return result;
}

void TodoList::clear() {
    for (Task* task : task_list) {
        delete task;
    }
    task_list.clear();
}

