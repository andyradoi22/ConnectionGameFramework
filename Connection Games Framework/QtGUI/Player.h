#pragma once
#include<iostream>
#include<vector>
#include<QString>

class Player
{
public:
    enum class Color : uint16_t {
            white, color1, color2
        };

    Player() = default;
    ~Player() = default;
    Player(const Player&) = default;
    Player(const QString&, const Color&);

    const Color& GetColor();
    void SetColor(const Player::Color&);
    void SetName(const QString& name) { m_name = name; }
    QString& GetName() { return m_name; }

protected:
    QString m_name;
    Color m_color;
};
