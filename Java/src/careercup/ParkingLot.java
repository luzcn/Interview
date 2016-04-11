package careercup;

import java.util.ArrayList;

//enum type for Vehicle
enum VehicleSize
{
	Motorcycle, Compact, Large,
}

abstract class Vehicle
{
	public VehicleSize size;
	public String licensePlate;
	public int spotsNeeded;

	ArrayList<ParkingSpot> spots = new ArrayList<>();

	/* Park vehicle in this spot (among others, potentially) */
	public void parkInSpot(ParkingSpot spot)
	{
		spots.add(spot);
	}

	/* Remove car from spot, and notify spot that it's gone */
	public void clearSpots()
	{
		for (int i = 0; i < spots.size(); i++)
		{
			spots.get(i).isAvailable = true;
			spots.get(i).vehicle = null;
		}
		spots.clear();
	}

	// this need to be implement in subclass
	public abstract boolean canFitInSpot(ParkingSpot spot);

	public abstract void print();
}

class Motorcycle extends Vehicle
{
	public Motorcycle()
	{
		size = VehicleSize.Motorcycle;
		spotsNeeded = 1;
	}

	@Override
	public boolean canFitInSpot(ParkingSpot spot)
	{
		return true;
	}

	@Override
	public void print()
	{

	}
}

class Car extends Vehicle
{
	public Car()
	{
		size = VehicleSize.Compact;
		spotsNeeded = 1;
	}

	@Override
	public boolean canFitInSpot(ParkingSpot spot)
	{
		return false;
	}

	@Override
	public void print()
	{
		// TODO Auto-generated method stub

	}
}

class Bus extends Vehicle
{
	public Bus()
	{
		size = VehicleSize.Large;
		spotsNeeded = 5;
	}

	@Override
	public boolean canFitInSpot(ParkingSpot spot)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void print()
	{
		// TODO Auto-generated method stub

	}
}

class ParkingSpot
{
	public void parkVehicle(Vehicle v)
	{
		v.parkInSpot(this);
		this.vehicle = v;
		this.isAvailable = false;
	}

	public VehicleSize size;
	public Vehicle vehicle;
	public boolean isAvailable;
}

/* Represents a level in a parking garage */
class Level
{
	public Level(int num_rows, int spots_per_row)
	{
		this.num_rows = num_rows;
		this.spots_per_row = spots_per_row;
		this.spotsAvailable = num_rows * spots_per_row;

		spots = new ParkingSpot[num_rows][spots_per_row];
	}

	public boolean parkVehicle(Vehicle v)
	{
		if (this.spotsAvailable < v.spotsNeeded)
			return false;

		return false;
	}

	private boolean findAvailable(Vehicle v)
	{
		this.parkInRow = -1;
		this.parkInStart = -1;
		this.parkInEnd = -1;

		for (int i = 0; i < num_rows; i++)
		{
			for (int j = 0; j < spots_per_row; j++)
			{
				if (v.canFitInSpot(spots[i][j]))
				{
					if (v.spotsNeeded == 1)
					{
						this.parkInRow = i;
						this.parkInStart = j;
						this.parkInEnd = j;
						return true;
					}
					else
					{
						if (j + 5 >= spots_per_row)
							return false;

						// Bus
						if (!v.canFitInSpot(spots[i][j]))
						{
							continue;
						}

					}
				}
			}
		}

		return false;
	}

	private ParkingSpot[][] spots;
	private int num_rows;
	private int spots_per_row;
	private int spotsAvailable;

	private int parkInRow;
	private int parkInStart;
	private int parkInEnd;
}

public class ParkingLot
{

	// @param n number of levels
	// @param num_rows each level has num_rows rows of spots
	// @param spots_per_row each row has spots_per_row spots
	public ParkingLot(int n, int num_rows, int spots_per_row)
	{
		// Write your code here
		levels = new Level[n];
		for (int i = 0; i < n; i++)
		{
			levels[i] = new Level(num_rows, spots_per_row);
		}
	}

	// Park the vehicle in a spot (or multiple spots)
	// Return false if failed
	public boolean parkVehicle(Vehicle vehicle)
	{

		return true;
	}

	// unPark the vehicle
	public void unParkVehicle(Vehicle vehicle)
	{
		vehicle.clearSpots();
	}

	private Level[] levels;
}