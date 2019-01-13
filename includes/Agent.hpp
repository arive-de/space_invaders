/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:56:24 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 11:44:38 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include <iostream>
#include "Projectile.hpp"

#define W_Y 40
#define W_X 150

#define NB_ENMY 50
#define NB_PROJ 5

class Agent {
    public :
        Agent();
        Agent(std::string name, size_t health);
        ~Agent();
        Projectile*  getProjectile(int i);
        void fireProjectile();
        int  getXPosition();
        int  getYPosition();
        void  incremXPosition();
        void  incremYPosition();
        void  decremXPosition();
        void  decremYPosition();
        void  decremNbProj();
        int   getHealth();
        Projectile      *_projectile[NB_PROJ];

    protected:
        std::string     _name;
        size_t          _health;
        int             _projecSpeed;
        int             _x;
        int             _y;
        int             _nbProjec;
    private:
		Agent	&operator=(const Agent &);
		Agent(const Agent &);


};

#endif