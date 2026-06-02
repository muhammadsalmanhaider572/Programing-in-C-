#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the progress bar
void displayProgressBar(int completed, int total) {
    cout << "\nProgress: [";
    
    // If there are no tasks, progress is 100%
    if (total == 0) {
        cout << "████████████████████] 100%\n";
        return;
    }

    // Calculate percentage and how many blocks to fill (out of 20)
    double percentage = ((double)completed / total) * 100;
    int blocks = percentage / 5; 

    for (int i = 0; i < 20; i++) {
        if (i < blocks) {
            cout << "█"; // Filled block
        } else {
            cout << " "; // Empty space
        }
    }
    cout << "] " << (int)percentage << "%\n";
}

int main() {
    vector<string> tasks;
    vector<bool> completedStatus; // Keeps track of whether a task is done (true/false)
    int choice;

    do {
        cout << "\n=========================" << endl;
        cout << "       TO-DO LIST        " << endl;
        cout << "=========================" << endl;

        // Calculate completed tasks
        int completedCount = 0;
        for (bool status : completedStatus) {
            if (status) completedCount++;
        }

        // Show Progress Bar
        displayProgressBar(completedCount, tasks.size());
        cout << "-------------------------" << endl;

        // Display Menu
        cout << "1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete a Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Fixes cin issues when mixing numbers and strings
        cin.ignore(); 

        if (choice == 1) {
            // VIEW TASKS
            cout << "\n--- CURRENT TASKS ---" << endl;
            if (tasks.empty()) {
                cout << "Your list is empty!" << endl;
            } else {
                for (size_t i = 0; i < tasks.size(); i++) {
                    string status = completedStatus[i] ? "[✓]" : "[ ]";
                    cout << i + 1 << ". " << status << " " << tasks[i] << endl;
                }
            }
        } 
        else if (choice == 2) {
            // ADD TASK
            cout << "\nEnter the task description: ";
            string newTask;
            getline(cin, newTask);
            
            tasks.push_back(newTask);
            completedStatus.push_back(false); // New tasks are not completed by default
            cout << "Task added successfully!" << endl;
        } 
        else if (choice == 3) {
            // MARK COMPLETED
            if (tasks.empty()) {
                cout << "\nNo tasks to mark as completed." << endl;
            } else {
                int taskNum;
                cout << "\nEnter the task number to mark as completed: ";
                cin >> taskNum;
                
                if (taskNum > 0 && taskNum <= tasks.size()) {
                    completedStatus[taskNum - 1] = true;
                    cout << "Task marked as completed!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
            }
        } 
        else if (choice == 4) {
            // DELETE TASK
            if (tasks.empty()) {
                cout << "\nNo tasks to delete." << endl;
            } else {
                int taskNum;
                cout << "\nEnter the task number to delete: ";
                cin >> taskNum;

                if (taskNum > 0 && taskNum <= tasks.size()) {
                    tasks.erase(tasks.begin() + (taskNum - 1));
                    completedStatus.erase(completedStatus.begin() + (taskNum - 1));
                    cout << "Task deleted successfully!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
            }
        }

    } while (choice != 5);

    cout << "\nGoodbye! Have a productive day." << endl;
    return 0;
}