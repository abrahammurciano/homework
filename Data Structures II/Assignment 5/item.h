#ifndef item_h
#define item_h

#include <list>
#include <string>

class item {
  private:
	std::string name;
	std::list<int> clients;

  public:
	item();
	item(std::string name);
};

#endif
