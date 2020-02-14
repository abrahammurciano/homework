#include "database.h"

database::database() : clients(1000), items(1000) {}

void database::insert(const client& c) {
	clients[c.id()] = c;
}

void database::insert(int id, std::string client_name, std::string phone) {
	insert(client(id, client_name, phone));
}

void database::insert(const item& i) {
	items[i.name()] = i;
}

void database::insert(const std::string& item_name) {
	insert(item(item_name));
}

void database::remove(int id) {
	clients.remove(id);
}

void database::remove(const std::string& item_name) {
	hash_map<std::string, item>::iterator i = items.find(item_name);
	if (!i) {
		throw std::runtime_error("Error: Could not remove item. No item exists with given key.");
	}
	items.remove(i);
}

void database::borrow_item(int client_id, std::string item_name) {
	if (!clients.find(client_id)) {
		throw std::runtime_error("Error: Cannot perform borrow operation. Specified client does not exist.");
	}
	if (!items.find(item_name)) {
		throw std::runtime_error("Error: Cannot perform borrow operation. Specified item does not exist.");
	}
	clients[client_id].borrow_item(item_name);
	items[item_name].borrow_item(client_id);
}

void database::return_item(int client_id, std::string item_name) {
	clients[client_id].return_item(item_name);
	items[item_name].return_item(client_id);
}

void database::print_clients(std::string item_name) const {
	try {
		std::list<int> client_ids = items[item_name].clients();
		for (std::list<int>::iterator i = client_ids.begin(); i != client_ids.end(); ++i) {
			client c = clients[*i];
			std::cout << c.id() << c.name() << c.phone() << std::endl;
		}
	} catch (std::runtime_error) {
	}
}