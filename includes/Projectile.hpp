/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:42:50 by zweng             #+#    #+#             */
/*   Updated: 2019/01/12 14:45:45 by zweng            ###   ########.fr       */
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
