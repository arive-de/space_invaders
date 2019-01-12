/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:56:24 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:47:10 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include <iostream>
#include "Projectile.hpp"
#include "World.hpp"

class Agent {
    public :
        Agent();
        Agent(std::string name, size_t health, World& world);
        ~Agent();
        void fireProjectile();
    protected:
        std::string     _name;
        size_t          _health;
        int             _projecSpeed;
        Projectile      **_projectile;
        World           &_world;
        int             _x;
        int             _y;
    private:

};

#endif