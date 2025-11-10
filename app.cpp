#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string title;
    bool done;
};

vector<Task> tasks;

void showAll() {
    cout << "\n---- Task List ----\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].done ? "✓" : " ") << "] " << tasks[i].title << "\n";
    }
    cout << "-------------------\n";
}

int main() {
    cout << "Task Manager (Team Project)" << endl;
    showAll();
    return 0;
}
