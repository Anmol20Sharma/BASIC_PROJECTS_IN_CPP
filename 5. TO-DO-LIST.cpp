#include<bits/stdc++.h>
using namespace std;

struct Task {
    string title;
    string dueDate;  // DD/MM/YYYY
    string dueTime;  // HH:MM
    bool isDone;
};

vector<Task> tasks;
const string filename = "tasks.txt";

void loadTasks() {
    ifstream file(filename);
    tasks.clear();
    if (file.is_open()) {
        string title, dueDate, dueTime;
        bool done;
        while (getline(file, title)) {
            getline(file, dueDate);
            getline(file, dueTime);
            file >> done;
            file.ignore(); // consume newline
            tasks.push_back({title, dueDate, dueTime, done});
        }
        file.close();
    }
}

void saveTasks() {
    ofstream file(filename);
    for (auto &task : tasks) {
        file << task.title << endl;
        file << task.dueDate << endl;
        file << task.dueTime << endl;
        file << task.isDone << endl;
    }
    file.close();
}

void addTask() {
    string title, dueDate, dueTime;
    cout << "Enter task title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter due date (DD/MM/YYYY): ";
    getline(cin, dueDate);
    cout << "Enter due time (HH:MM): ";
    getline(cin, dueTime);

    tasks.push_back({title, dueDate, dueTime, false});
    saveTasks();
    cout << " task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title 
            << " | Due: " << tasks[i].dueDate << " " << tasks[i].dueTime
            << " | Status: " << (tasks[i].isDone ? "Done" : "⏳ Pending") << "\n";
    }
}

void markDone() {
    int index;
    viewTasks();
    cout << "\nEnter task number to mark as done: ";
    cin >> index;
    if (index > 0 && index <= (int)tasks.size()) {
        tasks[index - 1].isDone = true;
        saveTasks();
        cout << "task marked as done!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    int index;
    viewTasks();
    cout << "\nEnter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        saveTasks();
        cout << "🗑️ Task deleted successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    loadTasks();
    int choice;
    do {
        cout << "\n=====  TO-DO LIST MENU =====\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewTasks(); break;
            case 2: addTask(); break;
            case 3: markDone(); break;
            case 4: deleteTask(); break;
            case 5: cout << " END OF CODE\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
