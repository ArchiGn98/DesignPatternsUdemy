
// SOLID Design Principles
#include "Source/SOLID/SingleResponsibility.h"
#include "Source/SOLID/Open-Closed.h"
#include "Source/SOLID/LiskovSubstitution.h"
#include "Source/SOLID/DependencyInversion.h"

//Builder
#include "Source/Builder/Builder.h"


//Factories
#include "Source/Factories/HotDrinkFactory.h"
#include "Source/Factories/DrinkFactory.h"
#include "Source/Factories/HomeTaskFactory.h"
#include "Source/Factories/PointFactory.h"

//Prototype
#include "Source/Prototype/Prototype.h"
#include "Source/Prototype/HomeTaskPrototype.h"

//Singleton
#include "Source/Singleton/Singleton.h"
#include "Source/Singleton/SingletonDI.h"
#include "Source/Singleton/Monostate.h"

//Adapter
#include "Source/Adapter/Adapter.h"

//Bridge
#include "Source/Bridge/PersonB.h"
#include "Source/Bridge/Bridge.h"
#include "Source/Bridge/HomeTaskBridge.h"

//State
#include "Source/State/StateMachine.h"
#include "Source/State/HandmadeStateMachine.h"
#include "Source/State/HomeTaskState.h"

//GTEST
#include <gtest/gtest.h>



#define  _USE_MATH_DEFINES
#include <cmath>

using namespace std;

namespace solid {
  
    
    //Dependency Inversion Principle
    /*
     * A High-level modules should not depend on low-level modules.
     *   Both should depend on abstractions
     * B Abstractions should not depend on details.
     *   Details should depend on abstractions
    */
    int execute_dependency_inversion_principle() {
        Human parent{ "John" };
        Human child1{ "Matt" };
        Human child2{ "Chris" };

        Relationships relationships;
        relationships.add_parent_and_child(parent, child1);
        relationships.add_parent_and_child(parent, child2);

        Research research{ relationships };
        return 0;
    }


    //------------------------------------------</SOLID DESIGN PRINCIPLES>--------------------------------------------
}

namespace patterns {
    //--------------------------------------------------------<BUILDER PATTERN>---------------------------------------
/*
 * Class that build objects of another classes
 */
   
    //-----------------------------------------------</BUILDER PATTERN>------------------------------------------------
    int execute_builder_pattern() {
        HtmlBuilder builder("ul");
        builder.add_child("li", "hello").add_child("li", "world");

        HtmlElement element = HtmlElement::create("ul")
            .add_child("li", "hello2")
            .add_child("li", "world2").build();

        cout << builder.str();
        cout << element.str();

        return 0;
    }
    //-----------------------------------------------<FACTORIES>-------------------------------------------------------
/*
 * A component responsible for creation of objects
 */
    unique_ptr<HotDrink> make_drink(const string& type) {
        unique_ptr<HotDrink> drink;
        if (type == "tea") {
            drink = make_unique<Tea>();
            drink->prepare(200);
        }
        else {
            drink = make_unique<Cofee>();
        }
        return drink;
    }

    int execute_factory_pattern() {
        auto p = Point::factory.NewPolar(5, static_cast<float>(0.785398163397448309616)); // pi/4
        cout << p << endl;

        //auto drink = make_drink("tea");

        //Abstract factory
        DrinkFactory df;
        auto c = df.make_drink("coffee");

        // functional factory
        DrinkWithVolumeFactory drinkWithVolumeFactory;
        auto t = drinkWithVolumeFactory.make_drink("tea", 150);
        auto t2 = drinkWithVolumeFactory.make_drink("tea", 300);

        //Home task
        ManFactory pf;

        auto person = pf.create_person("Vova");
        auto person2 = pf.create_person("Dima");

        cout << person << endl << person2 << endl;

        return 0;
    }
    //-----------------------------------------------</FACTORIES>-------------------------------------------------------

    //-----------------------------------------------<PROTOTYPE>--------------------------------------------------------
    /*
     * Object that can be fully or partly constructed that you copy and make use of
     */
     // Prototype/Prototype.h
     // Prototype/HomeTask.h
    int execute_prototype_pattern() {
        //Prototype work example
        Contact john{ "John Doe", new Address{"123 Earst Dr", "London", 123} };
        //Contact jane{"Jane Smith", Address{"123 Earst Dr", "London", 103}};
        Contact jane{ john };
        jane.name = "Jane Smith";
        jane.address->suite = 103;
        cout << john << endl << jane << endl;

        //EmployeeFactory
        auto john2 = EmploeeFactory::new_main_office_employee("John", 123);
        cout << *john2 << endl;

        //Home Task
        Line line1{ new PointFromTask{10,15}, new PointFromTask{0, 7} };
        Line line2 = line1.deep_copy();
        line2.start->x = 40;
        cout << line1 << endl << line2 << endl;

        return 0;
    }
    //-----------------------------------------------</PROTOTYPE>--------------------------------------------------------

    //-----------------------------------------------<SINGLETON>--------------------------------------------------------
    /*
     * For some components it only make sense to have one in the system.
     *      *Database repository
     *      *Object Factory
     * The constructor call is expensive.
     * Want to prevent anyone creating additional copies.
     * Need to take care of lazy instantiation and thread safety.
     *
     * SINGLETON - a component which is instantiated only once
     */
     //



    int execute_singleton_pattern() {
        string city = "Tokyo";
        cout << city << " has population " <<
            SingletonDatabase::get().get_population(city) << endl;

        //SingletonDI
        cout << "================================" << endl;

        //This is an alternative to having your own singleton
        /*
        auto injector = boost::di::make_injector(
            boost::di::bind<IFoo>().to<Foo>().in(boost::di::singleton)
        );

        auto bar1 = injector.create<shared_ptr<Bar>>();
        auto bar2 = injector.create<shared_ptr<Bar>>();

        cout << bar1->foo->name() << endl;
        cout << bar2->foo->name() << endl;

        cout << boolalpha << (bar1->foo.get() == bar2->foo.get()) << endl;
        */        

        //Monostate
        cout << "================================" << endl;
        Printer p;
        p.set_id(10);
        int id = p.get_id();

        Printer p2;
        int id2 = p2.get_id();
        cout << id << " " << id2 << endl;
        return 0;
    }
    // gtests
    TEST(RecordFinderTests, SingletonTotalPopulationTest) {
        SingletonRecordFinder rf;
        vector<string> names{ "Kiev", "Tokyo" };
        int tp = rf.total_population(names);
        EXPECT_EQ(3320000 + 4000000, tp);
    }

    TEST(RecordFinderTests, DependantTotalPopulationTest) {
        DummyDatabase db;
        ConfigurableRecordFinder rf{ db };
        EXPECT_EQ(4, rf.total_population(vector<string>{"alpha", "gamma"}));
    }
    //-----------------------------------------------</SINGLETON>--------------------------------------------------------


    //-----------------------------------------------<ADAPTER>-----------------------------------------------------------
    /*
     * A construct which adapts an existing interface X
     * to conform to the required interface Y
     */


    TEST(SquareToRectangleAdapterTests, AdaptingTest) {
        int size{ 0 };
        Square2 square{ 10 };
        SquareToRectangleAdapter adapter{ square };
        if (adapter.width() == adapter.height()) {
            size = adapter.width();
        }
        EXPECT_EQ(square.side, size);
    }

    TEST(SquareToRectangleAdapterTests, AreaTest) {
        Square2 square{ 10 };
        SquareToRectangleAdapter adapter{ square };
        EXPECT_EQ(100, adapter.area());
    }

    int execute_adapter_pattern() {
        Square2 square{ 10 };
        SquareToRectangleAdapter rectangleAdapter{ square };
        cout << rectangleAdapter.area();
        return 0;
    }
    //-----------------------------------------------</ADAPTER>-----------------------------------------------------------


    //-----------------------------------------------<BRIDGE>-------------------------------------------------------------
    /*
     * Connecting components together through abstractions
     */

     //Shapes - circle, square
     //Renderer - raster, vector
     //2x2: RasterCircleRenderer , RasterSquareRenderer, VectorCircleRenderer, VectorSquareRenderer.
    int execute_bridge_pattern() {
        //Pimpl Idiom
        PersonB personB;
        personB.name = "Alex";
        personB.greet();

        //Bridge
        cout << "================================" << endl;
        RasterRenderer rr;
        Circle raster_circle{ rr, 10, 15, 5 };
        raster_circle.draw();
        raster_circle.resize(10);
        raster_circle.draw();

        VectorRenderer vr;
        Circle vector_circle{ vr, 3, 6, 2 };
        vector_circle.draw();

        //Home task
        cout << "================================" << endl;
        LineRenderer lr;
        TriangleH line_triangle{ lr };
        line_triangle.draw();

        PixelRenderer pr;
        SquareH pixel_square{ pr };
        pixel_square.draw();

        return 0;
    }
    //-----------------------------------------------</BRIDGE>-------------------------------------------------------------

    //-----------------------------------------------<STATE>---------------------------------------------------------------
    /*
     * The object behavior determined by its state. An object transitions from one state
     * to another(smth need to trigger transition)
     *
     * A formalized construct which manages states and transitions called a state machine.
     */
    int execute_state_pattern() {
        //Classic State Macine
        LightSwitch ls;
        ls.on();
        ls.off();
        ls.off();

        //Handmade State Machine
        /*cout << "===================================" << endl;
        map<StatePhone, vector<pair<Trigger, StatePhone>>> rules;

        rules[StatePhone::off_hook] = {
                {Trigger::call_dialed,      StatePhone::connecting},
                {Trigger::stop_using_phone, StatePhone::on_hook}
        };

        rules[StatePhone::connecting] = {
                {Trigger::hung_up,        StatePhone::off_hook},
                {Trigger::call_connected, StatePhone::connected}
        };

        rules[StatePhone::connected] = {
                {Trigger::left_message,   StatePhone::off_hook},
                {Trigger::hung_up,        StatePhone::off_hook},
                {Trigger::placed_on_hold, StatePhone::on_hold}
        };

        rules[StatePhone::on_hold] = {
                {Trigger::taken_off_hold, StatePhone::connected},
                {Trigger::hung_up,        StatePhone::off_hook}
        };

        StatePhone currentState{StatePhone::off_hook}, exitState{StatePhone::on_hook};

        while (true) {
            cout << "The phone is currently " << currentState << endl;
            select_trigger:
            cout << "Select a trigger" << endl;
            int i = 0;
            for (auto item : rules[currentState]) {
                cout << i++ << ". " << item.first << endl;
            }
            int input;
            cin >> input;
            if (input < 0 || (input + 1) > rules[currentState].size()) {
                cout << "Incorrect option. Try againg." << endl;
                goto select_trigger;
            }
            currentState = rules[currentState][input].second;
            if (currentState == exitState) break;
        }
        cout << "We are done using phone" << endl;*/

        //Home Task
        cout << "===================================" << endl;
        vector<int> combination{ 1, 2, 3, 4, 5 };
        CombinationLock lock{ combination };
        lock.enter_digit(1);
        lock.enter_digit(2);
        lock.enter_digit(3);
        lock.enter_digit(4);
        lock.enter_digit(5);
        lock.close();

        lock.enter_digit(2);
        lock.enter_digit(3);
        lock.enter_digit(4);
        lock.enter_digit(5);
        lock.enter_digit(6);
        lock.close();
        return 0;
    }

}
















