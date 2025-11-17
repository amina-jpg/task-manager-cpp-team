added by laiba
void deleteTask(int index) {
    if (index >= 1 && index <= tasks.size()) {
        cout << "Deleted: " << tasks[index - 1].title << endl;
        tasks.erase(tasks.begin() + (index - 1));
    } else {
        cout << "Invalid index" << endl;
    }
}
# C++ Team Project – Feature-Based Development

This project is a collaborative C++ application developed using **Git**, **GitHub**, and **feature branching workflow**.  
Each team member created their own feature branch, added code into `app.cpp`, and merged their work into the `main` branch through pull requests.

---

## 🚀 Project Overview

This repository demonstrates:

- Proper use of **Git version control**
- Working with **multiple branches**
- Creating and merging **pull requests**
- Collaborative coding in **C++**
- Maintaining a clean and professional workflow

The base file is:

