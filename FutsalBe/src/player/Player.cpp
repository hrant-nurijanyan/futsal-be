#include "Player.hpp"

namespace Futsal
{

Player::Player( const std::string& id, const std::string& name, const std::string& surname, const std::string& avatarUrl )
    : id( id )
    , name( name )
    , surname( surname )
    , avatarUrl( avatarUrl )
{
}

const std::string& Player::getId() const
{
    return id;
}

const std::string& Player::getName() const
{
    return name;
}

const std::string& Player::getSurname() const
{
    return surname;
}

const std::string& Player::getAvatarUrl() const
{
    return avatarUrl;
}

} // namespace Futsal
