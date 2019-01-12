/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:00:59 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 18:34:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/World.hpp"

World::World(Player &player, Enemy **enemy) : _player(player), _enemy(enemy)
{
}

void World::checkEnemyProjectiles()
{
    int x(0);
    int y(0);

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            this->_grid[this->_enemy[j]->getYPosition()][this->_enemy[j]->getXPosition()] = '@';
            if (this->_enemy[i]->getXPosition() == this->_player.getXPosition() && this->_enemy[i]->getYPosition() == this->_player.getYPosition())
                this->_player.takeDamage(5000);
            else 
            {
                Projectile *proj = this->_enemy[i]->getProjectile(j);
                y = proj->getY();
                x = proj->getX() - 1;
                if (x == W_X)
                {
                    delete proj;
                    proj = NULL;
                }
                else if (y == this->_player.getYPosition() && x == this->_player.getXPosition())
                {
                    this->_player.takeDamage(1);
                    delete proj;
                    proj = NULL;
                }
                else 
                {
                    proj->setX(x);
                    this->_grid[y][x] = '-';
                }
            }
        }
        this->_enemy[i]->incremXPosition();
        this->_enemy[i]->incremYPosition();
    }
    this->_grid[this->_player.getYPosition()][this->_player.getXPosition()] = '>';
}

void            World::checkPlayerProjectiles()
{
    int x(0);
    int y(0);

    
    for (int i = 0; i < 30; i++)
    {
        Projectile *proj = this->_player.getProjectile(i);
        y = proj->getY();
        x = proj->getX() + 1;
        for (int j = 0; j < 50; j++)
        {
            if (x == W_X)
            {
                delete proj;
                proj = NULL;
            }
            else if (y == this->_enemy[j]->getYPosition() && x == this->_enemy[j]->getXPosition())
            {
                this->_grid[this->_enemy[j]->getYPosition()][this->_enemy[j]->getXPosition()] = ' ';
                delete proj;
                proj = NULL;
                delete this->_enemy[j];
                this->_enemy[j] = NULL;
            }
            else 
            {
                proj->setX(x);
                this->_grid[y][x] = '-';
            }
        }
    }
}

void World::makeTheRules()
{
    for (int i = 0; i < W_Y; i++)
        for (int j = 0; j < W_X; i++)
            this->_grid[i][j] = ' ';
    this->checkEnemyProjectiles();
    this->checkPlayerProjectiles();
}
