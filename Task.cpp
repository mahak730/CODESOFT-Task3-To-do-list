#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string name;
    bool is_completed;
};

void add_task(vector<Task>& to_do_list, const string& task_name) {
    to_do_list.push_back({task_name, false});
}

void view_tasks(const vector<Task>& to_do_list) {
    for (const Task& task : to_do_list) {
        cout << task.name << " (" << (task.is_completed ? "completed" : "pending") << ")\n";
    }
}

void mark_task_as_completed(vector<Task>& to_do_list, int task_index) {
    to_do_list[task_index].is_completed = true;
}

void remove_task(vector<Task>& to_do_list, int task_index) {
    to_do_list.erase(to_do_list.begin() + task_index);
}

int main() {
    vector<Task> to_do_list;

    int choice;
    while (true) {
        cout << "Enter a command: \n"
             << "1. Add task\n"
             << "2. View tasks\n"
             << "3. Mark task as completed\n"
             << "4. Remove task\n"
             << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task_name;
                cout << "Enter the task name: ";
                cin >> task_name;
                add_task(to_do_list, task_name);
                break;
            }
            case 2: {
                view_tasks(to_do_list);
                break;
            }
            case 3: {
                int task_index;
                cout << "Enter the task index: ";
                cin >> task_index;
                mark_task_as_completed(to_do_list, task_index);
                break;
            }
            case 4: {
                int task_index;
                cout << "Enter the task index: ";
                cin >> task_index;
                remove_task(to_do_list, task_index);
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice.\n";
                break;
            }
        }
    }

    return 0;
}