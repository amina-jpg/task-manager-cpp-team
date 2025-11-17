#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string title;
    bool done;
};

vector<Task> tasks;
//added by amina
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
void loadTasks(string filename = "tasks.txt") {
    ifstream file(filename);
    tasks.clear();
    string line;

    while (getline(file, line)) {
        size_t pos = line.find("|");
        string title = line.substr(0, pos);

        bool done = (line.substr(pos + 1) == "1");
        tasks.push_back({title, done});
    }

    file.close();
    cout << "Tasks loaded from " << filename << endl;
}

void viewTasks() {
    cout << "Displaying all tasks:" << endl;
    showAll();
}

void updateTask(int index, string newTitle) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].title = newTitle;
        cout << "Task updated to: " << newTitle << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}
// Added by laiba
void deleteTask(int index) {
    if (index >= 1 && index <= tasks.size()) {
        cout << "Deleted: " << tasks[index - 1].title << endl;
        tasks.erase(tasks.begin() + (index - 1));
    } else {
        cout << "Invalid index" << endl;
    }}
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
// Added by F
void markComplete(int index, bool done = true) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].done = done;
        cout << "Task " << index << " marked as "
             << (done ? "complete" : "incomplete") << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}

void menu() {
    while (true) {
        cout << "\n1=Add 2=View 3=Update 4=Search 0=Exit\n> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter title: ";
            string t; 
            cin.ignore(); 
            getline(cin, t);
            addTask(t);
        } 
        else if (choice == 2) viewTasks();
        else if (choice == 3) {
            int i; 
            string nt;
            cout << "Index: "; cin >> i;
            cin.ignore(); 
            cout << "New title: "; getline(cin, nt);
            updateTask(i, nt);
        } 
        else if (choice == 4) {
            string k; 
            cout << "Keyword: "; cin >> k;
            searchTask(k);
        } 
        else if (choice == 0) break;
        else cout << "Invalid choice!\n";
    }
}

int main() {
    //amina
    cout << "Task Manager (Team Project)" << endl;
    cout << "Welcome to Team Task Manager!\n";
    menu();
    return 0;
}
