#pragma once

#include "Days/Day.h"

class Day1
    : public Day
{
public:
	typedef std::pair<int32_t, int32_t>(*ExtractionFunctionType)(const std::string& str);

public:
	virtual void Execute() final;
	virtual void Print() const final;

private:
	int32_t ExecuteInternal(const std::vector<std::string>& lines, ExtractionFunctionType fn) const;

private:
	int32_t m_ResultPart1{};
	int32_t m_ResultPart2{};
};