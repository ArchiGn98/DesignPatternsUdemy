#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class HtmlBuilder;

struct HtmlElement {
	friend class HtmlBuilder;
	string name, text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement() = default;
	HtmlElement(const string& name, const string& text) : name{ name }, text{text} {}
	explicit HtmlElement(const string& name) : name{name} {}

public:

	const HtmlElement& operator=(const HtmlElement& other) {
		name = other.name;
		text = other.text;
		elements = other.elements;

		return *this;
	}

	string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;
		if (text.size() > 0)
			oss << string(indent_size * (indent + 1), ' ') << text << endl;
		for(const auto& element : elements){
			oss << element.str(indent + 1);
		}
		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}

	static HtmlBuilder create(const string& root_name);
};

class HtmlBuilder {
public:
	HtmlElement root;

	HtmlBuilder() = default;
	HtmlBuilder(string root_name) : root(root_name) {}
	HtmlBuilder(const HtmlBuilder& other) {
		root = other.root;
	}

	HtmlBuilder& add_child(const string& child_name, const string& child_text) {
		HtmlElement child(child_name, child_text);
		root.elements.emplace_back(child);
		return *this;
	}

	const HtmlBuilder& operator=(const HtmlBuilder& other) {
		root = other.root;
		return *this;
	}

	HtmlBuilder& build() {
		return *this;
	}

	string str() const {
		return root.str();
	}

	operator HtmlElement() const {
		return root;
	}

};

HtmlBuilder HtmlElement::create(const string& root_name) {
	return HtmlBuilder(root_name);
}
