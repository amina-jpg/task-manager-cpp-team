# task-manager-cpp-team
team git project - Task Manager C++
void deleteTask(int index) {
    if (index >= 1 && index <= tasks.size()) {
        cout << "Deleted: " << tasks[index - 1].title << endl;
        tasks.erase(tasks.begin() + (index - 1));
    } else {
        cout << "Invalid index" << endl;
    }
}
