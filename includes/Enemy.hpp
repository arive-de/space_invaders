/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:11 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 16:49:41 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "Agent.hpp"

class Enemy : public Agent {
    public :
        Enemy();
        Enemy(std::string name, int health, char enemyChar);
        ~Enemy();
        char            getEnemyChar();
        void            takeDamage(int damage);

    protected:

    private:
        Enemy	&operator=(const Enemy &);
		Enemy(const Enemy &);
        char    _enemyChar;

};

#endif