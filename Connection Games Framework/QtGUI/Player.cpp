#include "Player.h"


Player::Player(const QString& name, const Player::Color& color)
    :m_name(name), m_color(color)
{
}

const Player::Color& Player::GetColor()
{
    return m_color;
}

void Player::SetColor(const Player::Color& c)
{
    m_color = c;
}
