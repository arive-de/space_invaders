/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:12:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 20:12:52 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include <string>

class Projectile {
    public:
		Projectile(int, int);
		Projectile(int, int, int);
		Projectile(const Projectile &);
		Projectile	&operator=(const Projectile &);
        ~Projectile();

		void	move(void);

		int		getSpeed(void) const;
		int		getX(void) const;
		int		getY(void) const;
		void	setX(int);
		void	setY(int);

    protected:
        int posX;
        int posY;
        int dir_speed;

    private:
        Projectile();
};
#endif
