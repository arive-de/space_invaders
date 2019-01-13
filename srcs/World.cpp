/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:00:59 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 10:51:17 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/World.hpp"

World::World(Player &player, Enemy **enemy) : _player(player), _enemy(enemy)
{
    for (int i = 0; i < W_Y; i++)
        for (int j = 0; j < W_X; j++)
            this->_grid[i][j] = ' '; 
    this->_grid[this->_player.getYPosition()][this->_player.getXPosition()] = '>';

        for (int j = 0; j < NB_ENMY; j++)
        {
            if (this->_enemy[j]->getYPosition() < W_Y && this->_enemy[j]->getXPosition() < W_X)
                this->_grid[this->_enemy[j]->getYPosition()][this->_enemy[j]->getXPosition()] = '@';
        }
}

void World::checkEnemyProjectiles()
{
    // int x(0);
    // int y(0);

    for (int i = 0; i < NB_ENMY; i++)
    {
        if (this->_enemy[i])
        {
            if (this->_enemy[i]->getXPosition() - 1 <= 0)
            {
                delete this->_enemy[i];
                this->_enemy[i] = NULL;
            }
            else
            {
                this->_enemy[i]->decremXPosition();
                if (this->_enemy[i]->getXPosition() == this->_player.getXPosition() && this->_enemy[i]->getYPosition() == this->_player.getYPosition())
                {
                    this->_player.takeDamage(5000);
                    break;
                }
                // for (int j = 0; j < NB_PROJ; j++)
                // {
                //         Projectile *proj = this->_enemy[i]->getProjectile(j);
                //         y = proj->getY();
                //         x = proj->getX() - 1;
                //         if (x == 0)
                //         {
                //             delete proj;
                //             proj = NULL;
                //         }
                //         else if (y == this->_player.getYPosition() && x == this->_player.getXPosition())
                //         {
                //             this->_player.takeDamage(1);
                //             delete proj;
                //             proj = NULL;
                //         }
                //         else 
                //         {
                //             proj->setX(x);
                //             this->_grid[y][x] = '-';
                //         }
                // }
            }
        }

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
        for (int j = 0; j < NB_ENMY; j++)
        {
            if (x == W_X)
            {
                delete proj;
                proj = NULL;
                break ;
            }
            else if (y == this->_enemy[j]->getYPosition() && x == this->_enemy[j]->getXPosition())
            {
                delete proj;
                proj = NULL;
                delete this->_enemy[j];
                this->_enemy[j] = NULL;
                break ;
            }
            
        }
        if (proj != NULL) 
        {
            proj->setX(x);
            this->_grid[y][x] = '-';
        }
    }
}

char    World::getCharGrid(int y, int x)
{
    return this->_grid[y][x];
}

void World::printEnemy()
{
    for (int i = 0; i < NB_ENMY; i++)
    {
        if (this->_enemy[i])
        this->_grid[this->_enemy[i]->getYPosition()][this->_enemy[i]->getXPosition()] = '@';
    }
}

void World::makeTheRules()
{
    std::cout << "WORLD" << std::endl;
    for (int i = 0; i < W_Y; i++)
        for (int j = 0; j < W_X; j++)
            this->_grid[i][j] = ' ';

    this->checkEnemyProjectiles();
    // this->checkPlayerProjectiles();
    this->printEnemy();
}
