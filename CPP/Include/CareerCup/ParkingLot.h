#pragma once
#include "stdafx.h"

// design a parking lot

// Assumptions:
// 1. 
namespace careercup
{
    enum SlotType
    {
        Compact,        // compact size parking slot
        Regular,        // the regular size parking slot
        Handicapped,    // 
        ValetOnly,
    };

    class ParkingSlot
    {
    public:
        ParkingSlot(int level, int row, int position, SlotType type)
            :m_isOccupied(false), m_type(type)
        {
            m_id = to_string(level) + to_string(row) + to_string(position);
        }

        bool isAvailable()
        {
            return m_isOccupied;
        }

        string ID()
        {
            // for example:
            // "3E49" means the third floor Row E and No.49 slot
            return m_id;
        }
    private:
        string      m_id;
        bool        m_isOccupied;
        SlotType    m_type;
    };

    class ParkingLevel
    {
    public:
        ParkingLevel(int rows, int spaces)
            :m_rows(rows), m_spaceEachRow(spaces)
        {
        }

    private:
        const int           m_rows;
        const int           m_spaceEachRow;
        vector<ParkingSlot> m_slots;
    };

    // A parking lot has multiple parking levels
    class ParkingLot
    {
    public:
        ParkingLot(int levelNumbers)
        {
            m_levelList = vector<ParkingLevel>(levelNumbers, ParkingLevel(10, 50));
        }

    private:
        vector<ParkingLevel> m_levelList;
    };


    enum VehicleSize
    {
        Compact,
        Large,
        Motocycle
    };

    class Vehicle
    {
    public:
        Vehicle(string license, VehicleSize size, int sports)
            :m_licensePlate(license), m_size(size), m_sportsNeeded(sports)
        {}

        virtual ~Vehicle()
        {
        }

        int sportsNeeded()
        {
            return m_sportsNeeded;
        }

        VehicleSize getVehicleSize()
        {
            return m_size;
        }

        string licensePlate()
        {
            return m_licensePlate;
        }

        // parking the vehicle to the park slot
        // if failed to park, return false.
        bool parkIntoSport()
        {

        }

    protected:
        string m_licensePlate;
        int m_sportsNeeded;
        VehicleSize m_size;
    };
}