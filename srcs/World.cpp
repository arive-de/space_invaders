/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:00:59 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 18:25:31 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/World.hpp"

World::World(Player &player, Spaceship **spaceships, Alien **aliens) : _player(player), _spaceships(spaceships), _aliens(aliens)
{
    for (int i = 0; i < W_Y; i++)
        for (int j = 0; j < W_X; j++)
            this->_grid[i][j] = ' '; 
    this->_grid[this->_player.getYPosition()][this->_player.getXPosition()] = '>';

        for (int j = 0; j < NB_SPACESHIPS; j++)
        {
            if (this->_spaceships[j]->getYPosition() < W_Y && this->_spaceships[j]->getXPosition() < W_X)
                this->_grid[this->_spaceships[j]->getYPosition()][this->_spaceships[j]->getXPosition()] = this->_spaceships[j]->getEnemyChar();
        }
        for (int j = 0; j < NB_ALIENS; j++)
        {
            if (this->_aliens[j]->getYPosition() < W_Y && this->_aliens[j]->getXPosition() < W_X)
                this->_grid[this->_aliens[j]->getYPosition()][this->_aliens[j]->getXPosition()] = this->_aliens[j]->getEnemyChar();
        }
}

World::~World()
{

}

void World::checkEnemyProjectiles(Alien **aliens)
{
    int x(0);
    int y(0);

    for (int i = 0; i < NB_ALIENS; i++)
    {
        if (aliens[i])
        {
            if (aliens[i]->getXPosition() - 1 <= 0)
            {
                delete aliens[i];
                aliens[i] = NULL;
            }
            else
            {
                aliens[i]->decremXPosition();
                if (aliens[i]->getXPosition() == this->_player.getXPosition() && aliens[i]->getYPosition() == this->_player.getYPosition())
                {
                    this->_player.takeDamage(5000);
                    return ;
                }
                for (int j = 0; j < NB_PROJ; j++)
                {
                    if (aliens[i]->_projectile[j])
                    {
                        y = aliens[i]->_projectile[j]->getY();
                        x = aliens[i]->_projectile[j]->getX();
                        if (y == this->_player.getYPosition() && x - aliens[i]->getProjecSpeed() <= 0)
                        {
                            this->_player.takeDamage(5);
                            aliens[i]->decremNbProj();
                            delete aliens[i]->_projectile[j];
                            aliens[i]->_projectile[j] = NULL;
                        }
                        else if (x - aliens[i]->getProjecSpeed() <= 0)
                        {
                            aliens[i]->decremNbProj();
                            delete aliens[i]->_projectile[j];
                            aliens[i]->_projectile[j] = NULL;
                        }
                        else 
                        {
                            aliens[i]->_projectile[j]->setX(x - aliens[i]->getProjecSpeed());
                            this->_grid[y][x] = '-';
                        }
                    }
                }
            }
        }

    }
    this->_grid[this->_player.getYPosition()][this->_player.getXPosition()] = '>';
}

void World::checkEnemyProjectiles(Spaceship       **spaceships)
{
    int x(0);
    int y(0);

    for (int i = 0; i < NB_SPACESHIPS; i++)
    {
        if (spaceships[i])
        {
            if (spaceships[i]->getXPosition() - 1 <= 0)
            {
                delete spaceships[i];
                spaceships[i] = NULL;
            }
            else
            {
                spaceships[i]->decremXPosition();
                if (spaceships[i]->getXPosition() == this->_player.getXPosition() && spaceships[i]->getYPosition() == this->_player.getYPosition())
                {
                    this->_player.takeDamage(5000);
                    return ;
                }
                for (int j = 0; j < NB_PROJ; j++)
                {
                    if (spaceships[i]->_projectile[j])
                    {
                        y = spaceships[i]->_projectile[j]->getY();
                        x = spaceships[i]->_projectile[j]->getX();
                        if (y == this->_player.getYPosition() && x - spaceships[i]->getProjecSpeed() <= 0)
                        {
                            this->_player.takeDamage(5);
                            spaceships[i]->decremNbProj();
                            delete spaceships[i]->_projectile[j];
                            spaceships[i]->_projectile[j] = NULL;
                        }
                        else if (x - spaceships[i]->getProjecSpeed() <= 0)
                        {
                            spaceships[i]->decremNbProj();
                            delete spaceships[i]->_projectile[j];
                            spaceships[i]->_projectile[j] = NULL;
                        }
                        else 
                        {
                            spaceships[i]->_projectile[j]->setX(x - spaceships[i]->getProjecSpeed());
                            this->_grid[y][x] = '-';
                        }
                    }
                }
            }
        }

    }
    this->_grid[this->_player.getYPosition()][this->_player.getXPosition()] = '>';
}

void            World::checkPlayerProjectiles()
{
    int x(0);
    int y(0);

    
    for (int i = 0; i < NB_PROJ; i++)
    {
        // Projectile *proj = this->_player.getProjectile(i);
        // Projectile *this->_player._projectile[i] = this->_player._projectile[i];
        if (this->_player._projectile[i])
        {
            y = this->_player._projectile[i]->getY();
            x = this->_player._projectile[i]->getX();
            for (int j = 0; j < NB_ALIENS; j++)
            {
                if (this->_aliens[j])
                {
                    if (x + 1 == W_X)
                    {
                        delete this->_player._projectile[i];
                        this->_player._projectile[i] = NULL;
                        this->_player.decremNbProj();
                        break ;
                    }
                    else if (y == this->_aliens[j]->getYPosition() && (x == this->_aliens[j]->getXPosition() || x + 1 == this->_aliens[j]->getXPosition()))
                    {
                        delete this->_player._projectile[i];
                        this->_player._projectile[i] = NULL;
                        this->_player.decremNbProj();
                        this->_aliens[j]->setHealth(this->_aliens[j]->getHealth() - 1);
                        if (this->_aliens[j]->getHealth() <= 0)
                        {
                            this->_grid[this->_aliens[j]->getYPosition()][this->_aliens[j]->getXPosition()] = '*';
                            delete this->_aliens[j];
                            this->_aliens[j] = NULL;
                        }
                        break ;
                    }
                }
            }
            for (int j = 0; j < NB_SPACESHIPS; j++)
            {
                if (this->_spaceships[j])
                {
                    if (x + 1 == W_X)
                    {
                        delete this->_player._projectile[i];
                        this->_player._projectile[i] = NULL;
                        this->_player.decremNbProj();
                        break ;
                    }
                    else if (y == this->_spaceships[j]->getYPosition() && (x == this->_spaceships[j]->getXPosition() || x + 1 == this->_spaceships[j]->getXPosition()))
                    {
                        delete this->_player._projectile[i];
                        this->_player._projectile[i] = NULL;
                        this->_player.decremNbProj();
                        this->_grid[this->_spaceships[j]->getYPosition()][this->_spaceships[j]->getXPosition()] = '*';
                        delete this->_spaceships[j];
                        this->_spaceships[j] = NULL;
                        break ;
                    }
                }
            }
            if (this->_player._projectile[i]) 
            {
                this->_player._projectile[i]->setX(x + 1);
                this->_grid[y][x + 1] = '-';
            }
        }
    }
}

char    World::getCharGrid(int y, int x)
{
    return this->_grid[y][x];
}

void World::printEnemy()
{
    for (int i = 0; i < NB_ALIENS; i++)
    {
        if (this->_aliens[i] && this->_aliens[i]->getXPosition() < W_X)
            this->_grid[this->_aliens[i]->getYPosition()][this->_aliens[i]->getXPosition()] = this->_aliens[i]->getEnemyChar();
        if (!this->_aliens[i])
            this->_aliens[i] = new Alien();
    }
    for (int i = 0; i < NB_SPACESHIPS; i++)
    {
        if (this->_spaceships[i] && this->_spaceships[i]->getXPosition() < W_X)
            this->_grid[this->_spaceships[i]->getYPosition()][this->_spaceships[i]->getXPosition()] = this->_spaceships[i]->getEnemyChar();
        if (!this->_spaceships[i])
            this->_spaceships[i] = new Spaceship();
    }
}

void World::makeTheRules()
{
    int num;
    for (int i = 0; i < W_Y; i++)
        for (int j = 0; j < W_X; j++)
            this->_grid[i][j] = ' ';

    for (int j = 0; j < W_X; j++)
    {
        num = rand() % 10;
        for (int i = W_Y - num; i < W_Y; i++)
            this->_grid[i][j] = '+';
    }

    this->checkEnemyProjectiles(this->_aliens);
    this->checkEnemyProjectiles(this->_spaceships);
    this->checkPlayerProjectiles();
    this->printEnemy();
    for (int i = 0; i < NB_ALIENS; i++)
    {
        if (this->_aliens[i] && this->_aliens[i]->getXPosition() < W_X)
        {
            if (rand() % 250 == 1)
            this->_aliens[i]->fireProjectile(this->_aliens[i]->getYPosition(), this->_aliens[i]->getXPosition() - 1);
        }
    }
    for (int i = 0; i < NB_SPACESHIPS; i++)
    {
        if (this->_spaceships[i] && this->_spaceships[i]->getXPosition() < W_X)
        {
            if (rand() % 250 == 1)
            this->_spaceships[i]->fireProjectile(this->_spaceships[i]->getYPosition(), this->_spaceships[i]->getXPosition() - 1);
        }
    }
}