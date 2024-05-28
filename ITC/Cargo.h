#pragma once

enum CargoType : uint8_t
{
	Unknown = 0,
	Ice = 1,
	Iron = 2,
	Helium = 3
};

struct Cargo
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