/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:10:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 12:04:20 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

#include <string>
#include "Projectile.hpp"
#include "Agent.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Mesh.hpp"

class World {
    public :
        World(std::string name, size_t health, Projectile *_projectile);
        ~World();
        void            getAgentPosition(Player& player);
        void            getAgentPosition(Enemy& enemy);
        // void            getAgentPosition(Mesh& mesh);
    protected:
        int             **_grid;
        int             playerY;
    private:
        World();
};
#endif