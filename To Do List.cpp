            /*....A small program to save and organize your tasks....*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;
//     ==========...[...The category definition section...]...========== 
class Class_ToDoList {
private:
    vector<string> tasks; // list to store task

public:
    //   .....[...Add a New task...]...
    void addTask(const string& task) 
    {
        tasks.push_back(task); // Add the task to the task list 
    }
    //  .....[...Mark the task as complete...].....
    void completeTask(int index) 
    {
        if (index >= 0 && index < tasks.size()) {
            tasks[index] += " (Completed)";// Add " (Completed)" text to the task
        }
        else {
            cout << "Invalid task index" << endl;// Error massage for invalid choise
        }
    }
    //  .....[...View all tasks...].....
    void viewTasks() 
    {
        if (tasks.empty()) {
            cout << "No tasks yet" << endl;// massege for no tasks
        }
        else {
            cout << "===== CURRENT TASKS =====" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;// diplay tasks with index
            }
        }
    }
};
//....[...Part Two: Main Function Dealing with the user interface...]....
int main() {
   Class_ToDoList To_do_list; // create an interface of the to do list class

    while (true) {
        cout << "\n===== TO-DO LIST =====" << endl;
        cout << "1. Add Task" <<endl;
        cout << "2. Completed Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;

        int choice;
       cout << "Enter your choice: ";
       cin >> choice;

        switch (choice) {
        case 1: {
            string task;
            cout << "Enter the task: ";
            cin.ignore(); // ignore the previos input
            getline(cin, task);// read the task from user
            To_do_list.addTask(task);
            break;
        }
        case 2: {
            int index;
            cout << "Enter the index of the task to complete: ";
            cin >> index;
            To_do_list.completeTask(index - 1);// mark task as completed
            break;
        }
        case 3:
            To_do_list.viewTasks(); // view all tasks
            break;
        case 4:
            cout << "Exiting..." << endl;// Exist  the program
            return 0;
        default:
            cout << "Invalid choice" << endl;// massage for invalid choise
        }
    }

    return 0;
}
