/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:18 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 11:39:44 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Agent.hpp"

Agent::Agent(std::string name, size_t health) : _name(name), _health(health)
{
    this->_nbProjec = 0;
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

void     Agent::incremXPosition()
{
    this->_x++;
}

void     Agent::incremYPosition()
{
    this->_y++;
}

void     Agent::decremXPosition()
{
    this->_x--;
}

void     Agent::decremYPosition()
{
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

void Agent::fireProjectile()
{
    if (this->_nbProjec < NB_PROJ)
    {
        Projectile *projectile = new Projectile(this->_x, this->_y, this->_projecSpeed);
        for (int i = 0; i < NB_PROJ; i++)
        {
            if (!this->_projectile[i])
            {
                this->_projectile[i] = projectile;
                break ;
            }
        }
        this->_nbProjec += 1;
    }
    
}