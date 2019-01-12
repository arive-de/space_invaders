/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:03:05 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 10:08:40 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Projectile.hpp"
#include "Agent.hpp"

class Player : public Agent{
    public :
    protected:
        Player(std::string name, size_t health, Projectile *_projectile);
        ~Player();
        size_t          replay(bool r);
    private:
        Player();

};

#endif