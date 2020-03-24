#ifndef item_h
#define item_h

#include <list>
#include <string>

class item {
  private:
	std::string _name;
	std::list<int> _clients;

  public:
	item();
	item(std::string name);

	std::string name() const;
	const std::list<int>& clients() const;

	void borrow_item(int client_id);
	void return_item(int client_id);
};

#endif
