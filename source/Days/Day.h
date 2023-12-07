#pragma once

class Day
{
public:
	static constexpr int32_t MIN_ID = 1;
	static constexpr int32_t MAX_ID = 50;

public:
	static bool IsValidDayId(int32_t dayId);
	static Day* Create(int32_t dayId);

public:
	virtual ~Day() = default;

public:
	virtual void Execute() = 0;
	virtual void Print() const = 0;

private:

};