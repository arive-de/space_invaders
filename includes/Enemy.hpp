/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:29:11 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 15:42:17 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "Agent.hpp"

class Enemy : public Agent {
    public :
        Enemy();
        Enemy(std::string name);
        ~Enemy();
        void            takeDamage(size_t damage);

    protected:

    private:
        Enemy	&operator=(const Enemy &);
		Enemy(const Enemy &);

};

#endif