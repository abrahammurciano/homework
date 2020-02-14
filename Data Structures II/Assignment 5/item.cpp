#include "item.h"

item::item() {}

item::item(std::string name) : _name(name) {}

std::string item::name() const {
	return _name;
}

void item::borrow_item(int client_id) {
	_clients.push_back(client_id);
}

void item::return_item(int client_id) {
	_clients.remove(client_id);
}

const std::list<int>& item::clients() const {
	return _clients;
}