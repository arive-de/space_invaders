/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:56:24 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 18:37:19 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include <iostream>
#include "Projectile.hpp"

#define W_Y 40
#define W_X 150

class Agent {
    public :
        Agent();
        Agent(std::string name, size_t health);
        ~Agent();
        Projectile* & getProjectile(int i);
        void fireProjectile();
        int  getXPosition();
        int  getYPosition();
        void  incremXPosition();
        void  incremYPosition();
    protected:
        std::string     _name;
        size_t          _health;
        int             _projecSpeed;
        Projectile      *_projectile[30];
        int             _x;
        int             _y;
        int             _nbProjec;
    private:
		Agent	&operator=(const Agent &);
		Agent(const Agent &);


};

#endif