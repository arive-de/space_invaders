/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:59:49 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:49:43 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"

Enemy::Enemy(std::string name, World& world) : Agent(name, 1, world)
{
    this->_x = W_X;
    this->_y = rand() % W_Y;
    this->_projecSpeed = -4;
}

void Enemy::takeDamage(size_t dmg)
{
    std::string buf;

    if (dmg < this->_health)
        this->_health -= dmg;
    else
        delete this;
}