#include "date.h"
#include <iostream>

class loan {
	friend std::istream& operator>>(std::istream& in, loan& l);
	friend std::ostream& operator<<(std::ostream& out, loan& l);

  private:
	int _borrower_id;
	std::string _name;
	date _loan_date;
	int _item_id;

  public:
	loan(int _borrower_id, std::string _name, date _loan_date, int _item_id);
	int borrower_id() const;
	std::string name() const;
	date loan_date() const;
	int item_id() const;
	void borrower_id(int _borrower_id);
	void name(std::string _name);
	void loan_date(date _date);
	void item_id(int _item_id);

	bool operator==(const loan& l) const;
	bool operator!=(const loan& l) const;
	bool operator<(const loan& l) const;
	bool operator<=(const loan& l) const;
	bool operator>(const loan& l) const;
	bool operator>=(const loan& l) const;
};

std::istream& operator>>(std::istream& in, loan& l);
std::ostream& operator<<(std::ostream& out, loan& l);