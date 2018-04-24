/*
 *  Created on: April 20, 2018
 *  Author:     wrscode
 *  File:       ObserverPattern.cpp
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

struct IObserver
{
    virtual ~IObserver(){}
    virtual void update() = 0;
};

struct IObservables
{
    virtual ~IObservables()
    {
    }

    virtual void add(IObserver&) = 0;
    virtual void del(IObserver&) = 0;

    virtual void notify() = 0;
};

class MyObservables: public IObservables
{
public:
    MyObservables()
    {
    }

    void add(IObserver& Obr)
    {
        mObrs.push_back(&Obr);
    }

    void del(IObserver& Obr)
    {
        auto fitIt = std::find(mObrs.begin(), mObrs.end(), &Obr);
        if (fitIt != mObrs.end())
        {
            
            mObrs.erase(fitIt);
        }
    }

    void notify()
    {
        for (auto& It : mObrs)
        {
            if (It)
            {
                It->update();
            }
        }
    }

    void getData(){
        std::cout << "getData" << std::endl;
    }

private:
    std::vector<IObserver*> mObrs;

};

struct MyObserver : public IObserver
{
    MyObserver(MyObservables& Obles) : mObles{Obles}
    {
        mObles.add(*this);
    }

    virtual ~MyObserver()
    {
        mObles.del(*this);
    }

    void update(){
        mObles.getData();
    }

    MyObservables& mObles;
};


int main()
{
    MyObservables Obrles;
    MyObserver Obr0(Obrles);
    MyObserver Obr1(Obrles);


    Obrles.notify();
}
