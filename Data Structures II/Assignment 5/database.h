#ifndef database_h
#define database_h

#include "client.h"
#include "hash_map.h"
#include "item.h"
#include <string>

class database {
  private:
	hash_map<int, client> clients;
	hash_map<std::string, item> items;

  public:
	database();

	void insert(const client& c);
	void insert(int id, std::string client_name, std::string phone);
	void insert(const item& i);
	void insert(const std::string& item_name);
	void remove(int id);
	void remove(const std::string& item_name);

	void borrow_item(int client_id, std::string item_name);
	void return_item(int client_id, std::string item_name);

	void print_clients(std::string item_name) const;
};

#endif
