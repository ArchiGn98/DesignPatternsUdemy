//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_INTERFACESEGREGATION_H
#define DESIGNPATTERNS_INTERFACESEGREGATION_H

#include <string>

struct Document;

// If you need to implement only one function this approach is not correct
struct IBadMachine
{ 
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

//It must be done like this

struct IPrinter
{
    virtual std::string print() = 0;
};

struct IScanner
{
    virtual std::string scan() = 0;
};

struct IFax
{
    virtual void fax() = 0;
};

struct Printer : IPrinter
{
    std::string print() override
    {
        //do smth
        return "print";
    }
};

struct Scanner : IScanner
{
    std::string scan() override
    {
        //do smth
        return "scan";
    }
};

struct IMashine : IPrinter, IScanner{};
struct Machine : IMashine
{
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer, IScanner &scanner) : printer{printer}, scanner{scanner}{}

    std::string print() override
    {
        return printer.print();
    }

    std::string scan() override
    {
        return scanner.scan();
    }
};

#endif //DESIGNPATTERNS_INTERFACESEGREGATION_H
