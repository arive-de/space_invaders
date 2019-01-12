/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:10:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 11:26:39 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

#include <string>
#include "Projectile.hpp"
#include "Agent.hpp"

class World {
    public :
        World(std::string name, size_t health, Projectile *_projectile);
        ~World();
    protected:
        std::string     **_grid;
        int             playerY;
        size_t          replay(bool r);
    private:
        World();
};
#endif