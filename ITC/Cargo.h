#pragma once

enum CargoType
{
	Unknown,
	Ice

};

class Cargo
{
public:
	Cargo(CargoType type, unsigned int quantity)
	{
		Type = type;
		Quantity = quantity;
	}

	CargoType Type;
	unsigned int Quantity;
};