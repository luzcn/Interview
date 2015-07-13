#pragma once
#include "stdafx.h"

namespace DesignPattern
{
    template<typename T>
    class IObserver
    {
    public:
        virtual void Print(const T&) = 0;
    };

    template<typename T>
    class IObervable
    {
    public:
        virtual void Register(IObserver<T>*) = 0;
        virtual void Unregister(IObserver<T>*) = 0;
        virtual void Update(const T&) = 0;
    };

    template < typename T>
    class Provider : public IObervable<T>
    {
    public:
        void Register(IObserver<T>* ob)
        {
            if (std::find(m_list.begin(), m_list.end(), ob) == m_list.end())
                m_list.push_back(ob);
        }

        void Unregister(IObserver<T>* ob)
        {
            m_list.erase(std::remove(m_list.begin(), m_list.end(), ob));
        }

        void Update(const T& value)
        {
            for (IObserver<T>* t : m_list)
            {
                t->Print(value);
            }
        }

    private:
        vector<IObserver<T>*> m_list;
    };

    template<typename T>
    class Reporter : public IObserver<T>
    {
    public:
        Reporter(string name)
            :m_name(name)
        {}

        void Print(const T& value)
        {
            cout << m_name << " has changed value to: " << value << endl;
        }
    private:
        string m_name;
    };

}

#if 0
int _tmain(int argc, _TCHAR* argv[])
{
    using namespace DesignPattern;
    Provider<int> p;
    Reporter<int> r1("reporter1");
    Reporter<int> r2("reporter2");
    Reporter<int> r3("reporter3");

    p.Register(&r1);
    p.Register(&r2);
    p.Register(&r3);

    p.Update(2);

    p.Unregister(&r2);

    p.Update(3);
    return 0;
}
#endif