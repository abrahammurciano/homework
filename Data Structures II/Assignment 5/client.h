#ifndef client_h
#define client_h

#include <iostream>
#include <list>
#include <string>

class client {
  private:
	int _id;
	std::string _name;
	std::string _phone;
	std::list<std::string> _items;

  public:
	client();
	client(int id, const std::string& name, const std::string& phone);

	int id() const;
	std::string name() const;
	std::string phone() const;
	const std::list<std::string>& items() const;

	void borrow_item(const std::string& item_name);
	void return_item(const std::string& item_name);
};

#endif
