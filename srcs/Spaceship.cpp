/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:27:36 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 15:34:38 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Spaceship.hpp"

Spaceship::Spaceship() : Enemy("Spaceship", 1, '@')
{
    this->_x = (rand() % W_X) + W_X;
    this->_y = rand() % W_Y;
    this->_projecSpeed = 2;
}

Spaceship::~Spaceship()
{
 
}
