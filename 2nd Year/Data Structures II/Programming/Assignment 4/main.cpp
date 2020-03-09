#include "graph.h"
#include <iostream>
#include <list>
#include <string>

int main() {

	graph tasks;

	std::cout << "Choose one of the following:" << std::endl;
	std::cout << "1 - to add a task" << std::endl;
	std::cout << "2 - to add a priority rule" << std::endl;
	std::cout << "3 - to print all the graph" << std::endl;
	std::cout << "4 - print a recommended task order" << std::endl;
	std::cout << "5 - exit" << std::endl;

	char c;
	do {
		try {
			std::cin >> c;
			if (c == '1') {	 // Insert a task
				std::cout << "Enter the task you want to add" << std::endl;
				std::string task;
				std::cin >> task;
				tasks.insert(task);
			} else if (c == '2') {	// Link two tasks by chronological order
				std::cout << "Enter earlier task and the later task" << std::endl;
				std::string early, late;
				std::cin >> early >> late;
				tasks.link(early, late);
			} else if (c == '3') {	// Print the graph
				std::cout << "The graph:" << std::endl;
				tasks.print();
			} else if (c == '4') {	// Topologically sort the graph
				std::cout << "The recommended order:" << std::endl << "order:";
				std::list<std::string> ordered_tasks = tasks.topological_sort();
				// Print the sorted list
				for (std::list<std::string>::iterator i = ordered_tasks.begin(); i != ordered_tasks.end(); ++i) {
					std::cout << ' ' << *i;
				}
				std::cout << std::endl;
			} else if (c == '5') {
				std::cout << "byebye" << std::endl;
			}
		} catch (std::exception e) {
			std::cout << "ERROR" << std::endl;
		}
	} while (c != '5');

	return 0;
}
