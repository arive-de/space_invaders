/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigAlien.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:18:14 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 19:31:18 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BigAlien.hpp"

BigAlien::BigAlien() : Enemy("bigAlien", 4, 'B')
{
    this->_x = (rand() % W_X) + W_X;
    this->_y = rand() % W_Y;
    this->_projecSpeed = 2;
}

BigAlien::~BigAlien()
{
 
}