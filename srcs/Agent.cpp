/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:18 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:43:48 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Agent.hpp"

Agent::Agent(std::string name, size_t health, World &world) : _name(name), _health(health), _world(world)
{

}

void Agent::fireProjectile()
{
    Projectile *projectile = new Projectile(this->_x, this->_y, this->_projecSpeed);
    for (int i = 0; i < 30; i++)
    {
        if (this->_projectile[i])
            this->_projectile[i] = projectile;
    }
}