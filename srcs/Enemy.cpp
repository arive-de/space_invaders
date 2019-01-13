/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:59:49 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 15:59:25 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"

Enemy::Enemy(std::string name, int health, char enemyChar) : Agent(name, health)
{
    this->_enemyChar = enemyChar;
    this->_x = (rand() % W_X) + W_X;
    this->_y = rand() % W_Y;
    this->_projecSpeed = 2;
}

Enemy::~Enemy()
{
 
}

char Enemy::getEnemyChar()
{
    return this->_enemyChar;
}

void Enemy::takeDamage(size_t dmg)
{
    std::string buf;

    if (dmg < this->_health)
        this->_health -= dmg;
    else
        delete this;
}