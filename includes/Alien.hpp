/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:35:55 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 15:36:25 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <string>
#include "Enemy.hpp"

class Alien : public Enemy {
    public :
        Alien();
        ~Alien();
        void            takeDamage(size_t damage);

    protected:

    private:
        Alien	&operator=(const Alien &);
		Alien(const Enemy &);

};

#endif