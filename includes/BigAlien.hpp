/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigAlien.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:35:55 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 19:17:48 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGALIEN_HPP
#define BIGALIEN_HPP

#include <string>
#include "Enemy.hpp"

class BigAlien : public Enemy {
    public :
        BigAlien();
        ~BigAlien();

    protected:

    private:
        BigAlien	&operator=(const BigAlien &);
		BigAlien(const Enemy &);

};

#endif