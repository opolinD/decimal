#pragma once
#include<iostream>
#include<string>
class decimal {
protected:
	std::string num;
public:
	decimal() {
		num = "0.0";
	}
	decimal(std::string _num) :num(_num) {}
	decimal(const decimal& a) :num(a.num) {}
	std::string get_num();
	void set_num(std::string _num);
	int search_point();
	bool check_num();
	decimal operator+(decimal& b);
	decimal& operator =(const decimal& d);
	void cut_div();
	void swap(decimal& b);
	void align(decimal& b);
	decimal operator -(decimal& b);
	friend std::ostream& operator<<(std::ostream& out, const decimal& d);
	friend std::istream& operator>>(std::istream& out, decimal& d);
	/*void operator*(decimal& b) {
		cut_div();
		b.cut_div();
		decimal c_a(*this);
		decimal c_b(b);
		int pos1 = search_point();
		int pos2 = b.search_point();
		int len1 = num.length() - pos1 - 1;
		int len2 = b.num.length() - pos2 - 1;
		int len = len1 + len2;

	}*/
};
class s_decimal :public decimal {
public:
	s_decimal() {
		num = "0.0";
	}
	s_decimal(std::string _num) {
		num = _num;
	}
	s_decimal(const s_decimal& a) {
		num = a.num;
	}
	void short_num();
	s_decimal& operator =(const decimal& a);
};