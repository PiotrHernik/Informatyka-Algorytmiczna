#pragma once

class Location
{
public:
    Location(const int line, const int column) : line_(line), column_(column) {}
    virtual ~Location() = default;
    int getLine() const
    {
        return line_;
    }
    int getColumn() const
    {
        return column_;
    }

private:
    const int line_;
    const int column_;
};