/*
 *  Created on: April 20, 2018
 *  Author:     wrscode
 *  File:       StrategyPattern.cpp
 */

#include <iostream>
#include <string>
#include <memory>

struct IFlying
{
    using UPtr = std::unique_ptr<IFlying>;

    virtual ~IFlying()
    {
    }
    virtual void fly() = 0;
};

struct NoFlying :  public IFlying
{
    virtual void fly() override
    {
        std::cout << "no flying" << std::endl;
    }
};

struct IQuacking
{
    using UPtr = std::unique_ptr<IQuacking>;

    virtual ~IQuacking()
    {
    }
    virtual void quack() = 0;
};

struct NoQuacking :  public IQuacking
{
    virtual void quack() override {
        std::cout << "no quacking" << std::endl;
    }
};


struct IDisplaing
{
    using UPtr = std::unique_ptr<IDisplaing>;

    virtual ~IDisplaing()
    {
    }
    virtual void display() = 0;
};

struct NoDisplaing :  public IDisplaing
{
    virtual void display() override {
        std::cout << "no display" << std::endl;
    }
};

class Duck
{
public:
    Duck(std::string Name,
         IFlying::UPtr&&    Fly =   std::make_unique<NoFlying>(),
         IQuacking::UPtr&&  Quack = std::make_unique<NoQuacking>(),
         IDisplaing::UPtr&& Disp =  std::make_unique<NoDisplaing>())
         : mName(std::move(Name)),
           mFly{std::move(Fly)},
           mQuack{std::move(Quack)},
           mDisp{std::move(Disp)} {}


    void name()
    {
        std::cout << mName << std::endl;
    }

    void fly(){
        mFly->fly();
    }

    void quack (){
        mQuack->quack();
    }

    void display(){
        mDisp->display();
    }

private:
    std::string      mName;
    IFlying::UPtr    mFly;
    IQuacking::UPtr  mQuack;
    IDisplaing::UPtr mDisp;
};

class ClassicFlying : public IFlying
{
    virtual void fly() override
    {
        std::cout << "classic flying" << std::endl;
    }
};

class JetFlying : public IFlying
{
    virtual void fly() override
    {
        std::cout << "jet flying" << std::endl;
    }
};

class ClassicQuacking : public IQuacking
{
    virtual void quack() override
    {
        std::cout << "classic quacking" << std::endl;
    }
};

class SuperQuacking : public IQuacking
{
    virtual void quack() override
    {
        std::cout << "super quacking" << std::endl;
    }
};


int main(){

    Duck NoDuck("Empty Duck");

    Duck Duck2("Claasic Duck",
               std::make_unique<ClassicFlying>(),
               std::make_unique<ClassicQuacking>());

    Duck Duck3("Super Duck",
               std::make_unique<JetFlying>(),
               std::make_unique<SuperQuacking>(),
               std::make_unique<NoDisplaing>());

    NoDuck.name();
    NoDuck.fly();
    NoDuck.quack();
    NoDuck.display();

    Duck2.name();
    Duck2.fly();
    Duck2.quack();
    Duck2.display();

    Duck3.name();
    Duck3.fly();
    Duck3.quack();
    Duck3.display();

}