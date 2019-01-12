/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:26:45 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 11:27:31 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

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