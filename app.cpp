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
void addTask(string title){
tasks.push_back({title,false});
cout<< "Added: " << title <<endl;
}
void menu() {
    while (true) {
        cout << "\n1=Add 2=View 3=Delete 4=Update 5=Search 6=Mark 7=Save 8=Load 0=Exit\n> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter title: ";
            string t; cin.ignore(); getline(cin, t);
            addTask(t);
        } else if (choice == 2) viewTasks();
        else if (choice == 3) {
            int i; cout << "Index: "; cin >> i; deleteTask(i);
        } else if (choice == 4) {
            int i; string nt;
            cout << "Index: "; cin >> i;
            cin.ignore(); cout << "New title: "; getline(cin, nt);
            updateTask(i, nt);
        } else if (choice == 5) {
            string k; cout << "Keyword: "; cin >> k;
            searchTask(k);
        } else if (choice == 6) {
            int i; cout << "Index: "; cin >> i;
            markComplete(i, true);
        } else if (choice == 7) saveTasks();
        else if (choice == 8) loadTasks();
        else if (choice == 0) break;
        else cout << "Invalid choice!\n";
    }
void searchTask(string keyword) {
    cout << "Search results for: " << keyword << endl;
    bool found = false;
    for (auto &t : tasks) {
        if (t.title.find(keyword) != string::npos) {
            cout << "- " << t.title << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found." << endl;
}
    // Added by B
void viewTasks() {
    cout << "Displaying all tasks:" << endl;
    showAll();
}
    // Added by D
void updateTask(int index, string newTitle) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].title = newTitle;
        cout << "Task updated to: " << newTitle << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}



}

int main() {
    cout << "Task Manager (Team Project)" << endl;
    showAll();
    cout << "Welcome to Team Task Manager!\n";
    menu();
    return 0;
}
