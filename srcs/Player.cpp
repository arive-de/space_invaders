/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:14 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 15:43:19 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"

Player::Player(std::string name) : Agent(name, 5)
{
    this->_x = 0;
    this->_y = 5;
    this->_projecSpeed = 2;
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
    if (dmg < this->_health)
    {
        this->_health -= dmg;
    }
    else
    {
        std::cout << "REPLAY? y/n" << std::endl;
        getline(std::cin, buf);
        if (buf == "y")
            replay(true);
        else
            replay(false);
    }
}


