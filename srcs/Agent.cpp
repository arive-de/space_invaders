/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:18 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 18:36:37 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Agent.hpp"

Agent::Agent(std::string name, size_t health) : _name(name), _health(health)
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

void     Agent::incremXPosition()
{
    this->_x++;
}

void     Agent::incremYPosition()
{
    this->_y++;
}

Projectile* & Agent::getProjectile(int i)
{
    return this->_projectile[i];
}

void Agent::fireProjectile()
{
    if (this->_nbProjec < 30)
    {
        Projectile *projectile = new Projectile(this->_x, this->_y, this->_projecSpeed);
        for (int i = 0; i < 30; i++)
        {
            if (this->_projectile[i])
                this->_projectile[i] = projectile;
        }
        this->_nbProjec += 1;
    }
    
}