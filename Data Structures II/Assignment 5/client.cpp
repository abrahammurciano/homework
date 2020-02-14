#include "client.h"

client::client() {}

client::client(int id, const std::string& name, const std::string& phone) : _id(id), _name(name), _phone(phone) {}

int client::id() const {
	return _id;
}

std::string client::name() const {
	return _name;
}

std::string client::phone() const {
	return _phone;
}

void client::borrow_item(const std::string& item_name) {
	_items.push_back(item_name);
}

void client::return_item(const std::string& item_name) {
	_items.remove(item_name);
}

const std::list<std::string>& client::items() const {
	return _items;
}