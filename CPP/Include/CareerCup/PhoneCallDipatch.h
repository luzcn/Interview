#pragma once
#include "stdafx.h"

// Imagine you have a call center with three levels of employees : respondent, manager, and director.
// An incoming telephone call must be first allocated to a respondent who is free.
//
// If the respondent can't handle the call, he or she must escalate the call to a manager.
//
// If the manager isnot free or notable to handle it, then the call should be escalated to a director.
// 
// Design the classes and data structures for this problem.
//
// Implement a method dispatchCaLL() which assigns a call to the first available employee

namespace careercup
{
    class PhoneCall
    {
    public:
        string phoneNumber;
    };

    enum Rank
    {
        Director,
        Manager,
        Respondent
    };

    class Employee
    {
    public:
        Employee(Rank level, Employee* reportTo)
            :employeeLevel(level), reportToEmployee(reportTo)
        {}

        bool receivePhoneCall(PhoneCall call)
        {
            if (isFree)
            {
                isFree = false;
                return true;
            }

            return false;
        }

        void completePhoneCall()
        {
            isFree = true;
        }

        Employee* reportsTo()
        {
            return reportToEmployee;
        }

        bool status()
        {
            return isFree;
        }
    private:
        PhoneCall m_call;
        Employee* reportToEmployee;

        bool isFree;
        Rank employeeLevel;
    };


    // A singleton class
    class CallHandler
    {
    public:
        static CallHandler& getInstance()
        {
            static CallHandler instance;
            return instance;
        }

        Employee* dispatchPhoneCall()
        {
            auto& call = queue_call.front();

            for (auto emp : receptions)
            {
                if (emp->status())
                {
                    while (emp && !emp->receivePhoneCall(call))
                    {
                        emp = emp->reportsTo();
                    }

                    if (emp)
                    {
                        // the phone call is answered by someone
                        // remove the call from queue
                        queue_call.pop();

                        return emp;
                    }
                }
            }

            return nullptr;
        }

    private:
        CallHandler()
        {
            // Init the receptions
            // there are 1 director, 2 manager and 10 respondent totally
            Employee director(Rank::Director, nullptr);

            Employee manager1(Rank::Manager, &director);
            Employee manager2(Rank::Manager, &director);

            for (int i = 0; i < 5; i++)
            {
                Employee respondent(Rank::Respondent, &manager1);
                receptions.push_back(&respondent);
            }

            for (int i = 0; i < 5; i++)
            {
                Employee respondent(Rank::Respondent, &manager2);
                receptions.push_back(&respondent);
            }
        }

        // only need to save the "respondent" level employee.
        vector<Employee*> receptions;
        queue<PhoneCall> queue_call;

        CallHandler(const CallHandler&) = delete;
        CallHandler& operator= (const CallHandler&) = delete;
    };
}