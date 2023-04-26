#include "Cdeciamal.h"
#include<iostream>
#include<string>
std::string decimal::get_num() {
	return num;
}
void decimal::set_num(std::string _num) {
	num = _num;
	if (check_num() == false) {
		std::cout << "Input again";
		std::cin >> num;
	}
}
int decimal::search_point() {
	std::string tmp;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') {
			return i;
		}
	}
}
bool decimal::check_num() {
	for (int i = 0; i < num.length() - 1; i++) {
		if (num[i] == '.' || (num[i] >= 48 && num[i] <= 57)) {}
		else {
			return false;
		}
	}
}
decimal decimal::operator+(decimal& b) {
	num = "0" + num;
	b.num = "0" + b.num;
	decimal result(*this);
	result.align(b);
	int um = 0;
	for (int i = result.num.length() - 1; i >= 0; i--) {
		if (result.num[i] == '.') {
			continue;
		}
		else {
			if ((int(result.num[i]) + int(b.num[i]) - 48 + um) > 57) {
				result.num[i] = (int(result.num[i]) + int(b.num[i]) + um) - 57 - 1;
				um = 1;
			}
			else {
				result.num[i] = (int(result.num[i]) + int(b.num[i])) - 48 + um;
				um = 0;
			}
		}
	}
	result.cut_div();
	b.cut_div();
	return result;
}
decimal& decimal::operator =(const decimal& d) {
	if (this != &d) {
		decimal tmp(d);
		this->swap(tmp);
	}
	return *this;
}
void decimal::cut_div() {
	do {
		if (num[0] == '0') {
			num.erase(0, 1);
		}
		else if (num[0] == '.') {
			num = '0' + num;
			break;
		}

	} while (num[0] == '0' || num[0] == '.');
	do {
		if (num[num.length() - 1] == '0') {
			num.pop_back();
		}
		else if (num[num.length() - 1] == '.') {
			num += '0';
			break;
		}
	} while (num[num.length() - 1] == '0' || num[num.length() - 1] == '.');
}
void decimal::swap(decimal& b) {
	std::swap(this->num, b.num);
}
void decimal::align(decimal& b) {
	int pos_p1 = search_point();
	int pos_p2 = b.search_point();
	int zn_aft_p1 = num.length() - (pos_p1 + 1);
	int zn_aft_p2 = b.get_num().length() - (pos_p2 + 1);
	int zn_to_p1 = pos_p1;
	int zn_to_p2 = pos_p2;
	if (zn_aft_p1 < zn_aft_p2) {
		for (int i = zn_aft_p1; i < zn_aft_p2; i++) {
			num += "0";
		}
	}
	else if (zn_aft_p1 > zn_aft_p2) {
		for (int i = zn_aft_p2; i < zn_aft_p1; i++) {
			b.num += "0";
		}
	}
	if (zn_to_p1 < zn_to_p2) {
		b.num = "0" + b.num;
		for (int i = zn_to_p1; i <= zn_to_p2; i++) {
			num = "0" + num;
		}
	}
	else if (zn_to_p1 > zn_to_p2) {
		num = "0" + num;
		for (int i = zn_to_p2; i <= zn_to_p1; i++) {
			b.num = "0" + b.num;
		}
	}
}
decimal decimal::operator -(decimal& b) {
	decimal result(*this);
	decimal copy_b(b);
	result.align(copy_b);
	int um = 0;
	bool a_bol = true;
	bool ravno = false;
	for (int i = 0; i < result.num.length(); i++) {
		if (int(result.num[i]) > int(copy_b.num[i])) {
			break;
		}
		else if (int(result.num[i]) < int(copy_b.num[i])) {
			a_bol = false;
			break;
		}
	}
	if (a_bol == false) {
		//второе больше
		result.swap(copy_b);
	}
	for (int i = result.num.length() - 1; i >= 0; i--) {
		if (result.num[i] == '.' || result.num[i] == '-') {
			continue;
		}
		else {
			if ((int(result.num[i]) - int(copy_b.num[i]) - um) >= 0) {
				result.num[i] = (int(result.num[i]) - int(copy_b.num[i]) - um) + 48;
				um = 0;
			}
			else {
				result.num[i] = (int(result.num[i]) - int(copy_b.num[i])) + 58 - um;
				um = 1;
			}
		}
	}
	result.cut_div();
	if (a_bol == false) {
		result.num = "-" + result.num;
	}
	return result;
}
std::ostream& operator<<(std::ostream& out, const decimal& d) {
	out << d.num;
	return out;
}
std::istream& operator>>(std::istream& in, decimal& d) {
	in >> d.num;
	return in;
}
void s_decimal::short_num() {
	cut_div();
	int differ = 0;
	int point_pos = search_point();
	num.erase(point_pos, 1);
	for (int i = 0; i < num.length() - 1; i++) {
		if (num[i] == '-') {
			continue;
		}
		else if (num[i] == '0') {
			continue;
		}
		else {
			num.insert(i + 1, ".");
			differ = i + 1 - point_pos;
			cut_div();
			if (differ != 0) {
				num += "*10^(" + std::to_string(-differ) + ')';
			}
			break;
		}
	}if (num == "00") {
		num = "0.0";
	}
}
s_decimal& s_decimal::operator =(const decimal& a) {
	decimal::operator=(a);
	short_num();
	return *this;
}