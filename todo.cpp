#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

void displayMenu() {
    cout << "\t\t\t\t*To-Do List*\n"
         << "\t\t\t**********************\n\n"
         << "1. Add Task\n"
         << "2. View Tasks\n"
         << "3. Mark Task as Done\n"
         << "4. Remove Task\n"
         << "5. Exit\n"
         << "Choose an option: ";
}

void addTask(vector<Task> &tasks) {
    cin.ignore();
    cout << "Enter a new task: ";
    string taskDesc;
    getline(cin, taskDesc);

    if (!taskDesc.empty()) {
        tasks.emplace_back(taskDesc);
        cout << "Task added: \n" << taskDesc << endl;
    } else {
        cout << "Task cannot be empty." << endl;
    }
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].completed ? "Done" : "Pending") << "]" << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as done." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as done: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as done: \n" << tasks[taskNumber - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        cout << "Task removed: \n" << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
