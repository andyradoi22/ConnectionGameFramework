#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <windows.h>

class Player
{
public:
	enum class Color : uint16_t 
	{
		white,
		brown,
		cream,
		blue, 
		red, 
		black,
		yellow, 
		pink, 
		purple,
		orange,
		green
	};

	Player() = default;
	~Player() = default;
	Player(const Player&) = default;
	Player(const std::string&, const Color&);

	const Color& GetColor();
	void SetColor(const Player::Color&);
	void SetName(const std::string& name) { m_name = name; }
	std::string& GetName() { return m_name; }
	friend std::ostream& operator <<(std::ostream&, const Color&);
	friend std::ostream& operator <<(std::ostream&, const Player&);

protected:
	Color m_color;
	std::string m_name;
};

inline std::ostream& operator<<(std::ostream& print, const Player::Color& colour)
{
	switch (colour)
	{
	case Player::Color::white:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		print << "White";
		break;
	}

	case Player::Color::brown:
	{   		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 390);

	print << "Brown";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	break;
	}

	case Player::Color::cream:
	{   		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 232);

	print << "Cream";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	break;
	}

	case Player::Color::blue:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 19);

		print << "Blue";
		break;
	}
	case Player::Color::red:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);

		print << "Red";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);

		print << "Black";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::yellow:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);

		print << "Yellow";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::pink:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 206);

		print << "Pink";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::purple:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95);

		print << "Purple";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::orange:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 108);

		print << "Orange";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	case Player::Color::green:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 43);

		print << "Green";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		break;
	}
	}
	return print;
}
inline std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name;
	return out;
}

inline Player::Player(const std::string& name, const Player::Color& color)
	:m_name(name), m_color(color)
{
}

inline const Player::Color& Player::GetColor()
{
	return m_color;
}

inline void Player::SetColor(const Player::Color& c)
{
	m_color = c;
}
