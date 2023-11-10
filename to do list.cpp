#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
    } else {
        std::cout << "Task List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            std::cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
            std::cout << tasks[i].description << std::endl;
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& tasks, size_t index) {
    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task index.\n";
    } else {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& tasks, size_t index) {
    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task index.\n";
    } else {
        std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
        tasks.erase(tasks.begin() + index - 1);
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        // Display menu
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear newline character from the buffer
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                viewTasks(tasks);
                std::cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                std::cin >> index;
                markTaskAsCompleted(tasks, index);
                break;
            }
            case 4: {
                viewTasks(tasks);
                std::cout << "Enter the index of the task to remove: ";
                size_t index;
                std::cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

