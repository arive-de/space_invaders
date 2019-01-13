/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:10:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 10:18:22 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

#include <string>
#include "Player.hpp"
#include "Enemy.hpp"

#define W_Y 40
#define W_X 150

class World {

    public :
        World(Player &player, Enemy **enemy);
        ~World();
        void            makeTheRules();
        void            checkEnemyProjectiles();
        void            checkPlayerProjectiles();
        void            getAgentPosition(Player& player);
        void            getAgentPosition(Enemy& enemy);
        char            getCharGrid(int y, int x);
        void            printEnemy();


    protected:
        char             _grid[W_Y][W_X];
        Player          &_player;
        Enemy           **_enemy;

    private:
};
#endif