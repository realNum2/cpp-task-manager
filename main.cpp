#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> tasks;
	vector<bool> done;

	while (true)
	{
		int action;
		cout << "===Task meanager===" << endl;
		cout << "\t 1. Add task" << "\n" << "\t 2. Show all task" << "\n" << "\t 3. show only active task"
			<< "\n" << "\t 4. Mark task as completed" << "\n" << "\t 5. Delete Task" << "\n" << "\t 0. Exit" << endl;
		
		cout << "What do u want to do? ";
		cin >> action;
		cin.ignore();

		if (action == 0)
		{
			cout << "Bye!" << endl;
			break;
		}

		switch (action)
		{
		case 1: {
			string task;
			cout << "Enter task: ";
			getline(cin, task);

			if (!task.empty()) {
				tasks.push_back(task);
				done.push_back(false);
				cout << "Task added" << endl;
			}
			break;
		}
			  
		case 2: {
			cout << "All your tasks: " << endl;

			for (size_t i = 0; i < tasks.size(); ++i) {
				string icon = done[i] ? "x" : " ";

				cout << "[" << icon << "] " << tasks[i] << endl;
			}
			break;
		}

		case 3: {
			cout << "All your active tasks: " << endl;

			for (size_t j = 0; j < tasks.size(); ++j) {
				if (!done[j]) {
					cout << tasks[j] << endl;
				}
			}
			break;
		}

		case 4: {
			int choice;
			cout << "Select the completed task from list: " << endl;

			for (size_t z = 0; z < tasks.size(); ++z) {
				string icon = done[z] ? "✔" : " ";

				cout << "[" << icon << "]" << tasks[z] << endl;
			}

			cin >> choice;
			cin.ignore();
			int index = choice - 1;

			if (index >= 0 && index < static_cast<int>(tasks.size())) {
				done[index] = true;

				cout << "Task " << "'" << tasks[index] << "' " << "marked as completed!" << endl;
			}
			else
			{
				cout << "Error: this task is not exist" << endl;
			}

			break;
		}

		case 5: {
			int deleteChoice;
			cout << "Select a task to delete: ";
			for (size_t x = 0; x < tasks.size(); ++x) {
				string icon = done[x] ? "✔" : " ";

				cout << "[" << icon << "]" << tasks[x] << endl;
			}
			cin >> deleteChoice;
			cin.ignore();
			int deleteIndex = deleteChoice - 1;

			if (deleteIndex >= 0 && deleteIndex < static_cast<int>(tasks.size())) {
				tasks.erase(tasks.begin() + deleteIndex);
				done.erase(done.begin() + deleteIndex);
			}
			break;
		}
			  
		default: 
			cout << "Unknown operatin :/" << endl;
			break;
		}
		
	}
}