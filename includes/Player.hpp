/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:03:05 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:42:28 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Agent.hpp"

class Player : public Agent{

    public :
        Player(std::string name, World &world);
        ~Player();
        void          replay(bool r);
        void            takeDamage(size_t damage);

    private:
        Player();

};

#endif