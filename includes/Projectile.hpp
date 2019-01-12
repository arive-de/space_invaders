/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:42:50 by zweng             #+#    #+#             */
/*   Updated: 2019/01/12 14:56:26 by fmaury           ###   ########.fr       */
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
        int dir_speed;
        int posX;
        int posY;

    private:
        Projectile();
};
#endif