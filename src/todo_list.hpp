#pragma once

#include <string>
#include <vector>
#include "task.hpp"

class TodoList {
private:
    std::vector<Task*> task_list;

public:
    void add(std::string task_description);
    void complete(std::string task_description);
    std::string all();
    std::string complete();
    std::string incomplete();
    void clear();
    ~TodoList(){
        for (Task* task : task_list) {
            delete task;
        }
        task_list.clear();
        delete this;
    };
};


