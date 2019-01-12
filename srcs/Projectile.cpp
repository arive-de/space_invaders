/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:42:35 by zweng             #+#    #+#             */
/*   Updated: 2019/01/12 13:25:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(int x, int y): posX(x), posY(y)
{
}

Projectile::Projectile(int x, int y, int speed): posX(x), posY(y),
	dir_speed(speed)
{
}

Projectile::Projectile(const Projectile &obj)
{
	*this = obj;
}
	
Projectile	&Projectile::operator=(const Projectile &obj)
{
	this->dir_speed = obj.getSpeed();
	this->posX = obj.getX();
	this->posY = obj.getY();
	return (*this);
}

Projectile::~Projectile(void) {}

int		Projectile::getSpeed(void) const
{
	return (this->dir_speed);
}

int		Projectile::getX(void) const
{
	return (this->posX);
}

int		Projectile::getY(void) const
{
	return (this->posY);
}
