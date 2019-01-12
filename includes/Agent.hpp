/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:56:24 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 10:11:42 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include "Projectile.hpp"

class Agent : public World {
    public :
    protected:
        std::string _name;
        size_t      _health;
        Projectile      *_projectile;
    private:
        Agent();
        ~Agent();

};

#endif