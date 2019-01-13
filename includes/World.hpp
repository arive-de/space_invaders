/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:10:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 16:35:07 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

#include <string>
#include "Player.hpp"
#include "Alien.hpp"
#include "Spaceship.hpp"

#define W_Y 40
#define W_X 150

class World {

    public :
        World(Player &player, Spaceship **spaceships, Alien **aliens);
        ~World();
        void            makeTheRules();
        void            checkEnemyProjectiles(Alien **_aliens);
        void            checkEnemyProjectiles(Spaceship **_spaceships);
        void            checkPlayerProjectiles();
        void            getAgentPosition(Player& player);
        void            getAgentPosition(Enemy& enemy);
        char            getCharGrid(int y, int x);
        void            printEnemy();

    protected:
        char             _grid[W_Y][W_X];
        Player          &_player;
        Spaceship       **_spaceships;
        Alien           **_aliens;

    private:
};
#endif