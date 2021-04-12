//
// Created by artig on 24.01.2019.
//

#ifndef DESIGNPATTERNS_DRINKFACTORY_H
#define DESIGNPATTERNS_DRINKFACTORY_H

#include "HotDrinkFactory.h"
#include <map>
#include <functional>
using namespace std;

class DrinkFactory{ // abstract factory
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory() {
        hot_factories["coffee"] = make_unique<CofeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name){
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};


class DrinkWithVolumeFactory{ // functional factory
    map<string, function<unique_ptr<HotDrink>()>> factories;
public:
    int volume{200};
    DrinkWithVolumeFactory(){
        factories["tea"] = [this] {
            auto tea = make_unique<Tea>();
            tea->prepare(volume);
            return tea;
        };
        factories["coffee"] = [this] {
            auto coffee = make_unique<Cofee>();
            coffee->prepare(volume);
            return coffee;
        };
    }
    unique_ptr<HotDrink> make_drink(const string &name, int volume){
        this->volume = volume;
        return factories[name]();
    }
};





//-------------------------------------------------From book\

// interface click()
struct Clickable {
    virtual void click() = 0;
};
struct Sizeable {
    int w, h;
    Sizeable(int widht, int height) : w{ widht }, h{ height } {cout << "Size" << endl; }
};

struct Btn : public Clickable, public Sizeable {
    static int counter;
    virtual ~Btn() = default;
    Btn(int widht, int height) : Sizeable(widht, height) { cout << "Btn" << endl; ++counter;  }
};
int Btn::counter = 0;

struct CheckBox : public Clickable, public Sizeable {
    static int counter;
    virtual ~CheckBox() = default;
    CheckBox(int widht, int height) : Sizeable(widht, height) { cout << "checkBox" << endl; ++counter; }
};
int CheckBox::counter = 0;

struct WinBtn : public Btn {
    void click() override {
        cout << "WinBtn clicked" << endl;
    }
    WinBtn() = default;
    WinBtn(int widht, int height) : Btn(widht, height) { cout << "WinBtn" << endl; }
};


struct MacBtn : public Btn {
    void click() override {
        cout << "MacBtn clicked" << endl;
    }
    MacBtn(int widht, int height) : Btn(widht, height) { cout << "MacBtn" << endl; }
};

struct MacCheckBox : CheckBox {
    void click() override {
        cout << "MacCheckBox clicked" << endl;
    }
    MacCheckBox(int widht, int height) : CheckBox(widht, height) { cout << "MacCheckBox" << endl; }
};

struct WinCheckBox : CheckBox {
    void click() override {
        cout << "WinCheckBox clicked" << endl;
    }
    WinCheckBox(int widht, int height) : CheckBox(widht, height) { cout << "WinCheckBox" << endl; }
};

// Factory Interface
struct GUIFactory {
    virtual Btn* createButton() = 0;
    virtual CheckBox* createCheckbox() = 0;
};

struct WinFactory : GUIFactory {
    virtual Btn* createButton() override {
        return new WinBtn(400, 200);
    }
    virtual CheckBox* createCheckbox() override {
        return new WinCheckBox(40, 40);
    }
};

struct MacFactory : GUIFactory {
    virtual Btn* createButton() override {
        return new MacBtn(300, 100);
    }
    virtual CheckBox* createCheckbox() override {
        return new MacCheckBox(35, 35);
    }
};

struct App {
    GUIFactory* factory;
    vector<Btn*> buttons;
    vector<CheckBox*> checkBoxes;

    App() {
        enum { Windows = 1, MacOS = 2 };
        int os;
        cout << "Choose your system:" << endl
            << "(1) Windows" << endl
            << "(2) MacOS" << endl;
        cin >> os;
        if (os == Windows) factory = new WinFactory();
        if (os == MacOS) factory = new MacFactory();
    }
    void createUI() {
        buttons.push_back(factory->createButton());
        checkBoxes.push_back(factory->createCheckbox());
    }

    void addBtn() {
        buttons.push_back(factory->createButton());
    }

    void addCheckBox() {
        checkBoxes.push_back(factory->createCheckbox());
    }

    friend ostream& operator <<(ostream& os, const App& app) {
        os << "Buttons" << Btn::counter << ":" << endl;
        for (auto btn : app.buttons) {
            os << "Button" << btn << endl;
            os << "w: " << btn->w << endl
                << "h: " << btn->h << endl;
        }
        os << "Checkboxes " << CheckBox::counter << ":"<< endl;
        for (auto ch : app.checkBoxes) {
            os << "Checkbox" << ch << endl;
            os << "w: " << ch->w << endl
                << "h: " << ch->h << endl;
        }
        return os;
    }
};


#endif //DESIGNPATTERNS_DRINKFACTORY_H
