/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:27:55 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 19:17:46 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <string>
#include "Enemy.hpp"

class Spaceship : public Enemy {
    public :
        Spaceship();
        ~Spaceship();

    protected:

    private:
        Spaceship	&operator=(const Spaceship &);
		Spaceship(const Enemy &);

};

#endif