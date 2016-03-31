#pragma once
#include "stdafx.h"

// design a parking lot

// Assumptions:
//see CC150 OO Design for details.
// 1) n levels, each level has m rows of spots and each row has k spots.So each level has m x k spots.
// 2) The parking lot can park motorcycles, cars and buses
// 3) The parking lot has motorcycle spots, compact spots, and large spots
// 4) Each row, motorcycle spots id is in range[0, k / 4)(0 is included, k / 4 is not included),
//     compact spots id is in range[k / 4, k / 4 * 3) and large spots id is in range[k / 4 * 3, k].
// 5) A motorcycle can park in any spot
// 6) A car park in single compact spot or large spot
// 7) A bus can park in 5 large spots that are consecutive and within same row.it can not park in small spots
namespace careercup
{
    // enum type for Vehicle
    enum class VehicleSize
    {
        Motorcycle,
        Compact,
        Large
    };

    class Vehicle
    {
    public:
        string ID;
        VehicleSize size;
        int spotsNeeded;
    };

    class Bus : public Vehicle
    {
    public:
        Bus()
        {
            size = VehicleSize::Large;
            spotsNeeded = 5;
        }
    };

    class Car : public Vehicle
    {
    public:
        Car()
        {
            size = VehicleSize::Compact;
            spotsNeeded = 1;
        }
    };

    class Motorcycle : public Vehicle
    {
    public:
        Motorcycle()
        {
            size = VehicleSize::Motorcycle;
            spotsNeeded = 1;
        }
    };

    class ParkingSpot
    {
    public:
        ParkingSpot(VehicleSize type)
        {
            size = type;
            isAvailable = true;
        }

        bool canFit(Vehicle& v)
        {
            switch (v.size)
            {
            case VehicleSize::Motorcycle:
                return isAvailable;
            case VehicleSize::Compact:
                return isAvailable && size != VehicleSize::Motorcycle;
            case VehicleSize::Large:
                isAvailable && size == VehicleSize::Large;
            default:
                break;
            }
        }

        bool isAvailable;
    private:
        VehicleSize size;

    };

    class Level
    {
    public:
        Level(int num_rows, int spots_per_row)
        {
            spots = vector<vector<ParkingSpot>>(num_rows);
            numsAvailable = num_rows* spots_per_row;

            for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < spots_per_row; j++)
                {
                    if (j < spots_per_row / 4)
                    {
                        spots[i].push_back({ VehicleSize::Motorcycle });
                    }
                    else if (j < spots_per_row / 4 * 3)
                    {
                        spots[i].push_back({ VehicleSize::Compact });
                    }
                    else
                    {
                        spots[i].push_back({ VehicleSize::Large });
                    }
                }
            }
        }

        bool parkVehicle(Vehicle& v)
        {

        }

    private:
        int numsAvailable;
        vector<vector<ParkingSpot>> spots;
        int parkingRow;
        vector<int> parkingPos;

        bool findAvailable(Vehicle& v)
        {
            if (numsAvailable < v.spotsNeeded)
                return false;

            parkingPos.clear();
            parkingRow = 0;
            for (int i = 0; i < spots.size(); i++)
            {
                for (int j = 0; j < spots[0].size(); j++)
                {
                    if (v.spotsNeeded == 1)
                    {
                        if (spots[i][j].canFit(v))
                        {
                            parkingRow = i;
                            parkingPos.push_back(j);

                            return true;
                        }
                    }
                    else
                    {
                        // Bus, need to find 5 consecutive large spots
                        if (j + 5 >= spots[0].size())
                            break;

                        for (int k = 0; k < 5; k++)
                        {
                            if (!spots[i][j + k].canFit(v))
                            {
                                //
                            }
                        }
                    }
                }
            }

            return false;
        }
    };

    class ParkingLot
    {
    public:
        // @param n number of leves
        // @param num_rows  each level has num_rows rows of spots
        // @param spots_per_row each row has spots_per_row spots
        ParkingLot(int n, int num_rows, int spots_per_row)
        {
            for (int i = 0; i < n; i++)
            {
                levels.push_back({ num_rows, spots_per_row });
            }
        }

        // Park the vehicle in a spot (or multiple spots)
        // Return false if failed
        bool parkVehicle(Vehicle &vehicle)
        {
            // Write your code here
            for (int i = 0; i < levels.size(); i++)
            {
                if (!levels[i].parkVehicle)
                    return false;
            }

            return true;
        }

        // unPark the vehicle
        void unParkVehicle(Vehicle &vehicle)
        {
            
        }

    private:
        vector<Level> levels;
    };
}