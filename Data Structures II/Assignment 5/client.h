#ifndef client_h
#define client_h

#include <list>
#include <string>

class client {
  private:
	int id;
	std::string name;
	std::string phone;
	std::list<std::string> items;

  public:
	client();
	client(int id, std::string name, std::string phone);
};

#endif
