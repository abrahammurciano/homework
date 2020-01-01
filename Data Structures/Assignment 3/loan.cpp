#include "loan.h"
using namespace std;

loan::loan()
	: _borrower_id(0), _name(""), _item_id(0) {}

loan::loan(int _borrower_id, string _name, date _loan_date, int _item_id)
	: _borrower_id(_borrower_id), _name(_name), _loan_date(_loan_date), _item_id(_item_id) {}

int loan::borrower_id() const {
	return _borrower_id;
}

std::string loan::name() const {
	return _name;
}

date loan::loan_date() const {
	return _loan_date;
}

int loan::item_id() const {
	return _item_id;
}

void loan::borrower_id(int _borrower_id) {
	this->_borrower_id = _borrower_id;
}

void loan::name(std::string _name) {
	this->_name = _name;
}

void loan::loan_date(date _loan_date) {
	this->_loan_date = _loan_date;
}

void loan::item_id(int _item_id) {
	this->_item_id = _item_id;
}

loan& loan::operator=(const loan& l) {
	_borrower_id = l._borrower_id;
	_name = l._name;
	_loan_date = l._loan_date;
	_item_id = l._item_id;
	return *this;
}

bool loan::operator==(const loan& l) const {
	return borrower_id() == l.borrower_id() && name() == l.name() && loan_date() == l.loan_date() && item_id() == l.item_id();
}

bool loan::operator!=(const loan& l) const {
	return !(*this == l);
}

bool loan::operator<(const loan& l) const {
	if (loan_date() == l.loan_date()) {
		if (item_id() == l.item_id()) {
			return (borrower_id() < l.borrower_id());
		}
		return item_id() < l.item_id();
	}
	return loan_date() < l.loan_date();
}

bool loan::operator<=(const loan& l) const {
	return *this < l || *this == l;
}

bool loan::operator>(const loan& l) const {
	return !(*this <= l);
}

bool loan::operator>=(const loan& l) const {
	return !(*this < l);
}

istream& operator>>(istream& in, loan& l) {
	cout << "enter id name date item ";
	return in >> l._borrower_id >> l._name >> l._loan_date >> l._item_id;
}

ostream& operator<<(ostream& out, loan& l) {
	return out << endl
			   << "Lending details: id: " << l.borrower_id() << " name: " << l.name() << " date: " << l.loan_date() << " item: " << l.item_id() << endl;
}