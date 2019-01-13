/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:18 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 16:45:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Agent.hpp"

Agent::Agent(std::string name, size_t health) : _name(name), _health(health)
{
    this->_nbProjec = 0;
    for (int i = 0; i < NB_PROJ; i++)
        this->_projectile[i] = NULL;
}

Agent::~Agent() 
{

}

int     Agent::getXPosition()
{
    return this->_x;
}

int     Agent::getYPosition()
{
    return this->_y;
}

int     Agent::getHealth()
{
    return this->_health;
}

void     Agent::setHealth(int h)
{
    this->_health = h;
}

int     Agent::getProjecSpeed()
{
    return this->_projecSpeed;
}

void     Agent::incremXPosition()
{
    this->_x++;
}

void     Agent::incremYPosition()
{
    if (this->_y < W_Y - 1)
        this->_y++;
}

void     Agent::decremXPosition()
{
    this->_x--;
}

void     Agent::decremYPosition()
{
    if (this->_y > 0)
        this->_y--;
}

void     Agent::decremNbProj()
{
    this->_nbProjec--;
}

Projectile*  Agent::getProjectile(int i)
{
    return this->_projectile[i];
}

void Agent::fireProjectile(int y, int x)
{
    if (this->_nbProjec < NB_PROJ)
    {
        Projectile *projectile = new Projectile(x, y, this->_projecSpeed);
        for (int i = 0; i < NB_PROJ; i++)
        {
            if (!this->_projectile[i])
            {
                this->_projectile[i] = projectile;
                this->_nbProjec += 1;
                return ;
            }
        }
    }
    
}