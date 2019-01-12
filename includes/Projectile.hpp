/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:26:45 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 12:08:55 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include <string>
#include "Projectile.hpp"
#include "Agent.hpp"

class Projectile {
    public :
        ~Projectile();
    protected:
        int dir_speed;
        int posX;
        int posY;
    private:
        Projectile();
};
#endif