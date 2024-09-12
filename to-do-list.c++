#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task
{
    string description;
    bool isCompleted;
};

void addTask(Task tasks[], int &taskCount, string description)
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full\n";
        return;
    }
    tasks[taskCount].description = description;
    tasks[taskCount].isCompleted = false;
    taskCount++;
    cout << "Task added: " << description << "\n";
}

void viewTasks(const Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks in the list\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < taskCount; i++)
    {
        cout << i + 1 << ". " << tasks[i].description << " ["
             << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted(Task tasks[], int taskCount, int index)
{
    if (index < 1 || index > taskCount)
    {
        cout << "Invalid task number\n";
        return;
    }

    tasks[index - 1].isCompleted = true;
    cout << "Task marked as completed: " << tasks[index - 1].description << "\n";
}

void removeTask(Task tasks[], int &taskCount, int index)
{
    if (index < 1 || index > taskCount)
    {
        cout << "Invalid task number\n";
        return;
    }

    cout << "Task removed: " << tasks[index - 1].description << "\n";

    for (int i = index; i < taskCount; i++)
    {
        tasks[i - 1] = tasks[i];
    }

    taskCount--;
}

void showMenu()
{
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

int main()
{
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (true)
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(tasks, taskCount, description);
        }
        else if (choice == 2)
        {
            viewTasks(tasks, taskCount);
        }
        else if (choice == 3)
        {
            int taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            markTaskAsCompleted(tasks, taskCount, taskNumber);
        }
        else if (choice == 4)
        {
            int taskNumber;
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            removeTask(tasks, taskCount, taskNumber);
        }
        else if (choice == 5)
        {
            cout << "Exiting To-Do List Manager. Goodbye\n";
            break;
        }
        else
        {
            cout << "Invalid choice, please try again\n";
        }
    }

    return 0;
}
