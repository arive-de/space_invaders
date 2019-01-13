/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:14 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 10:52:02 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"

Player::Player(std::string name) : Agent(name, 5)
{
    this->_x = 1;
    this->_y = W_Y / 2;
    this->_projecSpeed = 2;
}

Player::~Player()
{

}

void Player::replay(bool r)
{
    if (r == true)
        this->_health = 5;
    else
    {
        delete this;
    }
}

void Player::takeDamage(size_t dmg)
{
    std::string buf;
    this->_health -= dmg;
    // else
    // {
    //     std::cout << "REPLAY? y/n" << std::endl;
    //     getline(std::cin, buf);
    //     if (buf == "y")
    //         replay(true);
    //     else
    //         replay(false);
    // }
}


