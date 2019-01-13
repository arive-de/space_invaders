/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:59:49 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 19:45:49 by fmaury           ###   ########.fr       */
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
    for (int i = 0; i < NB_PROJ; i++)
    {
        if (this->_projectile[i])
        {
         delete this->_projectile[i];
         this->_projectile[i] = NULL;
        }
    }
}

char Enemy::getEnemyChar()
{
    return this->_enemyChar;
}

void Enemy::takeDamage(int dmg)
{
    std::string buf;

    if (dmg < this->_health)
        this->_health -= dmg;
    else
        delete this;
}